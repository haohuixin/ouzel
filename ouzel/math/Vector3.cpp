// Copyright 2015-2018 Elviss Strazdins. All rights reserved.

#include "Vector3.hpp"
#include "Vector2.hpp"
#include "Vector4.hpp"
#include "Color.hpp"

namespace ouzel
{
    template<class T>
    Vector3<T>::Vector3(const Vector4<T>& vec):
        v{vec.v[0], vec.v[1], vec.v[2]}
    {
    }

    template<class T>
    Vector3<T>& Vector3<T>::operator=(const Vector4<T>& vec)
    {
        v[0] = vec.v[0];
        v[1] = vec.v[1];
        v[2] = vec.v[2];

        return *this;
    }

    template<class T>
    Vector3<T>::Vector3(Color color)
    {
        v[0] = color.normR();
        v[1] = color.normG();
        v[2] = color.normB();
    }

    template<class T>
    Vector3<T>& Vector3<T>::operator=(Color color)
    {
        v[0] = color.normR();
        v[1] = color.normG();
        v[2] = color.normB();

        return *this;
    }

    template class Vector3<float>;
}
