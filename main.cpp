//
//  main.cpp
//  Miracle
//
//  Created by Ace Rodstin on 3/22/23.
//  Copyright © 2023 Ace Rodstin. All rights reserved.
//

#include "llvm/Support/TargetSelect.h"
#include "Services/JIT.h"

using namespace miracle;

// определить target machine
// создать JIT
// сгенерировать IR
// выполнить расчет
// вывести результат

int main() {
	InitializeNativeTarget();
	auto jit = JIT::create();

	return 0;
}