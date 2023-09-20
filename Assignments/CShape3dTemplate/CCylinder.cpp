#include "CShape3d.cpp"

template<typename T>
class CCylinder : public CShape3d<T> {
public:
    CCylinder(T a, T b);
    ~CCylinder();

    T volume();

private:
    
};

template<typename T>
CCylinder<T>::CCylinder(T a, T b) : CShape3d<T>(a, b, 0) {
}

template<typename T>
CCylinder<T>::~CCylinder() {
}

template<typename T>
T CCylinder<T>::volume() {
    return 3.14 * this->a * this->a * this->b;
}

