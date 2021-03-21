cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(Benchmark)

option(BENCHMARKING "Enable bencharking" OFF)

add_subdirectory(external/Catch2)

add_executable(tests main.cpp Factorial.cpp Fibonacci.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2)

if(BENCHMARKING)
target_compile_definitions(tests PUBLIC CATCH_CONFIG_ENABLE_BENCHMARKING)
endif(BENCHMARKING)

include(CTest)
include(external/Catch2/contrib/Catch.cmake)
catch_discover_tests(tests)

