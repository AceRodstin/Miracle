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
#include "llvm/ExecutionEngine/Orc/IRCompileLayer.h"
#include "llvm/ExecutionEngine/Orc/JITTargetMachineBuilder.h"
#include "llvm/ExecutionEngine/Orc/RTDyldObjectLinkingLayer.h"
#include "llvm/ExecutionEngine/SectionMemoryManager.h"
#include "llvm/IR/DataLayout.h"
#include "llvm/IR/LLVMContext.h"
#include <memory>

using namespace std;
using namespace llvm;
using namespace orc;

namespace miracle {
	class JIT {
	public:
	JIT(shared_ptr<ExecutionSession> executionSession, shared_ptr<DataLayout> dataLayout, shared_ptr<JITTargetMachineBuilder> builder);
	~JIT();
	
	static shared_ptr<JIT> create();

	private:
		shared_ptr<ExecutionSession> executionSession;

		shared_ptr<DataLayout> dataLayout;
		MangleAndInterner mangle;

		RTDyldObjectLinkingLayer objectLayer;
		IRCompileLayer compileLayer;

		ThreadSafeContext context;
		JITDylib& dylib;
	};
}


#endif
