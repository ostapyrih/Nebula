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
        GLuint m_BufferID;
        GLint m_ComponentCount;

    public:
        VertexBuffer(GLfloat *data, GLsizei count, GLuint componentCount);
        ~VertexBuffer();
        void bind() const;
        void unbind() const;

        inline GLuint getComponentCount() const { return m_ComponentCount; }
    };

}