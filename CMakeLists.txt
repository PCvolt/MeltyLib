cmake_minimum_required(VERSION 3.19)
project(MeltyLib)

set(CMAKE_CXX_STANDARD 20)

add_library(
        MeltyLib
        src/AddressesAndStuff.h
        src/Action.h
        src/Character.h
        src/Address.h
        src/Character.cpp
        src/MeltyLib.h
)

add_executable(
        MeltyLib_tests
        tests/main.cpp
)
target_include_directories(MeltyLib_tests PRIVATE src)
target_link_libraries(MeltyLib_tests MeltyLib)