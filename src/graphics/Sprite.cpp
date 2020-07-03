#include "Sprite.h"

namespace nebula::graphics
{
	Sprite::Sprite(float x, float y, float width, float height, const Vec4& color) 
		: Renderable2D(Vec3(x, y, 0), Vec2(width, height), color)
	{
		
	}
}