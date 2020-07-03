cmake_minimum_required(VERSION 3.16)
project(nebula)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES main.cpp src/graphics/Window.cpp src/graphics/Window.h src/math/Vec2.cpp src/math/Vec2.h src/math/Vec3.cpp src/math/Vec3.h src/math/Vec4.cpp src/math/Vec4.h src/math/Math.h src/math/Mat4.cpp src/math/Mat4.h src/utils/Fileutils.h src/graphics/Shader.cpp src/graphics/Shader.h src/graphics/API/VertexBuffer.cpp src/graphics/API/VertexBuffer.h src/graphics/API/IndexBuffer.cpp src/graphics/API/IndexBuffer.h src/graphics/API/VertexArray.cpp src/graphics/API/VertexArray.h src/graphics/Renderable2D.h src/graphics/Renderer2D.h src/graphics/SimpleRenderer2D.cpp src/graphics/SimpleRenderer2D.h src/graphics/BatchRenderer2D.cpp src/graphics/BatchRenderer2D.h)

include_directories(${PROJECT_SOURCE_DIR}/libs/GLFW/include)
include_directories(${PROJECT_SOURCE_DIR}/libs/GLEW/include)

link_directories(${PROJECT_SOURCE_DIR}/libs/GLFW/lib)
link_directories(${PROJECT_SOURCE_DIR}/libs/GLEW/lib)

add_executable(nebula ${SOURCE_FILES} "src/graphics/Sprite.h" "src/graphics/Sprite.cpp" "src/graphics/StaticSprite.h" "src/graphics/StaticSprite.cpp")

target_link_libraries(nebula glfw3 opengl32 glew32s)

add_definitions(-DGLEW_STATIC)