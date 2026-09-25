cmake_minimum_required(VERSION 3.20)
project(SFML3Auto LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Use the bundled SFML 3.1.0 package in the project instead of downloading it from GitHub.
list(PREPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/SFML-3.1.0")
find_package(SFML 3 REQUIRED COMPONENTS Graphics Audio)

add_executable(SFML3Auto
    main.cpp
    doubao.h
    doubao.cpp)
target_link_libraries(SFML3Auto PRIVATE SFML::Graphics SFML::Audio)
add_compile_options(/utf-8)