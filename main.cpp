#include "src/graphics/window.h"
#include "src/math/math.h"

int main() {
    using namespace nebula::graphics;
    using namespace nebula::math;

    Window window("Nebula", 960, 540);
    glClearColor(0.0f, 1.0f, 0.0f, 1.0f);

    while (!window.closed()) {
        window.clear();
        glBegin(GL_TRIANGLES);
        glVertex2d(0.0f, 0.5f);
        glVertex2d(-0.5f, -0.5f);
        glVertex2d(0.5f, -0.5f);
        glEnd();
        window.update();
    }

    return 0;
}