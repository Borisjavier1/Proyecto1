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

string Person::BtoString(bool value)
{
    if (value == true)
        return "Yes";
    else
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
/*
ostream& operator <<(ostream& o, const Person& p2) {
    o << p2.toString();
    return o;
}
*/
ostream& operator <<(ostream& o, const Person& p2) {
    o << p2.toString();
    return o;
}
bool  Person::operator <(const Person& p2) const {
    int con_p1 = this->getCategory(), con_p2 = p2.getCategory();//conditions
    /*
    //This also could be as:
    //The conditions are asked separately in order to get a sum that details which person has more priority.
    if (this->withChild) con_p1++;
    if (this->pregnant) con_p1++;
    if (this->elderly) con_p1++;
    if (p2.withChild) con_p2++;
    if (p2.pregnant) con_p2++;
    if (p2.elderly) con_p2++;
    return con_p1 < con_p2;

    or to be read in an easier way: 

    return (int(this->withChild) + int(this->pregnant) + int(this->elderly) + con_p1)
    < (int(p2.withChild) + int(p2.pregnant) + int(p2.elderly) + con_p2);
 
    */
    return (this->getWithChild() + this->getPregnant() + this->getElderly() + con_p1)
    < (p2.getWithChild() + p2.getPregnant() + p2.getElderly() + con_p2);

}

bool Person::operator == (const Person& p2) const {
    int con_p1 = this->getCategory(), con_p2 = p2.getCategory();//conditions
    return (this->getWithChild() + this->getPregnant() + this->getElderly() + con_p1)
        == (p2.getWithChild() + p2.getPregnant() + p2.getElderly() + con_p2);
}

bool Person::operator > (const Person& p2) const {
    int con_p1 = this->getCategory(), con_p2 = p2.getCategory();//conditions
    return (this->getWithChild() + this->getPregnant() + this->getElderly() + con_p1)
        > (p2.getWithChild() + p2.getPregnant() + p2.getElderly() + con_p2);
}

