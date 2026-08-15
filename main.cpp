#include <iostream>
#include "include/StudentManager.h"

using namespace std;

void displayMainMenu()
{
    cout << "\n========================================\n";
    cout << "     STUDENT RECORD MANAGEMENT SYSTEM\n";
    cout << "========================================\n";
    cout << "1. Add Student\n";
    cout << "2. Display All Students\n";
    cout << "3. Search Student\n";
    cout << "4. Update Student\n";
    cout << "5. Delete Student\n";
    cout << "6. Exit\n";
    cout << "========================================\n";
    cout << "Enter your choice: ";
}

int main()
{
    StudentManager manager;

    int choice;

    do
    {
        displayMainMenu();
        cin >> choice;

        try
        {
            switch (choice)
            {
                case 1:
                    manager.addStudent();
                    break;

                case 2:
                    manager.displayAllStudents();
                    break;

                case 3:
                    manager.searchStudent();
                    break;

                case 4:
                    manager.updateStudent();
                    break;

                case 5:
                    manager.deleteStudent();
                    break;

                case 6:
                    cout << "\nThank you for using the Student Record Management System!\n";
                    break;

                default:
                    cout << "\nInvalid choice. Please try again.\n";
            }
        }
        catch (const exception& e)
        {
            cout << "\nError: " << e.what() << endl;
        }

    } while (choice != 6);

    return 0;
}