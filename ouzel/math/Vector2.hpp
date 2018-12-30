// Copyright 2015-2018 Elviss Strazdins. All rights reserved.

#ifndef OUZEL_MATH_VECTOR2_HPP
#define OUZEL_MATH_VECTOR2_HPP

#include <cstddef>
#include <cmath>

namespace ouzel
{
    class Vector3;
    class Vector4;

    class Vector2 final
    {
    public:
        float v[2]{0.0F, 0.0F};

        Vector2()
        {
        }

        Vector2(float x, float y):
            v{x, y}
        {
        }

        Vector2(const Vector2& copy):
            v{copy.v[0], copy.v[1]}
        {
        }

        explicit Vector2(const Vector3& vec);

        Vector2& operator=(const Vector3& vec);

        explicit Vector2(const Vector4& vec);

        Vector2& operator=(const Vector4& vec);

        inline float& x() { return v[0]; }
        inline float& y() { return v[1]; }

        inline float x() const { return v[0]; }
        inline float y() const { return v[1]; }

        inline bool isZero() const
        {
            return v[0] == 0.0F && v[1] == 0.0F;
        }

        inline bool isOne() const
        {
            return v[0] == 1.0F && v[1] == 1.0F;
        }

        static float angle(const Vector2& v1, const Vector2& v2);

        void add(const Vector2& vec)
        {
            v[0] += vec.v[0];
            v[1] += vec.v[1];
        }

        static void add(const Vector2& v1, const Vector2& v2, Vector2& dst);

        void clamp(const Vector2& min, const Vector2& max);

        static void clamp(const Vector2& vec, const Vector2& min, const Vector2& max, Vector2& dst);

        float distance(const Vector2& vec) const;

        float distanceSquared(const Vector2& vec) const
        {
            float dx = vec.v[0] - v[0];
            float dy = vec.v[1] - v[1];
            return dx * dx + dy * dy;
        }

        float dot(const Vector2& vec) const
        {
            return v[0] * vec.v[0] + v[1] * vec.v[1];
        }

        static float dot(const Vector2& v1, const Vector2& v2)
        {
            return v1.v[0] * v2.v[0] + v1.v[1] * v2.v[1];
        }

        float length() const;

        float lengthSquared() const
        {
            return v[0] * v[0] + v[1] * v[1];
        }

        void negate()
        {
            v[0] = -v[0];
            v[1] = -v[1];
        }

        void normalize();

        void scale(float scalar)
        {
            v[0] *= scalar;
            v[1] *= scalar;
        }

        void scale(const Vector2& scale)
        {
            v[0] *= scale.v[0];
            v[1] *= scale.v[1];
        }

        void rotate(float angle);
        void rotate(const Vector2& point, float angle);

        void set(float newX, float newY)
        {
            v[0] = newX;
            v[1] = newY;
        }

        void subtract(const Vector2& vec)
        {
            v[0] -= vec.v[0];
            v[1] -= vec.v[1];
        }

        static void subtract(const Vector2& v1, const Vector2& v2, Vector2& dst)
        {
            dst.v[0] = v1.v[0] - v2.v[0];
            dst.v[1] = v1.v[1] - v2.v[1];
        }

        void smooth(const Vector2& target, float elapsedTime, float responseTime);

        float getMin() const;
        float getMax() const;

        inline const Vector2 operator+(const Vector2& vec) const
        {
            return Vector2(v[0] + vec.v[0], v[1] + vec.v[1]);
        }

        inline Vector2& operator+=(const Vector2& vec)
        {
            v[0] += vec.v[0];
            v[1] += vec.v[1];
            return *this;
        }

        inline const Vector2 operator-(const Vector2& vec) const
        {
            return Vector2(v[0] - vec.v[0], v[1] - vec.v[1]);
        }

        inline Vector2& operator-=(const Vector2& vec)
        {
            v[0] -= vec.v[0];
            v[1] -= vec.v[1];
            return *this;
        }

        inline const Vector2 operator-() const
        {
            return Vector2(-v[0], -v[1]);
        }

        inline const Vector2 operator*(float scalar) const
        {
            return Vector2(v[0] * scalar, v[1] * scalar);
        }

        inline Vector2& operator*=(float scalar)
        {
            v[0] *= scalar;
            v[1] *= scalar;
            return *this;
        }

        inline const Vector2 operator/(float scalar) const
        {
            return Vector2(v[0] / scalar, v[1] / scalar);
        }

        inline Vector2& operator/=(float scalar)
        {
            v[0] /= scalar;
            v[1] /= scalar;
            return *this;
        }

        inline bool operator<(const Vector2& vec) const
        {
            if (v[0] == vec.v[0])
                return v[1] < vec.v[1];

            return v[0] < vec.v[0];
        }

        inline bool operator==(const Vector2& vec) const
        {
            return v[0] == vec.v[0] && v[1] == vec.v[1];
        }

        inline bool operator!=(const Vector2& vec) const
        {
            return v[0] != vec.v[0] || v[1] != vec.v[1];
        }

        inline float getAngle() const
        {
            return atan2f(v[1], v[0]);
        };
    };

    inline const Vector2 operator*(float scalar, const Vector2& vec)
    {
        return Vector2(vec.v[0] * scalar, vec.v[1] * scalar);
    }
}

#endif // OUZEL_MATH_VECTOR2_HPP
