cmake_minimum_required(VERSION 3.10)
project(SteganographyImage)

set(CMAKE_CXX_STANDARD 11)

add_executable(ManualReader main.cpp bmpFile.cpp bmpFile.h)