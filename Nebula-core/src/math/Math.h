//
// Created by ostap on 6/22/2020.
//
#pragma once

#include "Vec2.h"
#include "Vec3.h"
#include "Vec4.h"
#include "Mat4.h"

namespace nebula::math
{
	inline float toRadians(float degrees)
	{
		return degrees * (M_PI / 180.0f);
	}
}