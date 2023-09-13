#include "CShape3d.cpp"

class CCylinder : public CShape3d {
public:
    CCylinder(float a, float b);
    ~CCylinder();

    float volume();

private:
    
};

CCylinder::CCylinder(float a, float b) : CShape3d(a, b, 0) {
}

CCylinder::~CCylinder() {
}

float CCylinder::volume() {
    return 3.14 * a * a * b;
}

