cmake_minimum_required(VERSION 3.19)
project(MeltyLib)

set(CMAKE_CXX_STANDARD 20)

include_directories(include/directx)

add_library(
        MeltyLib
        src/Action.h
        src/Address.h
        src/AddressesAndStuff.h
        src/Character.h src/Character.cpp
        src/ComboInfo.h src/ComboInfo.cpp
        src/MeltyLib.h
        src/Stage.h
        src/Menu.h src/Menu.cpp
        src/DrawUtils.h src/DrawUtils.cpp src/Vector2.h src/Font.cpp src/Font.h)

add_executable(
        MeltyLib_tests
        tests/main.cpp)

target_include_directories(MeltyLib_tests PRIVATE src)
target_link_libraries(MeltyLib_tests MeltyLib)