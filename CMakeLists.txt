cmake_minimum_required(VERSION 4.0)
project(77933281 C)

set(CMAKE_C_STANDARD 11)

include_directories(filter)

add_executable(77933281
        filter/bmp.h
        filter/filter.c
        filter/helpers.c
        filter/helpers.h
        recover/recover.c
        volume/volume.c
        cash.c
        hello.c
        inheritance.c
        mario.c
        plurality.c
        readability.c
        runoff.c
        scrabble.c
        substitution.c)
