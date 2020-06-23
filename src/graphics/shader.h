//
// Created by ostap on 6/23/2020.
//
#pragma once

#include "../utils/fileutils.h"
#include "../math/math.h"
#include <vector>
#include <iostream>
#include <GL/glew.h>

namespace nebula::graphics {

    class Shader {
    private:
        GLuint m_ShaderID;
        const char *m_VertPath, *m_FragPath;

    public:
        Shader(const char *vertPath, const char *fragPath);

        ~Shader();

        GLint getUniformLocation(const GLchar *name);

        void setUniform1f(const GLchar* name, float value);
        void setUniform1i(const GLchar* name, int value);
        void setUniform2f(const GLchar* name, const math::vec2& vector);
        void setUniform3f(const GLchar* name, const math::vec3& vector);
        void setUniform4f(const GLchar* name, const math::vec4& vector);
        void setUniformMat4(const GLchar* name, const math::mat4& matrix);

        void enable() const;

        void disable() const;

    private:
        GLuint load();

    };

}