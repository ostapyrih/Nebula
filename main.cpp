#include "src/graphics/Window.h"
#include "src/graphics/Shader.h"
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

    Mat4 ortho = Mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

    Shader shader("../basic.vert", "../basic.frag");
    shader.enable();
    shader.setUniformMat4("pr_matrix", ortho);
    Renderable2D sprite(Vec3(5, 5, 0), Vec2(4, 4), Vec4(0, 1, 0, 1), shader);
    Renderable2D sprite2(Vec3(1, 1, 0), Vec2(2, 2), Vec4(1, 1, 0, 1), shader);


    while (!window.closed()) {
        window.clear();
        double x, y;
        window.getCursorPosition(x, y);
        shader.setUniform2f("light_pos", Vec2((float)(x * 16.0f / 960.0f), (float)(9.0f - y * 9.0f / 540.0f)));
        renderer.submit(&sprite);
        renderer.submit(&sprite2);
        renderer.flush();
        window.update();
    }

    return 0;
}