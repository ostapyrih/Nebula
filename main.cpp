#include "src/graphics/Window.h"
#include "src/graphics/Shader.h"
#include "src/graphics/API/VertexBuffer.h"
#include "src/graphics/API/IndexBuffer.h"
#include "src/graphics/API/VertexArray.h"
#include "src/graphics/Renderable2D.h"
#include "src/graphics/Renderer2D.h"
#include "src/graphics/SimpleRenderer2D.h"
#include "src/graphics/Sprite.h"
#include "src/graphics/BatchRenderer2D.h"

#include <chrono>

int main() {
    using namespace nebula;
    using namespace graphics;
    using namespace utils;
    using namespace math;
    using namespace API;

    Window window("Nebula", 960, 540);

    BatchRenderer2D batch;

    Mat4 ortho = Mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

    Shader shader("../../../basic.vert", "../../../basic.frag");
    shader.enable();
    shader.setUniformMat4("pr_matrix", ortho);

    Sprite sprite(5, 5, 4, 4, Vec4(0, 1, 0, 1));
    Sprite sprite2(7, 1, 2, 3, Vec4(1, 1, 0, 1));

    while (!window.closed()) {
        window.clear();
        double x, y;
        window.getCursorPosition(x, y);
        shader.setUniform2f("light_pos", Vec2((float)(x * 16.0f / 960.0f), (float)(9.0f - y * 9.0f / 540.0f)));
        batch.begin();
        batch.submit(&sprite);
        batch.submit(&sprite2);
        batch.end();
        batch.flush();
        window.update();
    }

    return 0;
}