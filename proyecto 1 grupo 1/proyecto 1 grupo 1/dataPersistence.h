/*
* @author Arnoldo Gonz�lez Quesada, Boris Monge Chaves,Carlos �lvarez Ram�rez.
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
	string filePath;

public: 
	dataPersistence();
	dataPersistence(string fileRoute);
	void deserialize(BST<Person>* bst);
	void serialize(BST<Person>* bst);

};