cmake_minimum_required(VERSION 3.10.2)
project(EXPRESSAOPREINPOS C)

set(CMAKE_C_STANDARD 11)

include_directories(
        "src/"
)

add_executable(ExpressaoPreInPos
        src/ExpressaoPreInPos.c
        src/define.h
        src/core/Convert.h
        src/core/Convert.c
        src/core/FuncoesPilha.c
        src/core/FuncoesPilha.h
        src/core/Saidas.c
        src/core/Saidas.h
        src/core/ValidaExpressao.c
        src/core/ValidaExpressao.h)

