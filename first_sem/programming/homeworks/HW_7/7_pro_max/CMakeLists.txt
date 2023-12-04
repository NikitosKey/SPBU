cmake_minimum_required(VERSION 3.26)
project(HW_7_pro_max C)

set(CMAKE_C_STANDARD 23)

add_executable(HW_7_pro_max Task1.c
        main.c
        Task1.h
        Tasks.h
        Task2.c
        Task2.h
        sys.h)
