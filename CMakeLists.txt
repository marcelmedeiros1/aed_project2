cmake_minimum_required(VERSION 3.10)

project(aed_project2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
    src/Airline.cpp
    src/Airport.cpp
    src/App.cpp
    src/FlightNetwork.cpp
    src/main.cpp
)

include_directories(inc)

add_executable(aed_project2 ${SOURCE_FILES})
