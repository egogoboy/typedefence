cmake_minimum_required(VERSION 3.24)
project(typedefence LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(${CMAKE_SOURCE_DIR}/src)

find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)

add_executable(game
    src/main.cpp
    src/core/Game.cpp
    src/entities/Entity.cpp
    src/entities/WordEntity.cpp
    src/render/Renderer.cpp
)

target_link_libraries(game
    PRIVATE
        SFML::Graphics
        SFML::Window
        SFML::System
)

add_custom_command(TARGET game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:game>/assets
)
