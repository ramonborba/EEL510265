#pragma once

template<typename T>
class CShape3d {
public:
    CShape3d(T a, T b, T c);

    virtual T volume() = 0;

protected:
    T a;
    T b;
    T c;

};

template<typename T>
CShape3d<T>::CShape3d(T a, T b, T c) : a(a), b(b), c(c) {
}
