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
src/GameEngine/NativeWindow.h
src/GameEngine/NativeWindow.cpp
src/GameEngine/Enviroment.cpp
src/GameEngine/Enviroment.h
src/GameEngine/Texture.cpp
src/GameEngine/Texture.h
src/GameEngine/Model.cpp
src/GameEngine/Model.h
src/GameEngine/Resource.cpp
src/GameEngine/Resource.h
src/GameEngine/Resources.cpp
src/GameEngine/Resources.h
src/GameEngine/Shader.cpp
src/GameEngine/Shader.h
src/GameEngine/Input.cpp
src/GameEngine/Input.h
src/GameEngine/Cat.cpp
src/GameEngine/Cat.h
src/GameEngine/ModelRenderer.cpp
src/GameEngine/ModelRenderer.h
src/GameEngine/BoxCollider.cpp
src/GameEngine/BoxCollider.h
src/GameEngine/Collider.cpp
src/GameEngine/Collider.h
src/GameEngine/RigidBody.cpp
src/GameEngine/RigidBody.h
)

add_executable(demo
src/demo/main.cpp
src/demo/Map.cpp
src/demo/map.h
)
target_link_libraries(demo GameEngine Graphics SDL2)
