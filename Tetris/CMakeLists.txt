cmake_minimum_required(VERSION 3.5)

project(Tetris LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)
find_package(Qt6 COMPONENTS OpenGLWidgets REQUIRED)

add_executable(Tetris
    src/main.cpp
    src/Player.h
    src/Player.cpp
    src/MainWindow.cpp
    src/MainWindow.h
    src/GameRenderer.cpp
    src/GameRenderer.h
)

# file(GLOB Tetris_SRC
#     "src/*.h"
#     "src/*.cpp"
# )
#
# add_executable(Tetris ${Tetris_SRC})

target_link_libraries(Tetris PRIVATE Qt6::Widgets)
target_link_libraries(Tetris PRIVATE Qt6::OpenGLWidgets)
