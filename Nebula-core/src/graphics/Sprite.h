#pragma once

#include "Renderable2D.h"

namespace nebula::graphics
{

	class Sprite : public Renderable2D
	{
	private:

	public:
		Sprite(float x, float y, float width, float height, const Vec4& color);
	};

}