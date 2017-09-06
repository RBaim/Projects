cmake_minimum_required(VERSION 3.7)

project(Server)

set(CMAKE_CXX_STANDARD 11)

link_libraries(ws2_32 wsock32)

set(SOURCE_FILES main.cpp)

add_executable(Server ${SOURCE_FILES})