cmake_minimum_required(VERSION 3.8)
project(Lab1_2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp MeshLoader.h AneuMeshLoader.h Util.h Algorithm.h MeshLoader.cpp AneuMeshLoader.cpp Exc.h Vector.h VectorIterator.h)
add_executable(Lab1_2 ${SOURCE_FILES})