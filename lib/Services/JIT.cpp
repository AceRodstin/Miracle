//
//  JIT.cpp
//  Miracle
//
//  Created by Ace Rodstin on 3/23/23.
//  Copyright © 2023 Ace Rodstin. All rights reserved.
//

#include "Services/JIT.h"

using namespace miracle;

JIT::JIT(
	shared_ptr<ExecutionSession> executionSession,
	shared_ptr<DataLayout> dataLayout,
	shared_ptr<JITTargetMachineBuilder> builder
):
	executionSession(executionSession),
	dataLayout(dataLayout),
	mangle(*executionSession, *dataLayout),
	objectLayer(*executionSession, []() { return std::make_unique<SectionMemoryManager>(); }),
	compileLayer(*executionSession, objectLayer, make_unique<ConcurrentIRCompiler>(*builder)),
	context(make_unique<LLVMContext>()),
	dylib(executionSession->createBareJITDylib("<main>"))
{
	auto globalPrefix = dataLayout->getGlobalPrefix();
	auto process = DynamicLibrarySearchGenerator::GetForCurrentProcess(globalPrefix);
	auto generator = cantFail(move(process));
	dylib.addGenerator(move(generator));
}

JIT::~JIT() {
	auto error = executionSession->endSession();

	if (error) {
		executionSession->reportError(move(error));
	}
}

shared_ptr<JIT> JIT::create() {
    auto executorProcessControl = SelfExecutorProcessControl::Create();

	if (!executorProcessControl) {
		return nullptr;
	}

	auto targetMachineBuilder = JITTargetMachineBuilder::detectHost();

	if (!targetMachineBuilder) {
		return nullptr;
	}

	auto defaultDataLayout = targetMachineBuilder->getDefaultDataLayoutForTarget();

	if (!defaultDataLayout) {
		return nullptr;
	}

	auto executionSession = make_shared<ExecutionSession>(move(*executorProcessControl));
	auto dataLayout = make_shared<DataLayout>(*defaultDataLayout);
	auto builder = make_shared<JITTargetMachineBuilder>(*targetMachineBuilder);

	return make_unique<JIT>(executionSession, dataLayout, builder);
}