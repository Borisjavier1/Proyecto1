/*
* @author Arnoldo González Quesada, Boris Monge Chaves,Carlos Álvarez Ramírez.
* @ v1.0
* .cpp file for DataPersistence class that handles data recovery from local files.
*
*/
#include "dataPersistence.h"

DataPersistence::DataPersistence()
{
	filePath = "";
}

DataPersistence::DataPersistence(string filePath)
{
	this->filePath = filePath;
}


void DataPersistence::deserialize(BST<Person>* bst){
	ifstream in(filePath, ios::in);
	if (in.good()) {
		while (!in.eof() && in.good()) {
			Person* p = new Person(in);
			bst->insert(p);
		}
		in.close();
	}
	else { throw FileError("Ruta del archivo no es valida o no hay permisos"); }
	
}
void DataPersistence::serialize(BST<Person>* bst)
{
	int size = bst->getSize();
	if (size > 0) {
		ofstream out(this->filePath, ios::out);

		if (out.good()) {
			{
				bst->serializeTree(out, bst->getRoot());

			}
			out.close();
		}
		else { throw FileError("Ruta del archivo no es valida o no hay permisos"); }
	}

}

