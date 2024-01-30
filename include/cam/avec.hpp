#pragma once

#include <iostream>

namespace cam {
    namespace detail {
        struct Vector4 {
            Vector4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}
            Vector4(float v) : x(v), y(v), z(v), w(v) {}
            Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

            union {
                float x;
                float r;
            };
            union {
                float y;
                float g;
            };
            union {
                float z;
                float b;
            };
            union {
                float w;
                float a;
            };

            Vector4 operator*(const Vector4 &other) const {
                Vector4 res;
                res.x = x * other.x;
                res.y = y * other.y;
                res.z = z * other.z;
                res.w = w * other.w;
                return res;
            }

            Vector4 operator/(const Vector4 &other) const {
                Vector4 res;
                res.x = x / other.x;
                res.y = y / other.y;
                res.z = z / other.z;
                res.w = w / other.w;
                return res;
            }

            Vector4 operator+(const Vector4 &other) const {
                Vector4 res;
                res.x = x + other.x;
                res.y = y + other.y;
                res.z = z + other.z;
                res.w = w + other.w;
                return res;
            }

            Vector4 operator-(const Vector4 &other) const {
                Vector4 res;
                res.x = x - other.x;
                res.y = y - other.y;
                res.z = z - other.z;
                res.w = w - other.w;
                return res;
            }

            Vector4 operator*(const float &other) const {
                Vector4 res;
                res.x = x * other;
                res.y = y * other;
                res.z = z * other;
                res.w = w * other;
                return res;
            }

            Vector4 operator/(const float &other) const {
                Vector4 res;
                res.x = x / other;
                res.y = y / other;
                res.z = z / other;
                res.w = w / other;
                return res;
            }

            Vector4 operator+(const float &other) const {
                Vector4 res;
                res.x = x + other;
                res.y = y + other;
                res.z = z + other;
                res.w = w + other;
                return res;
            }

            Vector4 operator-(const float &other) const {
                Vector4 res;
                res.x = x - other;
                res.y = y - other;
                res.z = z - other;
                res.w = w - other;
                return res;
            }

            friend std::ostream& operator<<(std::ostream&, const Vector4&);
        };

        std::ostream& operator<<(std::ostream &os, const Vector4 &vec) {
            os << "vec4: {" << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w << "}";
            return os;
        }
    };

    template<typename T>
    T lerp(const T &a, const T &b, const float &fac) {
        if (fac < 0.0f || fac > 1.0f) {
            std::cerr << "Lerp factor outside range (0-1)" << '\n';
            return a;
        }

        T res;
        res = (b - a) * fac + a;
        return res;
    }

    using vec4 = detail::Vector4;
};