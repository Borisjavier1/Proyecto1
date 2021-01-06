/*
* @author Arnoldo González Quesada, Boris Monge Chaves,Carlos Álvarez Ramírez.
* @ v1.0
* DataPersistence class that handles data recovery from local files.
*
*/
#pragma once
#include "Person.h"
#include <vector>
#include "BST.h"
class dataPersistence {
private:
	string fileRoute;

public: 
	dataPersistence(string fileRoute);
	void deserialize(vector<Person*>* v);
	void deserialize(BST<Person>* bst);
	void serialize();

};