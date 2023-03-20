cmake_minimum_required(VERSION 3.9)
project(Chapter1)

find_package(LLVM)

list(APPEND CMAKE_MODULE_PATH ${LLVM_CMAKE_DIR})
include(AddLLVM)

set(CMAKE_CXX_STANDARD 20)
set(INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/include")

include_directories(${LLVM_INCLUDE_DIRS} ${INCLUDE_DIRECTORIES})
separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})
add_definitions(${LLVM_DEFINITIONS_LIST})

add_llvm_executable(Chapter1 main.cpp)

llvm_map_components_to_libnames(
	LLVM
	Support
	Core
)

target_link_libraries(Chapter1 ${LLVM})
