cmake_minimum_required(VERSION 3.27)
project(dummy)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

FetchContent_Declare(
    my_testing_tools
    GIT_REPOSITORY https://github.com/naemnamenmea/my-testing-tools.git
    GIT_TAG        main
)
FetchContent_MakeAvailable(my_testing_tools)

file(GLOB SOURCE_FILES
    public/*.hpp
    public/*.h
    src/*.cpp
)

add_library(misc STATIC ${SOURCE_FILES})

target_include_directories(misc PUBLIC public)

add_subdirectory(miscUnitTests)
