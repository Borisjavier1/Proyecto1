#pragma once
#include "Person.h"
#include <vector>

class loadData {
public: 
	static void deserialize(vector<Person*>* v) {
		
		ifstream in("Personas.csv", ios::in);
		if (in.good())
		{
			while (!in.eof() && in.good())
			{
				Person* p = new Person(in);
				v->push_back(p);
			
			}
			in.close();
		}
	}


};