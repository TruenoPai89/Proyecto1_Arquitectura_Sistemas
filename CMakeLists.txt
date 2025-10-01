cmake_minimum_required(VERSION 3.29)
project(Programa C)

set(CMAKE_C_STANDARD 11)

add_executable(Programa
    main.c
        Funciones/Wificollector_Collect/wificollector_collect.c
        Funciones/Wificollector_Collect/wificollector_collect.h
        Funciones/Wificollector_Quit/wificollector_quit.c
        Funciones/Wificollector_Quit/wificollector_quit.h
        Funciones/Wificollector_Display/wificollector_display.h
        Funciones/Wificollector_Display/wificollector_display.c
        Funciones/Wificollector_Display_All/wificollector_display_all.h
        Funciones/Wificollector_Display_All/wificollector_display_all.c)
