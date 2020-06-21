#pragma once

#include <iostream>

namespace nebula::math{

	struct vec2 {
		
		float x, y;

		vec2();
		vec2(const float& x, const float& y);

		vec2& Add(const vec2& other);
		vec2& Subtract(const vec2& other);
		vec2& Multiply(const vec2& other);
		vec2& Divide(const vec2& other);

        friend vec2 operator+(vec2 left, const vec2& right);
        friend vec2 operator-(vec2 left, const vec2& right);
        friend vec2 operator*(vec2 left, const vec2& right);
        friend vec2 operator/(vec2 left, const vec2& right);

        bool operator==(const vec2& other) const;
        bool operator!=(const vec2& other) const;

        vec2& operator+=(const vec2& other);
        vec2& operator-=(const vec2& other);
        vec2& operator*=(const vec2& other);
        vec2& operator/=(const vec2& other);

        friend std::ostream& operator<<(std::ostream& stream, const vec2& vector);
	};

}