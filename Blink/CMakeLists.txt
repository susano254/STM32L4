cmake_minimum_required(VERSION 3.23)
project(Blink C)

set(CMAKE_C_STANDARD 99)
include_directories(include)

add_executable(Blink src/Blink.c include/stm32l432kc.h)
