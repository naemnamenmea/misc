cmake_minimum_required(VERSION 3.27)

include(FetchContent)

set(project_name "dummy")
project(${project_name} LANGUAGES C CXX)

# FetchContent_Declare(
#     misc
#     SOURCE_DIR "./"
#     )

FetchContent_Declare(
    misc-base
    GIT_REPOSITORY https://github.com/naemnamenmea/misc-base.git
    GIT_TAG        main
    )
FetchContent_MakeAvailable(misc-base)

if (MSVC)
    # warning level 4
    add_compile_options(/W4 /WX)
else()
    # additional warnings
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_SUPPRESS_REGENERATION OFF)

file(GLOB SOURCE_FILES
    public/*.hpp
    public/*.h
    src/*.cpp
)

add_library(misc STATIC ${SOURCE_FILES})
target_link_libraries(misc PUBLIC misc-base)

target_include_directories(misc PUBLIC public)

add_subdirectory(miscUnitTests)