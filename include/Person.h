#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person
{
protected:
    string name;
    string phone;

public:
    Person();
    Person(string name, string phone);

    void setName(string name);
    void setPhone(string phone);

    string getName() const;
    string getPhone() const;

    virtual void display() const;
    virtual ~Person();
};

#endif