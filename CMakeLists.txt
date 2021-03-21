cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(Benchmark)

add_subdirectory(external/Catch2)

add_executable(Benchmark main.cpp Factorial.cpp Fibonacci.cpp)
target_link_libraries(Benchmark PRIVATE Catch2::Catch2)

# include(CTest)
# include(external/Catch2/contrib/Catch.cmake)
# catch_discover_tests(tests)