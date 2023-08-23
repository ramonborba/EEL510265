#include <iostream>

#include "StudentRegistry.h"

void pressEnterToContinue();

int main(int argc, char const *argv[])
{
    using namespace std;

    StudentRegistry reg;

    bool exit = false;
    int command = -1;
    
    system("clear");
    while (!exit)
    {
        cout << "----- Student Registry System -----\n\n";

        cout << "Available commands:\n\n";
        cout << "   1 - Add student\n";
        cout << "   2 - Search student\n";
        cout << "   3 - Update student\n";
        cout << "   4 - Remove student\n";
        cout << "   5 - List registry\n\n";
        cout << "Command: ";
        cin >> command;

        switch (command)
        {
        case 1:
            reg.addStudent();
            break;
        
        case 2:
            reg.printStudent();
            break;
        
        case 3:
            reg.updateStudent();
            break;
        
        case 4:
            reg.deleteStudent();
            break;
        
        case 5:
            reg.printRegistry();
            break;
        
        case 0:
            exit = true;
            system("clear");
            continue;
        
        default:
            cout << "Invalid commmand.\n" << endl;
            break;
        }
        pressEnterToContinue();
    }
    
    return 0;
}

void pressEnterToContinue()
{
    std::cout << std::endl << "Press 'Enter' to continue.";
    std::cin.ignore();
    std::cin.get();
    system("clear");
}
