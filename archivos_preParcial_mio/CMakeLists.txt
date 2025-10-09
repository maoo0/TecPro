cmake_minimum_required(VERSION 4.0)
project(archivos_preParcial_mio)

set(CMAKE_CXX_STANDARD 20)

add_executable(archivos_preParcial_mio main.cpp
        src/Utils.h
        src/FuncionesAuxiliares.cpp
        src/FuncionesAuxiliares.h
)
