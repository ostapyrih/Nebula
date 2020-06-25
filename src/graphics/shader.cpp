//
// Created by ostap on 6/23/2020.
//

#include "shader.h"

using namespace nebula::utils;

namespace nebula::graphics
{

    Shader::Shader(const char *vertPath, const char *fragPath) :
            m_FragPath(fragPath), m_VertPath(vertPath)
    {
        m_ShaderID = load();
    }

    Shader::~Shader()
    {
        glDeleteProgram(m_ShaderID);
    }

    GLuint Shader::load()
    {
        GLuint program = glCreateProgram();
        GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
        GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

        std::string vertSourceString = read_file(m_VertPath);
        std::string fragSourceString = read_file(m_FragPath);

        const char* vertSource = vertSourceString.c_str();
        const char* fragSource = fragSourceString.c_str();

        glShaderSource(vertex, 1, &vertSource, NULL);
        glCompileShader(vertex);

        GLint result;
        glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);
        if (result == GL_FALSE)
        {
            GLint length;
            glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
            std::vector<char> error(length);
            glGetShaderInfoLog(vertex, length, &length, &error[0]);
            std::cout << "Vertex shader ERROR!" << std::endl;
            std::cout << &error[0] << std::endl;
            glDeleteShader(vertex);
            return 0;
        }

        glShaderSource(fragment, 1, &fragSource, NULL);
        glCompileShader(fragment);

        glGetShaderiv(fragment, GL_COMPILE_STATUS, &result);
        if (result == GL_FALSE)
        {
            GLint length;
            glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
            std::vector<char> error(length);
            glGetShaderInfoLog(fragment, length, &length, &error[0]);
            std::cout << "Fragment shader ERROR!" << std::endl;
            std::cout << &error[0] << std::endl;
            glDeleteShader(fragment);
            return 0;
        }

        glAttachShader(program, vertex);
        glAttachShader(program, fragment);

        glLinkProgram(program);
        glValidateProgram(program);

        glDeleteShader(vertex);
        glDeleteShader(fragment);

        return program;
    }

    GLint Shader::getUniformLocation(const GLchar *name) const
    {
        return glGetUniformLocation(m_ShaderID, name);
    }

    void Shader::setUniform1f(const GLchar *name, float value) const
    {
        glUniform1f(getUniformLocation(name), value);
    }

    void Shader::setUniform1i(const GLchar *name, int value) const
    {
        glUniform1i(getUniformLocation(name), value);
    }

    void Shader::setUniform2f(const GLchar *name, const math::vec2 &vector) const
    {
        glUniform2f(getUniformLocation(name), vector.x, vector.y);
    }

    void Shader::setUniform3f(const GLchar *name, const math::vec3 &vector) const
    {
        glUniform3f(getUniformLocation(name), vector.x, vector.y, vector.z);
    }

    void Shader::setUniform4f(const GLchar *name, const math::vec4 &vector) const
    {
        glUniform4f(getUniformLocation(name), vector.x, vector.y, vector.z, vector.w);
    }

    void Shader::setUniformMat4(const GLchar *name, const math::mat4 &matrix) const
    {
        glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, matrix.elements);
    }

    void Shader::enable() const
    {
        glUseProgram(m_ShaderID);
    }

    void Shader::disable() const
    {
        glUseProgram(0);
    }

}