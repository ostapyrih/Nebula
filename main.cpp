#include "src/graphics/window.h"
#include "src/graphics/shader.h"
#include "src/graphics/API/VertexBuffer.h"
#include "src/graphics/API/IndexBuffer.h"
#include "src/graphics/API/VertexArray.h"
#include "src/graphics/Renderable2D.h"
#include "src/graphics/Renderer2D.h"
#include "src/graphics/SimpleRenderer2D.h"

int main() {
    using namespace nebula;
    using namespace graphics;
    using namespace utils;
    using namespace math;
    using namespace API;

    Window window("Nebula", 960, 540);

    SimpleRenderer2D renderer;

    mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

    Shader shader("../basic.vert", "../basic.frag");
    shader.enable();
    shader.setUniformMat4("pr_matrix", ortho);
    Renderable2D sprite(vec3(5, 5, 0), vec2(4, 4), vec4(0,1,0,1), shader);
    Renderable2D sprite2(vec3(1, 1, 0), vec2(2, 2), vec4(1,1,0,1), shader);


    while (!window.closed()) {
        window.clear();
        double x, y;
        window.getCursorPosition(x, y);
        shader.setUniform2f("light_pos", vec2((float)(x * 16.0f / 960.0f), (float)(9.0f - y * 9.0f / 540.0f)));
        renderer.submit(&sprite);
        renderer.submit(&sprite2);
        renderer.flush();
        window.update();
    }

    return 0;
}