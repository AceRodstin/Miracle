cmake_minimum_required(VERSION 3.9)
project(Miracle)

set(CMAKE_CXX_STANDARD 20)
set(INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/include")

include_directories(${INCLUDE_DIRECTORIES})

add_executable(Miracle main.cpp)
