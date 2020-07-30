#include "src/graphics/Window.h"
#include "src/graphics/Shader.h"
#include "src/graphics/Sprite.h"
#include "src/graphics/BatchRenderer2D.h"
#include "src/utils/Timer.h"

int main() {
    using namespace nebula;
    using namespace graphics;
    using namespace utils;
    using namespace math;

    Window window("Nebula", 960, 540);

    BatchRenderer2D batch;

    Mat4 ortho = Mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

    Shader shader("basic.vert", "basic.frag");
    shader.enable();
    shader.setUniformMat4("pr_matrix", ortho);

    Sprite sprite(5, 5, 4, 4, Vec4(1, 1, 1, 1));
    Sprite sprite2(7, 1, 2, 3, Vec4(1, 1, 0, 1));

    Timer timer;
    unsigned int fps = 0;

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
        
        fps++;
        if (timer.elapsed() > 1.0f) {
            printf("%d FPS\n", fps);
            fps = 0;
            timer.reset();
        }
    }

    return 0;
}