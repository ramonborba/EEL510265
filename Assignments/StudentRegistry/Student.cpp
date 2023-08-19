#include <iostream>

#include "Student.h"

Student::Student()
{
    name = "";
    id = 0;
    for (int i = 0; i < N_GRADES; i++)
    {
        grade[i] = 0;
    }
    valid = false;
}

Student::~Student()
{

}

void Student::setName(std::string newName)
{
    name = newName;
}

void Student::setId(unsigned int newId)
{
    id = newId;
}

void Student::setGrade(float newGrade, unsigned int pos)
{
    if (pos < N_GRADES)
    {
        grade[pos] = newGrade;
    }
    
}

std::string Student::getName() const
{
    return name;
}

unsigned int Student::getId() const
{
    return id;
}

float Student::getGrade(unsigned int pos) const
{
    float val = -1.0;
    if (pos < N_GRADES)
    {
        val = grade[pos];
    }
    return val;
}

bool Student::isValid() const
{
    return valid;
}

void Student::setValid()
{
    valid = true;
}
void Student::setInvalid()
{
    valid = false;
}

float Student::getAverageGrade() const
{
    float avg = 0;
    for (int i = 0; i < N_GRADES; i++)
    {
        avg += grade[i];
    }
    return avg / N_GRADES;
}

void Student::print() const
{
    std::cout << "\n";
    std::cout << " - ID:        " << id << "\n";
    std::cout << " - Name:      " << name << "\n";
    std::cout << " - Grade P1:  " << grade[0] << "\n";
    std::cout << " - Grade P2:  " << grade[1] << "\n";
    std::cout << " - Avg Grade: " << getAverageGrade() << "\n";
    std::cout << std::endl;
}
