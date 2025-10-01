cmake_minimum_required(VERSION 3.29)
project(Programa C)

set(CMAKE_C_STANDARD 11)

add_executable(Programa
        src/main.c
        incl/wificollector_quit.h
        src/wificollector_quit.c
        incl/wificollector_display_all.h
        src/wificollector_display_all.c
        incl/wificollector_collect.h
        src/wificollector_collect.c
        src/wificollector_display.c
        incl/wificollector_display.h)
