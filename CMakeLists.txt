cmake_minimum_required(VERSION 3.16)
project(CSA_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(CSA_1 Sources/main.cpp
                     Sources/container.cpp
                     Sources/language.cpp
                     Sources/functional.cpp
                     Sources/objectoriented.cpp
                     Sources/procedural.cpp
                     Headers/container.h
                     Headers/language.h
                     Headers/functional.h
                     Headers/objectoriented.h
                     Headers/procedural.h)
