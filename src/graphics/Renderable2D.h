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

    struct VertexData{
        Vec3 vertex;
        Vec4 color;
    };

    class Renderable2D
    {
    protected:
        Vec3 m_Position;
        Vec2 m_Size;
        Vec4 m_Color;

    public:
        Renderable2D(Vec3 position, Vec2 size, Vec4 color) :
            m_Position(position), m_Size(size), m_Color(color) {}

        virtual ~Renderable2D() {}

        inline const Vec3& getPosition() const { return m_Position; }
        inline const Vec2& getSize() const { return m_Size; }
        inline const Vec4& getColor() const { return m_Color; }
    };

}