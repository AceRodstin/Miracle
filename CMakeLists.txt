cmake_minimum_required(VERSION 3.9)
project(Miracle)

find_package(LLVM)
include(AddLLVM)

set(CMAKE_CXX_STANDARD 20)
set(GOOGLETEST_VERSION 1.13)
list(APPEND CMAKE_MODULE_PATH ${LLVM_CMAKE_DIR})

separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})
add_definitions(${LLVM_DEFINITIONS_LIST})

llvm_map_components_to_libnames(
	llvm
	Support
	Core
	native
	ExecutionEngine
	OrcJIT
)

include_directories(${LLVM_INCLUDE_DIRS} "${CMAKE_SOURCE_DIR}/include")
add_subdirectory("${CMAKE_SOURCE_DIR}/lib")
add_subdirectory("${CMAKE_SOURCE_DIR}/googletest")
add_subdirectory("${CMAKE_SOURCE_DIR}/test")

add_llvm_executable(Miracle main.cpp)

target_link_libraries(Miracle PRIVATE ${llvm} ast models services)
