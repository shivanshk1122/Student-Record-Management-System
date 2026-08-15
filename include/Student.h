#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

class Student : public Person
{
private:
    int rollNumber;
    string branch;
    int semester;
    double cgpa;

public:
    Student();
    Student(int rollNumber, string name, string phone,
            string branch, int semester, double cgpa);

    void setRollNumber(int rollNumber);
    void setBranch(string branch);
    void setSemester(int semester);
    void setCGPA(double cgpa);

    int getRollNumber() const;
    string getBranch() const;
    int getSemester() const;
    double getCGPA() const;

    char calculateGrade() const;

    void display() const override;
};

#endif