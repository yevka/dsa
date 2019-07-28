cmake_minimum_required(VERSION 3.2)

# ISO 8601 scheme: YYYY-MM-DD
project(dsa VERSION 2019.07.28 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE} "DEBUG")

if ( CMAKE_CXX_COMPILER_ID MATCHES "Clang" )
  add_compile_options(
    -Weverything
    -fcolor-diagnostics
    -Wno-c++98-compat
    -Wno-padded
    -Wno-missing-variable-declarations
    -Wno-unused-macros
)
endif()

# run swap:     ctest -R swap
# run all test: ctest
enable_testing()

add_executable(test_swap test_swap.cpp)
add_test(NAME swap COMMAND test_swap)

add_executable(test_counting_sort test_counting_sort.cpp)
add_test(NAME counting_sort COMMAND test_counting_sort)
