cmake_minimum_required(VERSION 4.0)
project(prueba4)

set(CMAKE_CXX_STANDARD 20)

add_executable(prueba4 main.cpp
        Bibliotecas/FuncionesAuxiliares.cpp
        Bibliotecas/FuncionesAuxiliares.hpp
        Bibliotecas/Utils.hpp)
