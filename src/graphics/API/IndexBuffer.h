//
// Created by ostap on 6/23/2020.
//
#pragma once

#include <GL/glew.h>

namespace nebula::graphics::API
{
    class IndexBuffer
    {
    private:
        GLuint m_BufferID;
        GLint m_Count;

    public:
        IndexBuffer(GLushort *data, GLsizei count);

        void bind() const;
        void unbind() const;

        inline GLuint getCount() const { return m_Count; }
    };
}