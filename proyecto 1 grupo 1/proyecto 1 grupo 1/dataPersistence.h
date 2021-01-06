#pragma once
#include "Person.h"
#include <vector>

class dataPersistence {
private:
	string fileRoute;

public: 
	dataPersistence(string fileRoute);
	void deserialize(vector<Person*>* v);
	void serialize();
		
	


};