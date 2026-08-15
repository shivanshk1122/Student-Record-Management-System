#include "../include/Person.h"
#include <iostream>

using namespace std;

Person::Person()
{
    name = "";
    phone = "";
}

Person::Person(string name, string phone)
{
    this->name = name;
    this->phone = phone;
}

void Person::setName(string name)
{
    this->name = name;
}

void Person::setPhone(string phone)
{
    this->phone = phone;
}

string Person::getName() const
{
    return name;
}

string Person::getPhone() const
{
    return phone;
}

void Person::display() const
{
    cout << "Name  : " << name << endl;
    cout << "Phone : " << phone << endl;
}

Person::~Person()
{
}