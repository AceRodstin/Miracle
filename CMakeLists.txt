cmake_minimum_required(VERSION 3.9)
project(Miracle)

set(CMAKE_CXX_STANDARD 20)

include_directories("${CMAKE_SOURCE_DIR}/include")
add_subdirectory("${CMAKE_SOURCE_DIR}/lib")

add_executable(Miracle main.cpp)

target_link_libraries(Miracle PRIVATE ast models services)
