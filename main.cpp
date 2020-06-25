#include "src/graphics/window.h"
#include "src/graphics/shader.h"
#include "src/utils/fileutils.h"
#include "src/math/math.h"
#include "src/graphics/API/VertexBuffer.h"
#include "src/graphics/API/IndexBuffer.h"
#include "src/graphics/API/VertexArray.h"

int main() {
    using namespace nebula;
    using namespace graphics;
    using namespace utils;
    using namespace math;
    using namespace API;

    Window window("Nebula", 960, 540);

    GLfloat vertices[] = {
            0, 0, 0,
            0, 3 ,0,
            8, 3, 0,
            8, 0, 0
    };

    GLushort indices[] =
    {
        0, 1, 2,
        2, 3, 0
    };

    GLfloat colorA[] =
    {
        1, 0, 1, 1,
        1, 0, 1, 1,
        1, 0, 1, 1,
        1, 0, 1, 1
    };

    GLfloat colorB[] =
    {
        0.2f, 0.5f, 0.8f, 1.0f,
        0.2f, 0.5f, 0.8f, 1.0f,
        0.2f, 0.5f, 0.8f, 1.0f,
        0.2f, 0.5f, 0.8f, 1.0f
    };

    VertexArray sprite1, sprite2;
    IndexBuffer ibo(indices, 6);

    sprite1.addBuffer(new VertexBuffer(vertices, 4 * 3, 3), 0);
    sprite1.addBuffer(new VertexBuffer(colorA, 4 * 4, 4), 1);
    sprite2.addBuffer(new VertexBuffer(vertices, 4 * 3, 3), 0);
    sprite2.addBuffer(new VertexBuffer(colorB, 4 * 4, 4), 1);

    mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

    Shader shader("../basic.vert", "../basic.frag");
    shader.enable();
    shader.setUniformMat4("pr_matrix", ortho);
    shader.setUniformMat4("ml_matrix", mat4::translation(vec3(4, 3, 0)));
    shader.setUniform2f("light_pos", vec2(4.0f, 1.5f));
    shader.setUniform4f("colour", vec4(0.2f, 0.5f, 0.8f, 1.0f));


    while (!window.closed()) {
        window.clear();
        double x, y;
        window.getCursorPosition(x, y);
        shader.setUniform2f("light_pos", vec2((float)(x * 16.0f / 960.0f), (float)(9.0f - y * 9.0f / 540.0f)));
        sprite1.bind();
        ibo.bind();
        shader.setUniformMat4("ml_matrix", mat4::translation(vec3(4, 3, 0)));
        glDrawElements(GL_TRIANGLES, ibo.getCount(), GL_UNSIGNED_SHORT, nullptr);
        ibo.bind();
        sprite1.unbind();

        sprite2.bind();
        ibo.bind();
        shader.setUniformMat4("ml_matrix", mat4::translation(vec3(0, 0, 0)));
        glDrawElements(GL_TRIANGLES, ibo.getCount(), GL_UNSIGNED_SHORT, nullptr);
        ibo.bind();
        sprite2.unbind();
        window.update();
    }

    return 0;
}