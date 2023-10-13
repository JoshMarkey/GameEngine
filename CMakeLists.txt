cmake_minimum_required(VERSION ${CMAKE_VERSION})
project(GAMEENGINE)

include_directories(
 src
 contrib/windows-cl-amd64/include
)
link_directories(
 ${PROJECT_SOURCE_DIR}/contrib/windows-cl-amd64/lib
)

add_library(Graphics
src/Graphics/Model.cpp
src/Graphics/Model.h
src/Graphics/rend.h
src/Graphics/RenderTexture.cpp
src/Graphics/RenderTexture.h
src/Graphics/Shader.cpp
src/Graphics/Shader.h
src/Graphics/Texture.cpp
src/Graphics/Texture.h
src/Graphics/Vao.cpp
src/Graphics/Vao.h
src/Graphics/Vbo.cpp
src/Graphics/Vbo.h
src/Graphics/stb_image.h
src/Graphics/bugl.h
src/Graphics/Camera.h
src/Graphics/Camera.cpp
)

target_link_libraries(Graphics glew32 opengl32)



add_library(GameEngine
src/GameEngine/Core.cpp
src/GameEngine/Core.h
src/GameEngine/Entity.h
src/GameEngine/Entity.cpp
src/GameEngine/Component.cpp
src/GameEngine/Component.h
src/GameEngine/Transform.h
src/GameEngine/Transform.cpp
src/GameEngine/TriangleRenderer.cpp
src/GameEngine/TriangleRenderer.h
)

add_executable(demo
src/demo/main.cpp
)
target_link_libraries(demo GameEngine Graphics SDL2)
