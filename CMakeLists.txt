cmake_minimum_required(VERSION 3.26)
project(locadora C)

set(CMAKE_C_STANDARD 11)

add_executable(locadora main.c
        locadora.h
        locadora.c)
