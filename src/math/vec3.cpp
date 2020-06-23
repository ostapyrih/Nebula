//
// Created by ostap on 6/21/2020.
//

#include "vec3.h"
namespace nebula::math {

    vec3::vec3() : x(0.0f), y(0.0f), z(0.0f) {}

    vec3::vec3(float x, float y, float z) : x(x), y(y), z(z) {}

    vec3& vec3::Add(const vec3& other) {
        x += other.x;
        y += other.y;
        z += other.z;

        return *this;
    }

    vec3& vec3::Subtract(const vec3& other) {
        x -= other.x;
        y -= other.y;
        z -= other.z;

        return *this;
    }

    vec3& vec3::Multiply(const vec3& other) {
        x *= other.x;
        y *= other.y;
        z *= other.z;

        return *this;
    }

    vec3& vec3::Divide(const vec3& other) {
        x /= other.x;
        y /= other.y;
        z /= other.z;

        return *this;
    }

    vec3 operator+(vec3 left, const vec3& right) {
        return left.Add(right);
    }

    vec3 operator-(vec3 left, const vec3& right) {
        return left.Subtract(right);
    }

    vec3 operator*(vec3 left, const vec3& right) {
        return left.Multiply(right);
    }

    vec3 operator/(vec3 left, const vec3& right) {
        return left.Divide(right);
    }

    vec3& vec3::operator+=(const vec3& other) {
        return Add(other);
    }

    vec3& vec3::operator-=(const vec3& other) {
        return Subtract(other);
    }

    vec3& vec3::operator*=(const vec3& other) {
        return Multiply(other);
    }

    vec3& vec3::operator/=(const vec3& other) {
        return Divide(other);
    }

    bool vec3::operator==(const vec3& other) const {
        return x == other.x && y == other.y && z == other.z;
    }

    bool vec3::operator!=(const vec3& other) const {
        return !(*this == other);
    }

    std::ostream& operator<<(std::ostream& stream, const vec3& vector) {
        stream << "vec3: {" << vector.x << ", " << vector.y << ", " << vector.z << "}";
        return stream;
    }
}