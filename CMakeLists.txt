cmake_minimum_required(VERSION ${CMAKE_VERSION})
project(GAMEENGINE)

include_directories(
	src
)

add_library(GameEngine
src/GameEngine/Core.cpp
src/GameEngine/Core.h
src/GameEngine/Entity.h
src/GameEngine/Entity.cpp
src/GameEngine/Component.cpp
src/GameEngine/Component.h
)

add_executable(demo
src/demo/main.cpp
)
target_link_libraries(demo GameEngine)
