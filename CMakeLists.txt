cmake_minimum_required(VERSION 3.27)

include(FetchContent)

FetchContent_Declare(
    misc
    SOURCE_DIR "./"
    )

project(dummy)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB SOURCE_FILES
    public/*.hpp
    public/*.h
    src/*.cpp
)

add_library(misc STATIC ${SOURCE_FILES})

target_include_directories(misc PUBLIC public)

add_subdirectory(miscUnitTests)