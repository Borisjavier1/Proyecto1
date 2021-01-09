/*
* @author Arnoldo González Quesada, Boris Monge Chaves,Carlos Álvarez Ramírez.
* @ v1.0
* DataPersistence class that handles data recovery from local files.
*
*/
#pragma once
#include "Person.h"
#include "BST.h"
#include "RuntimeException.h"
class DataPersistence {
private:
	string filePath;

public: 
	DataPersistence();
	DataPersistence(string fileRoute);
	void deserialize(BST<Person>* bst);
	void serialize(BST<Person>* bst);

};