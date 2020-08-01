#pragma once

#include "../Renderable2D.h"
#include "../../math/Math.h"
#include "../Renderer2D.h"

namespace nebula::graphics::layers
{
	using namespace math;

	class Group : public Renderable2D
	{
	private:
		std::vector<Renderable2D*> m_Renderables;
		Mat4 m_TransformationMatrix;
	public:
		Group(const Mat4 transform);
		void submit(Renderer2D* renderer) const override;
		void add(Renderable2D* renderable);
	};
}