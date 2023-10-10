cmake_minimum_required(VERSION 3.25)
project(untitled C)

set(CMAKE_C_STANDARD 23)

add_executable(untitled main.c ABP.c ABP.h ABP.h aleatoria_ABP.h aleatoria_LSE.c aleatoria_LSE.h LSE.c options.h ordenada_ABP.c ordenada_ABP.h ordenada_LSE.c ordenada_LSE.h utils.c utils.h aleatoria_ABP.c)
