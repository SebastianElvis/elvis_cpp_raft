cmake_minimum_required(VERSION 3.10)
project(elvis_cpp_raft)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_subdirectory(log)
add_subdirectory(message)
add_subdirectory(network)
add_subdirectory(state)

add_executable(elvis_cpp_raft main.cpp)

target_link_libraries(elvis_cpp_raft Log Message Network State)