cmake_minimum_required(VERSION 3.7.2)
project(TPE-ENSICAEN-2018 C)

set(CMAKE_C_STANDARD 11)

include_directories(include CCollections/include)

add_executable(helloWolrd src/main/helloWorld.c)