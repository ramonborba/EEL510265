#pragma once

#include <string>

#define N_GRADES 2

class Student
{
public:
    Student();
    ~Student();

    void setId(unsigned int newId);
    void setGrade(float newGrade, unsigned int pos);
    void setName(std::string newName);

    float getGrade(unsigned int pos) const;
    unsigned int getId() const;
    std::string getName() const;

    bool isValid() const;
    void setValid();
    void setInvalid();

    float getAverageGrade() const;
    void print() const;
private:
    float grade[N_GRADES];
    unsigned int id;
    std::string name;
    bool valid;
};
