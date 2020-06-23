//
// Created by ostap on 6/22/2020.
//
#pragma once

#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
#include "mat4.h"

namespace nebula::math
{
    inline float toRadians(float degrees)
    {
        return degrees * (M_PI / 180.0f);
    }
}