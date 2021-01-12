/*
* @author Arnoldo González Quesada, Boris Monge Chaves,Carlos Álvarez Ramírez.
* @ v1.0
* .cpp file for Person class which encapsules important data for this proejct.
*
*/
#include "Person.h"

bool Person::StoBool(string value)
{
    if (value == "Yes")  
        return true; 
    else 
        return false;
}

string Person::BtoString(bool value){
    if (value == true)
        return "Yes";
    return "No";
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
int Person::priority() const{ //Calculate priority
    const int TOTAL = 100;
    float per = 0.0f;//percentage;
    if (this->withChild) per += 0.20;
    if (this->pregnant) per += 0.25;
    if (this->elderly) per += 0.35;
    if(this->category == 1) per += 0.20;
    if (this->category == 2) per += 0.10;
    //category 3 has 0% percentage, so, it does not affect the priority.
    return int(TOTAL * per);
}
Person::Person(istream& input)
{
    string temp;
    getline(input, name, ',');
    input >> id;
    input.ignore();
    getline(input, temp, ',');
    this->withChild = StoBool(temp);
    getline(input, temp, ',');
    this->pregnant = StoBool(temp);
    getline(input, temp, ',');
    this->elderly = StoBool(temp);
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

void Person::serialize(ostream& out)
{
    out << this->name << ",";
    out << this->id << ",";
    out << BtoString(this->withChild) << ",";
    out << BtoString(this->pregnant) << ",";
    out << BtoString(this->elderly) << ",";
    out << this->category;
}

string Person::toString() const
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


ostream& operator <<(ostream& o, const Person& p2) {
    o << p2.toString();
    return o;
}

bool  Person::operator <(const Person& p2) const {
    return (this->priority() < p2.priority());
}

bool Person::operator == (const Person& p2) const {
    return (this->priority() == p2.priority());
}

bool Person::operator > (const Person& p2) const {
    return (this->priority() > p2.priority());
}

