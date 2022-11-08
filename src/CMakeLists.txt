cmake_minimum_required(VERSION 3.1...3.23)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(Ityl.Character.Manager
        VERSION 1.0
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(CMAKE_CXX_FLAGS " ${CMAKE_CXX_FLAGS} --coverage")

#set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)

if(CMAKE_VERSION VERSION_LESS 3.7.0)
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt6 REQUIRED COMPONENTS Widgets Qml Quick QuickControls2)

if(CMAKE_VERSION VERSION_LESS 3.12.0)
    add_definitions(-DQT_DEPRECATED_WARNINGS)
else()
    add_compile_definitions(QT_DEPRECATED_WARNINGS)
endif()

add_subdirectory(Ityl.DataModel)
add_subdirectory(Ityl.JsonReader)
add_subdirectory(Ityl.Business)
add_subdirectory(Ityl.Character.Manager)

# TODO

add_subdirectory(Ityl.Core)
add_subdirectory(Ityl.Json)
add_subdirectory(Ityl.UI)
add_subdirectory(UnitTests)

