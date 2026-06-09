cmake_minimum_required(VERSION 3.20)

project(walkie_talkie)

set(CMAKE_CXX_STANDARD 17)

add_executable(walkie_talkie main.cpp "player.h" "scene.h" "worldscene.h"  "worldscene.cpp" "player.cpp")

add_subdirectory(C:/raylib/raylib raylib_build)

target_link_libraries(walkie_talkie PRIVATE raylib)