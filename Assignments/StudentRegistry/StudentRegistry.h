#pragma once

#include "Student.h"

#define N_STUDENTS 20

class StudentRegistry
{
public:
    StudentRegistry();
    ~StudentRegistry();

    unsigned int getCapacity() const;

    int addStudent();
    int addStudent(std::string name, float grade1, float grade2);

    int deleteStudent();
    int updateStudent();

    int updateStudent(unsigned int id, std::string name, float grade1, float grade2);

    int printStudent() const;
    void printRegistry() const;

private:
    Student students[N_STUDENTS];
    unsigned int numId;
    unsigned int entries;

    unsigned int generateId();

    int findFreeSpot();

    Student* const searchStudent(unsigned int id);;
    const Student* const searchStudent(unsigned int id) const;

    unsigned int requestId() const;
};
