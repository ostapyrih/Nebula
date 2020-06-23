//
// Created by ostap on 6/23/2020.
//
#pragma once

#include <GL/glew.h>

namespace nebula::graphics::API
{

    class VertexBuffer
    {
    private:
        GLint m_BufferID;
        GLint m_ComponentCount;

    public:
        VertexBuffer(GLfloat *data, GLsizei count, GLuint componentCount);

        void bind() const;
        void unbind() const;

        inline GLuint getComponentCount() const { return m_ComponentCount; }
    };

}