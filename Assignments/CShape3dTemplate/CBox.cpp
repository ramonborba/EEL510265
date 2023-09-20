#include "CShape3d.cpp"

template<typename T>
class CBox : public CShape3d<T> {
public:
    CBox(T a, T b, T c);
    ~CBox();

    T volume();
};

template<typename T>
CBox<T>::CBox(T a, T b, T c) : CShape3d<T>(a, b, c) {
}

template<typename T>
CBox<T>::~CBox() {
}

template<typename T>
T CBox<T>::volume() 
{
    return this->a * this->b * this->c;
}
