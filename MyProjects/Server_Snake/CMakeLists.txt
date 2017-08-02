cmake_minimum_required(VERSION 3.8)
project(Server_Snake)

set(CMAKE_CXX_STANDARD 11)

link_libraries(ws2_32 wsock32)

set(SOURCE_FILES main.cpp)
add_executable(Server_Snake ${SOURCE_FILES})