cmake_minimum_required(VERSION 3.20)
project(TSK)

set(CMAKE_CXX_STANDARD 26)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS")

add_executable(TSK
        src/main.cpp
        src/core.cpp
        lib/core.h
        src/vehicle.cpp
        lib/vehicle.h
        src/dopplerRadar.cpp
        lib/dopplerRadar.h
        src/mainFrame.cpp
        lib/mainFrame.h
        lib/mainFrame.h
        src/simController.cpp
        lib/simController.h
        lib/simController.h
        src/eventHandlers.cpp
        lib/eventHandlers.h
        src/eventHandlers.cpp)

find_package(wxWidgets CONFIG REQUIRED)

target_link_libraries(TSK PRIVATE wx::core wx::base)

set_target_properties(TSK PROPERTIES LINK_FLAGS "/ENTRY:WinMainCRTStartup")
