cmake_minimum_required(VERSION 3.9)
project(Miracle)

set(CMAKE_CXX_STANDARD 20)
set(GOOGLETEST_VERSION 1.13)

include_directories("${CMAKE_SOURCE_DIR}/include")
add_subdirectory("${CMAKE_SOURCE_DIR}/lib")
add_subdirectory("${CMAKE_SOURCE_DIR}/googletest")
add_subdirectory("${CMAKE_SOURCE_DIR}/test")

add_executable(Miracle main.cpp)

target_link_libraries(Miracle PRIVATE ast models services)
