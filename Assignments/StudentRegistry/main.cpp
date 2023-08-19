#include <iostream>

#include "StudentRegistry.h"

int main(int argc, char const *argv[])
{

    StudentRegistry reg;

    reg.addStudent("Ramon", 10, 10);
    reg.addStudent("Harry", 7.5, 7);
    reg.addStudent("Ron", 7, 7);
    reg.addStudent("Hermionie", 8.5, 9);
    reg.addStudent("Draco", 7.2, 8);

    reg.printRegistry();

    reg.updateStudent();
    reg.updateStudent(1, "Harry Potter", 8.3, 8.5);

    reg.printRegistry();

    return 0;
}
