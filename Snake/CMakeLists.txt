cmake_minimum_required(VERSION 3.7)
project(Snake)

set(CMAKE_CXX_STANDARD 11)

link_libraries(ws2_32 wsock32)

set(SOURCE_FILES main.cpp Player.h Cursor.h Cursor.cpp MyTcpIP.h MyTcpIP.cpp)
add_executable(Snake ${SOURCE_FILES})