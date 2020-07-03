//
// Created by ostap on 6/21/2020.
//
#pragma once

#include <iostream>

namespace nebula::math
{

    struct Vec4
    {
        float x, y, z, w;

        Vec4() = default;

        Vec4(float x, float y, float z, float w);

        Vec4 &Add(const Vec4 &other);

        Vec4 &Subtract(const Vec4 &other);

        Vec4 &Multiply(const Vec4 &other);

        Vec4 &Divide(const Vec4 &other);

        friend Vec4 operator+(Vec4 left, const Vec4 &right);

        friend Vec4 operator-(Vec4 left, const Vec4 &right);

        friend Vec4 operator*(Vec4 left, const Vec4 &right);

        friend Vec4 operator/(Vec4 left, const Vec4 &right);

        bool operator==(const Vec4 &other);

        bool operator!=(const Vec4 &other);

        Vec4 &operator+=(const Vec4 &other);

        Vec4 &operator-=(const Vec4 &other);

        Vec4 &operator*=(const Vec4 &other);

        Vec4 &operator/=(const Vec4 &other);

        friend std::ostream &operator<<(std::ostream &stream, const Vec4 &vector);
    };
}