//
// Created by ostap on 6/22/2020.
//
#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include "math.h"

namespace nebula::math {

    struct mat4 {

        struct {
            float elements[16];
            vec4 columns[4];
        };

        mat4();
        mat4(float diagonal);

        static mat4 identity();
        mat4& multiply(const mat4& other);

        static mat4 orthographic(float left, float right, float bottom, float top, float near, float far);
        static mat4 perspective(float fov, float aspectRation, float near, float far);

        static mat4 translation(const vec3& translation);
        static mat4 rotation(float angle, const vec3& axis);
        static mat4 scale(const vec3& scale);

        friend mat4 operator*(mat4 left, const mat4& right);
        mat4& operator*=(const mat4& other);
    };

}