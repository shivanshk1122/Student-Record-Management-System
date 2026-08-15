#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H

#include "Student.h"
#include <vector>
#include <string>

using namespace std;

class StudentManager
{
private:
    vector<Student> students;
    string fileName;

public:
    StudentManager(string fileName = "data/students.txt");

    void addStudent();
    void displayAllStudents() const;
    void searchStudent() const;
    void updateStudent();
    void deleteStudent();

    void saveToFile() const;
    void loadFromFile();

    int findStudentIndex(int rollNumber) const;
};

#endif
