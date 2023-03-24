//
//  JIT.cpp
//  Miracle
//
//  Created by Ace Rodstin on 3/23/23.
//  Copyright © 2023 Ace Rodstin. All rights reserved.
//

#include "Services/JIT.h"
#include "Tools.h"

using namespace miracle;

JIT::JIT(
	unique_ptr<ExecutionSession> executionSession,
	JITTargetMachineBuilder builder,
	DataLayout dataLayout
):
	executionSession(move(executionSession)),
	dataLayout(move(dataLayout)),
	mangle(*(this->executionSession), this->dataLayout),
	objectLayer(*(this->executionSession), []() { return make_unique<SectionMemoryManager>(); }),
	compileLayer(*(this->executionSession), objectLayer, make_unique<ConcurrentIRCompiler>(move(builder))),
	dylib(this->executionSession->createBareJITDylib("<main>"))
{
	auto globalPrefix = dataLayout.getGlobalPrefix();
	auto process = DynamicLibrarySearchGenerator::GetForCurrentProcess(globalPrefix);
	auto generator = cantFail(move(process));
	dylib.addGenerator(move(generator));
}

JIT::~JIT() {
	tools::validate(executionSession->endSession());
}

unique_ptr<JIT> JIT::create() {
	auto executorProcessControl = tools::validate(SelfExecutorProcessControl::Create());
	auto executionSession = make_unique<ExecutionSession>(move(executorProcessControl));
	auto targetMachineBuilder = tools::validate(JITTargetMachineBuilder::detectHost());
	auto dataLayout = tools::validate(targetMachineBuilder.getDefaultDataLayoutForTarget());
	return make_unique<JIT>(move(executionSession), move(targetMachineBuilder), move(dataLayout));
}

void JIT::addModule(ThreadSafeModule module) {
	auto resourceTracker = dylib.getDefaultResourceTracker();
	tools::validate(compileLayer.add(resourceTracker, move(module)));
}

JITEvaluatedSymbol JIT::lookup(string symbolName) {
	ArrayRef<JITDylib *> searchModule = &dylib;
	SymbolStringPtr symbol = mangle(symbolName);
	return tools::validate(executionSession->lookup(searchModule, symbol));
}

void JIT::remove(string symbolName) {
	SymbolStringPtr symbol = mangle(symbolName);
	SymbolNameSet symbols { symbol };
	tools::validate(dylib.remove(symbols));
}

const DataLayout& JIT::getDataLayout() const {
	return dataLayout;
}