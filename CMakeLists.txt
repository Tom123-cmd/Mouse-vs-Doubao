cmake_minimum_required(VERSION 3.20)
project(MouseVsDoubao LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Use the bundled SFML 3.1.0 package in the project instead of downloading it from GitHub.
list(PREPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/SFML-3.1.0")
find_package(SFML 3 REQUIRED COMPONENTS Graphics Audio)

add_executable(MouseVsDoubao
    main.cpp
    doubao.h
    doubao.cpp
    cannonball.h
    cannonball.cpp)
target_link_libraries(MouseVsDoubao PRIVATE SFML::Graphics SFML::Audio)
add_compile_options(/utf-8)