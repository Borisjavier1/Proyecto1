#include "Person.h"

bool Person::toBool(string value)
{
    if (value == "Yes")  
        return true; 
    else 
        return false;
}

Person::Person(string name, long long id, bool withChild, bool pregnant, bool elderly, int category)
{
    this->name = name;
    this->id = id;
    this->withChild = withChild;
    this->pregnant = pregnant;
    this->elderly = elderly;
    this->category = category;
}

Person::Person(istream& input)
{
    string temp;
    getline(input, name, ',');
    input >> id;
    input.ignore();
    getline(input, temp, ',');
    this->withChild = toBool(temp);
    getline(input, temp, ',');
    this->pregnant = toBool(temp);
    getline(input, temp, ',');
    this->elderly = toBool(temp);
    input >> category;
    input.ignore();

}

string Person::getName() const
{
    return name;
}

void Person::setName(string name)
{
    this->name = name;
}

long long Person::getId() const
{
    return id;
}

void Person::setId(long long id)
{
    this->id = id;
}

bool Person::getWithChild() const
{
    return withChild;
}

void Person::setWithChild(bool withChild)
{
    this->withChild = withChild;
}

bool Person::getPregnant() const
{
    return pregnant;
}

void Person::setPregnant(bool pregnant)
{
    this->pregnant = pregnant;
}

bool Person::getElderly() const
{
    return elderly;
}

void Person::setElderly(bool elderly)
{
    this->elderly = elderly;
}

int Person::getCategory() const
{
    return category;
}

void Person::setCategory(int category)
{
    this->category = category;
}

string Person::toString()
{
    stringstream s;
    s << "Nombre: " << name << endl;
    s << "ID: " << id << endl;
    s << "Con hijo: " << withChild << endl;
    s << "Embarazada: " << pregnant << endl;
    s << "Adulto mayor: " << elderly << endl;
    s << "category: " << category << endl;
    return s.str();
}

