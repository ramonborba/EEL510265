#include <iostream>

#define ARRAY_SIZE 10

void addVector(int* a, int* b, int* c, int size);

void printVector(int* vector, int size);

int main(void)
{
    int x[ARRAY_SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int y[ARRAY_SIZE] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
    int z[ARRAY_SIZE] = { 0 };

    addVector(x, y, z, ARRAY_SIZE);

    std::cout << "x: "; printVector(x, ARRAY_SIZE); std::cout << "\n";
    std::cout << "y: "; printVector(y, ARRAY_SIZE); std::cout << "\n";
    std::cout << "z: "; printVector(z, ARRAY_SIZE); std::cout << std::endl;
}

void addVector(int* a, int* b, int* c, int size)
{
    for (int i = 0; i < size; i++)
    {
        *c++ = *a++ + *b++;
    }
}

void printVector(int* vector, int size)
{
    std::cout << vector[0];
    for (int i = 1; i < size; i++)
    {
        std::cout << ", " << vector[i];
    }
}
