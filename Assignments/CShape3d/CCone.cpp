#include "CShape3d.cpp"

class CCone : public CShape3d {
public:
    CCone(float a, float b);
    ~CCone();

    float volume();

private:
    
};

CCone::CCone(float a, float b) : CShape3d(a, b, 0) {
}

CCone::~CCone() {
}

float CCone::volume() {
    return 3.14 * a * a * b /3;
}

