cmake_minimum_required(VERSION 3.20)
project(TSK)

set(CMAKE_CXX_STANDARD 26)

add_executable(TSK
        src/main.cpp
        src/core.cpp
        lib/core.h
        src/vehicle.cpp
        lib/vehicle.h
        src/dopplerRadar.cpp
        lib/dopplerRadar.h)

find_package(wxWidgets CONFIG REQUIRED)
target_link_libraries(TSK PRIVATE wx::core wx::base)