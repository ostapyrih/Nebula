//
// Created by ostap on 6/21/2020.
//

#include "vec4.h"

namespace nebula::math {

    vec4::vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

    vec4& vec4::Add(const vec4& other) {
        x += other.x;
        y += other.y;
        z += other.z;
        w += other.w;

        return *this;
    }

    vec4& vec4::Subtract(const vec4& other) {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        w -= other.w;

        return *this;
    }

    vec4& vec4::Multiply(const vec4& other) {
        x *= other.x;
        y *= other.y;
        z *= other.z;
        w *= other.w;

        return *this;
    }

    vec4& vec4::Divide(const vec4& other) {
        x /= other.x;
        y /= other.y;
        z /= other.z;
        w /= other.w;

        return *this;
    }

    vec4 operator+(vec4 left, const vec4& right) {
        return left.Add(right);
    }

    vec4 operator-(vec4 left, const vec4& right) {
        return left.Subtract(right);
    }

    vec4 operator*(vec4 left, const vec4& right) {
        return left.Multiply(right);
    }

    vec4 operator/(vec4 left, const vec4& right) {
        return left.Divide(right);
    }

    vec4& vec4::operator+=(const vec4& other) {
        return Add(other);
    }

    vec4& vec4::operator-=(const vec4& other) {
        return Subtract(other);
    }

    vec4& vec4::operator*=(const vec4& other) {
        return Multiply(other);
    }

    vec4& vec4::operator/=(const vec4& other) {
        return Divide(other);
    }

    bool vec4::operator==(const vec4& other) {
        return x == other.x && y == other.y && z == other.z && w == other.w;
    }

    bool vec4::operator!=(const vec4& other) {
        return !(*this == other);
    }

    std::ostream& operator<<(std::ostream& stream, const vec4& vector) {
        stream << "vec4: {" << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w << "}";
        return stream;
    }
}