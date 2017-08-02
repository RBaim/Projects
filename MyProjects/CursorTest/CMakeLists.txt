cmake_minimum_required(VERSION 3.8)
project(CursorTest)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Cursor.h Cursor.cpp)
add_executable(CursorTest ${SOURCE_FILES})