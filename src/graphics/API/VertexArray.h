//
// Created by ostap on 6/23/2020.
//
#pragma once

#include <vector>
#include <GL/glew.h>
#include "VertexBuffer.h"

namespace nebula::graphics::API
{
    class VertexArray
    {
    private:
        GLuint m_ArrayID;
        std::vector<VertexBuffer*> m_VertexBuffers;

    public:
        VertexArray();
        ~VertexArray();

        void addBuffer(VertexBuffer* buffer, GLuint index);
        void bind() const;
        void unbind() const;
    };
}