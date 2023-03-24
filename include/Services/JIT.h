//
//  JIT.h
//  Miracle
//
//  Created by Ace Rodstin on 3/23/23.
//  Copyright © 2023 Ace Rodstin. All rights reserved.
//

#ifndef JIT_HEADER_FILE
#define JIT_HEADER_FILE

#include "llvm/ExecutionEngine/JITSymbol.h"
#include "llvm/ExecutionEngine/Orc/CompileUtils.h"
#include "llvm/ExecutionEngine/Orc/Core.h"
#include "llvm/ExecutionEngine/Orc/ExecutionUtils.h"
#include "llvm/ExecutionEngine/Orc/ExecutorProcessControl.h"
#include "llvm/ExecutionEngine/Orc/IRCompileLayer.h"
#include "llvm/ExecutionEngine/Orc/JITTargetMachineBuilder.h"
#include "llvm/ExecutionEngine/Orc/RTDyldObjectLinkingLayer.h"
#include "llvm/ExecutionEngine/SectionMemoryManager.h"
#include "llvm/IR/DataLayout.h"
#include "llvm/IR/LLVMContext.h"
#include <memory>
#include <string>

using namespace std;
using namespace llvm;
using namespace orc;

namespace miracle {
	class JIT {
	public:
		JIT(unique_ptr<ExecutionSession> executionSession, JITTargetMachineBuilder builder, DataLayout dataLayout);
		~JIT();

		static unique_ptr<JIT> create();
		void addModule(ThreadSafeModule module);
		JITEvaluatedSymbol lookup(string symbolName);
		const DataLayout& getDataLayout() const;

	private:
		unique_ptr<ExecutionSession> executionSession;

		DataLayout dataLayout;
		MangleAndInterner mangle;

		RTDyldObjectLinkingLayer objectLayer;
		IRCompileLayer compileLayer;

		JITDylib& dylib;
	};
}


#endif