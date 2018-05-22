cmake_minimum_required(VERSION 3.0)
project(trecia_uzduotis)

set(CMAKE_CXX_STANDARD 17)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

include_directories(includes)

add_executable(trecia_uzduotis
        main.cpp
        includes/studentas.cpp
        includes/studentas.h
        includes/fileStreams.cpp
        includes/randPazymys.cpp
        includes/failuGeneravimas.cpp
        includes/strategijos.cpp)

add_executable(testai
        tests/galutinisBalas.cpp
        tests/kintamieji.cpp
        includes/studentas.cpp
        includes/studentas.h
        includes/fileStreams.cpp
        includes/randPazymys.cpp
        includes/failuGeneravimas.cpp
        includes/strategijos.cpp tests/kintamieji.cpp)
