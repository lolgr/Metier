set(CMAKE_CONFIGURATION_TYPES Debug Release)
project(Metier)
cmake_minimum_required(VERSION 3.22)
set_property(GLOBAL PROPERTY OS_FOLDERS ON)

set(SOURCES
    Metier_app.cpp
    Metier_Ticker.cpp
    Metier_Chart.cpp
    Metier_TCallback.cpp
    Metier_Indicators.cpp
    Metier_Series.cpp
    Metier_app.h
    Metier_Ticker.h
    Metier_Chart.h
    Metier_TCallback.h
    Metier_Indicators.h
    Metier_Series.h
    )

include_directories(${CMAKE_SOURCE_DIR}/third_party/curl-8.1.2/include/curl)
include_directories(${CMAKE_SOURCE_DIR}/third_party/json)
add_executable(Metier ${SOURCES})
target_link_libraries(Metier curl)
