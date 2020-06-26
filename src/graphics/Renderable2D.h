//
// Created by ostap on 6/25/2020.
//
#pragma once

#include "../math/Math.h"
#include "API/VertexArray.h"
#include "API/IndexBuffer.h"
#include "Shader.h"

namespace nebula::graphics
{
    using namespace API;
    using namespace math;

    class Renderable2D
    {
    protected:
        Vec3 m_Position;
        Vec2 m_Size;
        Vec4 m_Color;

        VertexArray *m_VertexArray;
        IndexBuffer *m_IndexBuffer;
        Shader &m_Shader;

    public:
        Renderable2D(Vec3 position, Vec2 size, Vec4 color, Shader &shader) :
            m_Position(position), m_Size(size), m_Color(color), m_Shader(shader)
        {
            m_VertexArray = new VertexArray();
            GLfloat vertices[] =
            {
                0, 0, 0,
                0, size.y, 0,
                size.x, size.y, 0,
                size.x, 0, 0
            };

            GLfloat colors[] =
            {
                color.x, color.y, color.z, color.w,
                color.x, color.y, color.z, color.w,
                color.x, color.y, color.z, color.w,
                color.x, color.y, color.z, color.w
            };

            m_VertexArray->addBuffer(new VertexBuffer(vertices, 4 * 3, 3), 0);
            m_VertexArray->addBuffer(new VertexBuffer(colors, 4 * 4, 4), 1);

            GLushort indices[] = { 0, 1, 2, 2, 3, 0};
            m_IndexBuffer = new IndexBuffer(indices, 6);
        }

        virtual ~Renderable2D()
        {
            delete m_VertexArray;
            delete m_IndexBuffer;
        }

        inline const VertexArray* getVAO() const { return m_VertexArray; }
        inline const IndexBuffer* getIBO() const { return m_IndexBuffer; }
        inline const Shader& getShader() const { return m_Shader; }

        inline const Vec3& getPosition() const { return m_Position; }
        inline const Vec2& getSize() const { return m_Size; }
        inline const Vec4& getColor() const { return m_Color; }
    };

}