//
//  Tools.h
//  Miracle
//
//  Created by Ace Rodstin on 3/24/23.
//  Copyright © 2023 Ace Rodstin. All rights reserved.
//

#ifndef TOOLS_HEADER_FILE
#define TOOLS_HEADER_FILE


#include "llvm/Support/Error.h"
#include "llvm/Support/TargetSelect.h"

using namespace llvm;

namespace tools {
	static ExitOnError validate;

	static void initializeHost() {
		InitializeNativeTarget();
		InitializeNativeTargetAsmPrinter();
		InitializeNativeTargetAsmParser();
	}
}


#endif