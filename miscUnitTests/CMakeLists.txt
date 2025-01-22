cmake_minimum_required(VERSION 3.27)

include(FetchContent)

set(project_name "dummy")
project(${project_name} LANGUAGES C CXX)

# FetchContent_Declare(
#     misc
#     SOURCE_DIR "../"
# )

FetchContent_Declare(
    my_testing_tools
    GIT_REPOSITORY https://github.com/naemnamenmea/my-testing-tools.git
    GIT_TAG        main
)
FetchContent_MakeAvailable(my_testing_tools)

add_executable(miscUnitTests)

file(GLOB TEST_FILES tests/*.cpp)
file(GLOB SOURCE_FILES *.cpp *.hpp)

target_include_directories(miscUnitTests PRIVATE .)
target_sources(miscUnitTests PUBLIC ${SOURCE_FILES} ${TEST_FILES})

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(miscUnitTests PUBLIC misc)
target_link_libraries(miscUnitTests PUBLIC my_testing_tools)

# get_target_property(parent_folder misc FOLDER)
