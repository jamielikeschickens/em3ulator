cmake_minimum_required(VERSION 2.8.9)
project(em3ulator)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall")

set(SOURCE_DIR "./src")
set(TESTS_SRC_DIR "./src/tests")

set(EM3ULATOR_SRCS
    ${SOURCE_DIR}/Register.cpp
    ${SOURCE_DIR}/Instruction.cpp
    ${SOURCE_DIR}/FlexibleOperand.cpp
)

set(TESTS_SRC_DIR "./src/tests")

set(TEST_SRCS
    ${TESTS_SRC_DIR}/FlexibleOperand.t.cpp
)


include_directories(${SOURCE_DIR})

# em3ulatorlib
add_library(em3ulatorlib ${EM3ULATOR_SRCS})

# em3ulator executable
add_executable(em3ulator ${SOURCE_DIR}/main.cpp)
target_link_libraries(em3ulator em3ulatorlib)

# gtestlib
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(gtest ${TEST_SRCS} ${EM3ULATOR_SRCS})
target_link_libraries(gtest ${GTEST_BOTH_LIBRARIES}) 
add_test(gtest gtest)
