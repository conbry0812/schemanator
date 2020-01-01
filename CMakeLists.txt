cmake_minimum_required(VERSION 3.15)
project(schemanator C)

set(CMAKE_C_STANDARD 99)

add_executable(schemanator main.c scanner.c scanner.h universalFunctions.h)