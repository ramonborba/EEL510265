#include <iostream>
#include <string>

#include "StudentRegistry.h"

StudentRegistry::StudentRegistry(/* args */)
{
    numId = 0;
    entries = 0;
}

StudentRegistry::~StudentRegistry()
{
}

unsigned int StudentRegistry::getCapacity() const
{
    return entries;
}

unsigned int StudentRegistry::generateId()
{
    return numId++;
}

int StudentRegistry::findFreeSpot()
{
    int index = -1;
    for (int i = 0; (i < N_STUDENTS && index < 0) ; i++)
    {
        if (students[i].isValid() == false)
        {
            index = i;
        }
    }
    return index;
}

int StudentRegistry::addStudent()
{
    using namespace std;

    int index = findFreeSpot();

    if (index >= 0 ) 
    {
        char name[50];
        float grade1;
        float grade2;
        cout << "----- New Student -----\n\n";
        cout << "Name: ";
        cin.getline(name, 50);
        cout << "Grade P1: ";
        cin >> grade1;
        cout << "Grade P2: ";
        cin >> grade2;
        cout << endl;

        students[index].setId(generateId());
        students[index].setName(name);
        students[index].setGrade(grade1, 0);
        students[index].setGrade(grade2, 1);
        students[index].setValid();
        entries++;
        cout << "Student registered succesfully\n";
    }
    else
    {
        cout << "Error: Registry full.\n";
    }
    return index;
}

int StudentRegistry::addStudent(std::string name, float grade1, float grade2)
{
    int index = findFreeSpot();

    if (index >= 0) 
    {
        students[index].setId(generateId());
        students[index].setName(name);
        students[index].setGrade(grade1, 0);
        students[index].setGrade(grade2, 1);
        students[index].setValid();
        entries++;
    }

    return index;
}

int StudentRegistry::deleteStudent(unsigned int id)
{
    int err = 0;
    Student* st = searchStudent(id);
    if (st)
    {
        st->setInvalid();
        entries--;
    }
    else
    {
        err = -1;
    }
    return err;
}

Student* const StudentRegistry::searchStudent(unsigned int id)
{
    Student* st = nullptr;
    for (int i = 0; i < N_STUDENTS; i++) {
        if (students[i].isValid() && students[i].getId() == id)
        {
            st = &students[i];
        }
    }
    return st;
}

const Student* const StudentRegistry::searchStudent(unsigned int id) const
{
    const Student* st = nullptr;
    for (int i = 0; i < N_STUDENTS; i++) {
        if (students[i].isValid() && students[i].getId() == id)
        {
            st = &students[i];
        }
    }
    return st;
}

int StudentRegistry::updateStudent()
{
    using namespace std;

    int err = 0;

    unsigned int id = -1;
    cout << "Student ID: ";
    cin >> id;

    Student* const st = searchStudent(id);

    if (st) 
    {
        char name[50];
        float grade1;
        float grade2;
        cout << "\n----- Updating Student -----\n\n"; 
        cout << "Name: ";
        cin.ignore();
        cin.getline(name, 50);
        cout << "Grade P1: ";
        cin >> grade1;
        cout << "Grade P2: ";
        cin >> grade2;
        cout << endl;

        st->setName(name);
        st->setGrade(grade1, 0);
        st->setGrade(grade2, 1);
        cout << "Student updated succesfully.\n";
    }
    else
    {
        cout << "Error: Student not found.\n";
        err = -1;
    }
    return err;
}

int StudentRegistry::updateStudent(unsigned int id, std::string name, float grade1, float grade2)
{
    int err = 0;

    Student* const st = searchStudent(id);

    if (st)
    {
        st->setName(name);
        st->setGrade(grade1, 0);
        st->setGrade(grade2, 1);
    }
    else
    {
        err = -1;
    }

    return err;
}

int StudentRegistry::printStudent(unsigned int id) const
{
    int err = 0;
    const Student* const st = searchStudent(id);
    if (st)
    {
        st->print();
    }
    else
    {
        err = -1;
    }
    return err;
}

void StudentRegistry::printRegistry() const
{
    using namespace std;

    cout << "----- Student Registry -----\n\n";

    cout << "Registered students: " << entries << "\n\n";

    for (int i = 0; i < N_STUDENTS; i++)
    {
        if (students[i].isValid())
        {
            cout << "---------------\n";
            students[i].print();
        }
    }
    cout << "---------------\n\n";
    cout << "----------------------------\n";
    cout << endl;
}
