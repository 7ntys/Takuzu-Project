cmake_minimum_required(VERSION 3.22.1)
project(Takuzu_Project C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Takuzu_Project
        function.c
        function.h
        main.c)
