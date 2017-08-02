cmake_minimum_required(VERSION 3.8)
project(Listen_Snake)

set(CMAKE_CXX_STANDARD 11)

link_libraries(ws2_32 wsock32)

set(SOURCE_FILES main.cpp Cursor.h Cursor.cpp MyTcpIP.h MyTcpIP.cpp)
add_executable(Listen_Snake ${SOURCE_FILES})