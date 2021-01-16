/*
* @author Arnoldo González Quesada, Boris Monge Chaves,Carlos Álvarez Ramírez.
* @ v1.0
* .h file for Person class which encapsules important data for this proejct.
*
*/
#pragma once
#include "Libraries.h"
class Person
{
private:
    string name;
    long long id;
    bool withChild;
    bool pregnant;
    bool elderly;
    int category;
    bool StoBool(string value);
    string BtoString(bool value);
    string booleanToText(bool value) const;
public:
    Person(string name = "", long long id = 0, bool withChild = false, bool pregnant = false, bool elderly = false, int category = 0);
    Person(istream& input);
    string getName() const;
    void setName(string name);
    long long getId() const;
    void setId(long long id);
    bool getWithChild() const;
    void setWithChild(bool withChild);
    bool getPregnant() const;
    void setPregnant(bool pregnant);
    bool getElderly() const;
    void setElderly(bool elderly);
    int getCategory() const;
    void setCategory(int category);
    void serialize(ostream& out);
    string toString() const;
    int priority() const; //Calculate priority
    bool operator < (const Person& p2) const;
    bool operator == (const Person& p2) const;
    bool operator > (const Person& p2) const;
    bool operator <= (const Person& p2) const;
    bool operator >= (const Person& p2) const;

};
ostream& operator << (ostream& o, const Person& p2);
