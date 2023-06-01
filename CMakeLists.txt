file(GLOB SOURCE_FILES
    public/*.hpp
    public/*.h
    src/*.cpp
)

add_library(misc STATIC ${SOURCE_FILES})

target_include_directories(misc PUBLIC public)

add_subdirectory(miscUnitTests)
