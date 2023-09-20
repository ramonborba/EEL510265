#include "CShape3d.cpp"

template<typename T>
class CCone : public CShape3d<T> {
public:
    CCone(T a, T b);
    ~CCone();

    T volume();

private:
    
};

template<typename T>
CCone<T>::CCone(T a, T b) : CShape3d<T>(a, b, 0) {
}

template<typename T>
CCone<T>::~CCone() {
}

template<typename T>
T CCone<T>::volume() {
    return 3.14 * this->a * this->a * this->b /3;
}

