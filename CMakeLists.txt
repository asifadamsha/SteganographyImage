cmake_minimum_required(VERSION 3.10)
project(qdbmpBitmap C)

set(CMAKE_C_STANDARD 99)

add_executable(qdbmpBitmap main.c qdbmp.c qdbmp.h)