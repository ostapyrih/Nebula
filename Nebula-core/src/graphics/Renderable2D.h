//
// Created by ostap on 6/25/2020.
//
#pragma once

#include "../math/Math.h"
#include "buffers/VertexArray.h"
#include "buffers/IndexBuffer.h"
#include "Shader.h"
#include "Renderer2D.h"

namespace nebula::graphics
{

	using namespace buffers;
	using namespace math;

	struct VertexData
	{
		Vec3 vertex;
		unsigned int color;
	};

	class Renderable2D
	{
	protected:
		Vec3 m_Position;
		Vec2 m_Size;
		Vec4 m_Color;
	protected:
		Renderable2D() { }
	public:
		Renderable2D(Vec3 position, Vec2 size, Vec4 color) :
			m_Position(position), m_Size(size), m_Color(color)
		{
		}

		virtual ~Renderable2D() {}

		virtual void submit(Renderer2D* renderer) const
		{
			renderer->submit(this);
		}

		inline const Vec3& getPosition() const { return m_Position; }
		inline const Vec2& getSize() const { return m_Size; }
		inline const Vec4& getColor() const { return m_Color; }
	};

}