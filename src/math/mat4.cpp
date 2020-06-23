//
// Created by ostap on 6/22/2020.
//

#include "mat4.h"

namespace nebula::math
{

    mat4::mat4()
    {
        memset(elements, 0, 4 * 4 * sizeof(float));

    }

    mat4::mat4(float diagonal)
    {
        memset(elements, 0, 4 * 4 * sizeof(float));
        elements[0 + 0 * 4] = diagonal;
        elements[1 + 1 * 4] = diagonal;
        elements[2 + 2 * 4] = diagonal;
        elements[3 + 3 * 4] = diagonal;
    }

    mat4 mat4::identity()
    {
        return mat4(1.0f);
    }

    mat4 &mat4::multiply(const mat4 &other)
    {
        float data[16];
        for (int row = 0; row < 4; row++)
        {
            for (int col = 0; col < 4; col++)
            {
                float sum = 0.0f;
                for (int e = 0; e < 4; e++)
                {
                    sum += elements[e + row * 4] * other.elements[col + e * 4];
                }
                data[col + row * 4] = sum;
            }
        }
        memcpy(elements, data, 4 * 4 * sizeof(float));
        return *this;
    }

    mat4 operator*(mat4 left, const mat4 &right)
    {
        return left.multiply(right);
    }

    mat4 &mat4::operator*=(const mat4 &other)
    {
        return multiply(other);
    }

    mat4 mat4::orthographic(float left, float right, float bottom, float top, float near, float far)
    {
        mat4 result(1.0f);

        result.elements[0 + 0 * 4] = 2.0f / (right - left);

        result.elements[1 + 1 * 4] = 2.0f / (top - bottom);

        result.elements[2 + 2 * 4] = 2.0f / (near - far);

        result.elements[0 + 3 * 4] = (left + right) / (left - right);
        result.elements[1 + 3 * 4] = (bottom + top) / (bottom - top);
        result.elements[2 + 3 * 4] = (far + near) / (far - near);

        return result;
    }

    mat4 mat4::perspective(float fov, float aspectRation, float near, float far)
    {
        mat4 result(1.0f);

        float q = 1.0f / (float) tan(toRadians(0.5f * fov));
        float a = q / aspectRation;
        float b = (near + far) / (near - far);
        float c = (2.0f * near * far) / (near - far);

        result.elements[0 + 0 * 4] = a;
        result.elements[1 + 1 * 4] = q;
        result.elements[2 + 2 * 4] = b;
        result.elements[3 + 2 * 4] = -1.0f;
        result.elements[2 + 3 * 4] = c;

        return result;
    }

    mat4 mat4::translation(const vec3 &translation)
    {
        mat4 result(1.0f);

        result.elements[0 + 3 * 4] = translation.x;
        result.elements[1 + 3 * 4] = translation.y;
        result.elements[2 + 3 * 4] = translation.z;

        return result;
    }

    mat4 mat4::rotation(float angle, const vec3 &axis)
    {
        mat4 result(1.0f);

        float r = toRadians(angle);
        float c = cos(r);
        float s = sin(r);
        float omc = 1.0f - c;

        float x = axis.x;
        float y = axis.y;
        float z = axis.z;

        result.elements[0 + 0 * 4] = x * omc + c;
        result.elements[1 + 0 * 4] = y * x * omc + z * s;
        result.elements[2 + 0 * 4] = x * z * omc - y * s;

        result.elements[0 + 1 * 4] = x * y * omc - z * s;
        result.elements[1 + 1 * 4] = y * omc + c;
        result.elements[2 + 1 * 4] = y * z * omc + x * s;

        result.elements[0 + 2 * 4] = x * z * omc + y * s;
        result.elements[1 + 2 * 4] = y * z * omc - x * s;
        result.elements[2 + 2 * 4] = z * omc + c;

        return result;
    }

    mat4 mat4::scale(const vec3 &scale)
    {
        mat4 result(1.0f);

        result.elements[0 + 0 * 4] = scale.x;
        result.elements[1 + 1 * 4] = scale.y;
        result.elements[2 + 2 * 4] = scale.z;

        return result;
    }

}
