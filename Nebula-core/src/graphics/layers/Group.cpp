#include "Group.h"

namespace nebula::graphics::layers
{

	Group::Group(const Mat4 transform)
		: m_TransformationMatrix(transform)
	{

	}

	void Group::submit(Renderer2D* renderer) const
	{
		renderer->push(m_TransformationMatrix);
		for (const Renderable2D* renderable : m_Renderables)
		{
			renderable->submit(renderer);	
		}
		renderer->pop();
	}

	void Group::add(Renderable2D* renderable)
	{
		m_Renderables.push_back(renderable);
	}

}