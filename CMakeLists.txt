cmake_minimum_required(VERSION ${CMAKE_VERSION})
project(GAMEENGINE)

include_directories(
	src
)


add_executable(demo
src/demo/Player.h
src/demo/main.cpp
)

add_library(GameEngine
src/GameEngine/Core.cpp
src/GameEngine/Core.h
)