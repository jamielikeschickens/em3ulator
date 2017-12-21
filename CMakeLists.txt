cmake_minimum_required(VERSION 2.8.9)
project (em3ulator)
add_executable(em3ulator main.cpp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall")

set(SOURCE_DIR, "./src")

include_directories(${SOURCE_DIR})
