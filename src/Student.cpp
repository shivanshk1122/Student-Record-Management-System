#include "../include/Student.h"
#include <iostream>
#include <iomanip>

using namespace std;

Student::Student()
{
    rollNumber = 0;
    branch = "";
    semester = 0;
    cgpa = 0.0;
}

Student::Student(int rollNumber, string name, string phone,
                 string branch, int semester, double cgpa)
    : Person(name, phone)
{
    this->rollNumber = rollNumber;
    this->branch = branch;
    this->semester = semester;
    this->cgpa = cgpa;
}

void Student::setRollNumber(int rollNumber)
{
    this->rollNumber = rollNumber;
}

void Student::setBranch(string branch)
{
    this->branch = branch;
}

void Student::setSemester(int semester)
{
    this->semester = semester;
}

void Student::setCGPA(double cgpa)
{
    this->cgpa = cgpa;
}

int Student::getRollNumber() const
{
    return rollNumber;
}

string Student::getBranch() const
{
    return branch;
}

int Student::getSemester() const
{
    return semester;
}

double Student::getCGPA() const
{
    return cgpa;
}

char Student::calculateGrade() const
{
    if (cgpa >= 9.0)
        return 'A';
    else if (cgpa >= 8.0)
        return 'B';
    else if (cgpa >= 7.0)
        return 'C';
    else if (cgpa >= 6.0)
        return 'D';
    else
        return 'F';
}

void Student::display() const
{
    cout << "Roll Number : " << rollNumber << endl;
    cout << "Name        : " << name << endl;
    cout << "Phone       : " << phone << endl;
    cout << "Branch      : " << branch << endl;
    cout << "Semester    : " << semester << endl;
    cout << fixed << setprecision(2);
    cout << "CGPA        : " << cgpa << endl;
    cout << "Grade       : " << calculateGrade() << endl;
}