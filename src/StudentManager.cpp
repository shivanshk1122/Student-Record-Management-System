#include "../include/StudentManager.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

StudentManager::StudentManager(string fileName)
{
    this->fileName = fileName;
    loadFromFile();
}

int StudentManager::findStudentIndex(int rollNumber) const
{
    for (int i = 0; i < static_cast<int>(students.size()); i++)
    {
        if (students[i].getRollNumber() == rollNumber)
        {
            return i;
        }
    }

    return -1;
}

void StudentManager::addStudent()
{
    int rollNumber;
    string name;
    string phone;
    string branch;
    int semester;
    double cgpa;

    cout << "\nEnter Roll Number: ";
    cin >> rollNumber;

    if (findStudentIndex(rollNumber) != -1)
    {
        cout << "A student with this roll number already exists.\n";
        return;
    }

    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Phone Number: ";
    getline(cin, phone);

    cout << "Enter Branch: ";
    getline(cin, branch);

    cout << "Enter Semester: ";
    cin >> semester;

    cout << "Enter CGPA: ";
    cin >> cgpa;

    if (semester < 1 || semester > 8)
    {
        cout << "Invalid semester.\n";
        return;
    }

    if (cgpa < 0.0 || cgpa > 10.0)
    {
        cout << "Invalid CGPA. CGPA must be between 0 and 10.\n";
        return;
    }

    Student student(
        rollNumber,
        name,
        phone,
        branch,
        semester,
        cgpa
    );

    students.push_back(student);

    saveToFile();

    cout << "\nStudent added successfully!\n";
}

void StudentManager::displayAllStudents() const
{
    if (students.empty())
    {
        cout << "\nNo student records found.\n";
        return;
    }

    cout << "\n========== STUDENT RECORDS ==========\n";

    for (const Student& student : students)
    {
        student.display();
        cout << "-------------------------------------\n";
    }
}

void StudentManager::searchStudent() const
{
    int rollNumber;

    cout << "\nEnter Roll Number to search: ";
    cin >> rollNumber;

    int index = findStudentIndex(rollNumber);

    if (index == -1)
    {
        cout << "Student not found.\n";
        return;
    }

    cout << "\nStudent found:\n";
    students[index].display();
}

void StudentManager::updateStudent()
{
    int rollNumber;

    cout << "\nEnter Roll Number to update: ";
    cin >> rollNumber;

    int index = findStudentIndex(rollNumber);

    if (index == -1)
    {
        cout << "Student not found.\n";
        return;
    }

    string name;
    string phone;
    string branch;
    int semester;
    double cgpa;

    cin.ignore();

    cout << "Enter new Name: ";
    getline(cin, name);

    cout << "Enter new Phone Number: ";
    getline(cin, phone);

    cout << "Enter new Branch: ";
    getline(cin, branch);

    cout << "Enter new Semester: ";
    cin >> semester;

    cout << "Enter new CGPA: ";
    cin >> cgpa;

    if (semester < 1 || semester > 8 ||
        cgpa < 0.0 || cgpa > 10.0)
    {
        cout << "Invalid student information.\n";
        return;
    }

    students[index].setName(name);
    students[index].setPhone(phone);
    students[index].setBranch(branch);
    students[index].setSemester(semester);
    students[index].setCGPA(cgpa);

    saveToFile();

    cout << "Student record updated successfully!\n";
}

void StudentManager::deleteStudent()
{
    int rollNumber;

    cout << "\nEnter Roll Number to delete: ";
    cin >> rollNumber;

    int index = findStudentIndex(rollNumber);

    if (index == -1)
    {
        cout << "Student not found.\n";
        return;
    }

    students.erase(students.begin() + index);

    saveToFile();

    cout << "Student record deleted successfully!\n";
}

void StudentManager::saveToFile() const
{
    ofstream file(fileName);

    if (!file)
    {
        cout << "Error: Unable to open file for saving.\n";
        return;
    }

    for (const Student& student : students)
    {
        file << student.getRollNumber() << "|"
             << student.getName() << "|"
             << student.getPhone() << "|"
             << student.getBranch() << "|"
             << student.getSemester() << "|"
             << student.getCGPA() << "\n";
    }

    file.close();
}

void StudentManager::loadFromFile()
{
    ifstream file(fileName);

    if (!file)
    {
        return;
    }

    students.clear();

    int rollNumber;
    string name;
    string phone;
    string branch;
    int semester;
    double cgpa;

    while (file >> rollNumber)
    {
        file.ignore();

        getline(file, name, '|');
        getline(file, phone, '|');
        getline(file, branch, '|');

        file >> semester;
        file.ignore();

        file >> cgpa;
        file.ignore();

        Student student(
            rollNumber,
            name,
            phone,
            branch,
            semester,
            cgpa
        );

        students.push_back(student);
    }

    file.close();
}