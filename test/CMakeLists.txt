set(TEST_SOURCES "CalculatorTests.cpp")

add_executable(Tests "tests.cpp")

target_link_libraries(Tests PRIVATE gtest ast models services)
target_sources(Tests PRIVATE ${TEST_SOURCES})