/*
* @author Arnoldo González Quesada, Boris Monge Chaves,Carlos Álvarez Ramírez.
* @ v1.0
* .cpp file for DataPersistence class that handles data recovery from local files.
*
*/
#include "dataPersistence.h"

dataPersistence::dataPersistence()
{
	filePath = "";
}

dataPersistence::dataPersistence(string filePath)
{
	this->filePath = filePath;
}


void dataPersistence::deserialize(BST<Person>* bst){
	ifstream in(filePath, ios::in);
	if (in.good())
		while (!in.eof() && in.good()){
			Person* p = new Person(in);	
			bst->insert(p);	
		}
	in.close();
}
void dataPersistence::serialize(BST<Person>* bst)
{
	int size = bst->getSize();
	if (size > 0) {
		ofstream out(this->filePath, ios::out);

		if (out.good())
		{
	       bst->serializeTree(out, bst->getRoot());
			
		}
		out.close();
	}
}

