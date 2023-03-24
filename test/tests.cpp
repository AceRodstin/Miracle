#include "gtest/gtest.h"
#include "Tools.h"

using namespace testing;
using namespace llvm;

int main() {
	tools::initializeHost();
	InitGoogleTest();
	return RUN_ALL_TESTS();
}