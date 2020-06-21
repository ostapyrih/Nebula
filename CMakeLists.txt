cmake_minimum_required(VERSION 3.16)
project(nebula)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES main.cpp src/graphics/window.cpp src/graphics/window.h src/math/vec2.cpp src/math/vec2.h src/math/vec3.cpp src/math/vec3.h src/math/vec4.cpp src/math/vec4.h)

include_directories(${PROJECT_SOURCE_DIR}/libs/GLFW/include)
include_directories(${PROJECT_SOURCE_DIR}/libs/GLEW/include)

link_directories(${PROJECT_SOURCE_DIR}/libs/GLFW/lib)
link_directories(${PROJECT_SOURCE_DIR}/libs/GLEW/lib)

add_executable(nebula ${SOURCE_FILES})

target_link_libraries(nebula glfw3 opengl32 glew32s)

add_definitions(-DGLEW_STATIC)