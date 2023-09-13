#include "CShape3d.cpp"

class CBox : public CShape3d {
public:
    CBox(float a, float b, float c);
    ~CBox();

    float volume();
};

CBox::CBox(float a, float b, float c) : CShape3d(a, b, c) {
}

CBox::~CBox() {
}

float CBox::volume() 
{
    return a * b * c;
}
