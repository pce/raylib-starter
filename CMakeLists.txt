cmake_minimum_required(VERSION 3.0)
project(Game)

# https://github.com/raysan5/raylib/wiki/Working-on-macOS

set (CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} game.cpp)

if (NOT TARGET raylib)
  find_package(raylib 2.5.0 REQUIRED)
endif()

target_link_libraries(${PROJECT_NAME} raylib)
