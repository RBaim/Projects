cmake_minimum_required(VERSION 3.8)
project(SeaBattle)

set(CMAKE_CXX_STANDARD 11)

link_libraries(ws2_32 wsock32)

set(SOURCE_FILES main.cpp Table.h Table.cpp Cursor.h Cursor.cpp Ships.h Ships.cpp MyTcpIP.h MyTcpIP.cpp)
add_executable(SeaBattle ${SOURCE_FILES})