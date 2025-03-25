cmake_minimum_required(VERSION 3.30)
project(exo1 C)

set(CMAKE_C_STANDARD 11)

add_executable(exo1 main.c
        my_strncpy.h
        my_strncpy.c)

# Find and include CUnit
include_directories(/usr/local/Cellar/cunit/2.1-3/include)
link_directories(/usr/local/Cellar/cunit/2.1-3/lib)

add_executable(test_my_strncpy test_my_strncpy.c
        my_strncpy.h
        my_strncpy.c)
target_link_libraries(test_my_strncpy cunit)
