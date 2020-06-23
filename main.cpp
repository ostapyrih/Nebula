#include "src/graphics/window.h"
#include "src/graphics/shader.h"
#include "src/utils/fileutils.h"
#include "src/math/math.h"

int main() {
    using namespace nebula;
    using namespace graphics;
    using namespace utils;
    using namespace math;

    Window window("Nebula", 960, 540);
    //glClearColor(0.0f, 1.0f, 0.0f, 1.0f);

    GLuint vbo;

    GLfloat vertices[] = {
        0, 0, 0,
        8, 0, 0,
        0, 3 ,0,
        0, 3, 0,
        8, 3, 0,
        8, 0, 0
    };

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);

    mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

    Shader shader("../basic.vert", "../basic.frag");
    shader.enable();
    shader.setUniformMat4("pr_matrix", ortho);
    shader.setUniformMat4("ml_matrix", mat4::translation(vec3(4, 3, 0)));
    shader.setUniform2f("light_pos", vec2(8.0f, 4.5f));
    shader.setUniform4f("colour", vec4(0.2f, 0.5f, 0.8f, 1.0f));


    while (!window.closed()) {
        window.clear();
        glDrawArrays(GL_TRIANGLES, 0, 6);
        window.update();
    }

    return 0;
}