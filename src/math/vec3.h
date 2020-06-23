//
// Created by ostap on 6/21/2020.
//
#pragma once

#include <iostream>

namespace nebula::math
{

    struct vec3
    {

        float x, y, z;

        vec3();

        vec3(float x, float y, float z);

        vec3 &Add(const vec3 &other);

        vec3 &Subtract(const vec3 &other);

        vec3 &Multiply(const vec3 &other);

        vec3 &Divide(const vec3 &other);

        friend vec3 operator+(vec3 left, const vec3 &right);

        friend vec3 operator-(vec3 left, const vec3 &right);

        friend vec3 operator*(vec3 left, const vec3 &right);

        friend vec3 operator/(vec3 left, const vec3 &right);

        bool operator==(const vec3 &other) const;

        bool operator!=(const vec3 &other) const;

        vec3 &operator+=(const vec3 &other);

        vec3 &operator-=(const vec3 &other);

        vec3 &operator*=(const vec3 &other);

        vec3 &operator/=(const vec3 &other);

        friend std::ostream &operator<<(std::ostream &stream, const vec3 &vector);
    };

}