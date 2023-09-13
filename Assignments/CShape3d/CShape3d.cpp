#pragma once

class CShape3d {
public:
    CShape3d(float a, float b, float c);

    virtual float volume() = 0;

protected:
    float a;
    float b;
    float c;

};

CShape3d::CShape3d(float a, float b, float c) : a(a), b(b), c(c) {
}
