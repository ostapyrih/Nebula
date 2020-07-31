#pragma once

#include "../Renderer2D.h"
#include "../Renderable2D.h"
#include "../../math/Math.h"

namespace nebula::graphics::layers
{

	using namespace math;

	class Layer
	{

	protected:
		Renderer2D* m_Renderer;
		std::vector<Renderable2D*> m_Renderables;
		Shader* m_Shader;
		Mat4 m_ProjectionMatrix;

	public:
		virtual ~Layer();
		virtual void add(Renderable2D* renderable);
		void render();

	protected:
		Layer(Renderer2D* renderer, Shader* shader, Mat4 projectionMatrix);

	};

}