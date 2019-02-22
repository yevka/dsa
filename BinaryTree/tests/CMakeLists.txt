cmake_minimum_required(VERSION 3.7.2)

# Define variables
set(TEST_RUNNER test_runner)
file(GLOB_RECURSE TEST_SRC_LIST "*.cxx")

# Configure test target
add_executable(${TEST_RUNNER} ${TEST_SRC_LIST} ${SRC_LIST})

# Run tests
add_test(
        NAME ${TEST_RUNNER}
        COMMAND ./${TEST_RUNNER} -d yes
)
