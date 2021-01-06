/*
* @author Arnoldo Gonz�lez Quesada, Boris Monge Chaves,Carlos �lvarez Ram�rez.
* @ v1.0
* .cpp file for DataPersistence class that handles data recovery from local files.
*
*/
#include "dataPersistence.h"

dataPersistence::dataPersistence(string fileRoute)
{
	this->fileRoute = fileRoute;
}

void dataPersistence::deserialize(vector<Person*>* v)
{
	ifstream in(fileRoute, ios::in);
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
void dataPersistence::deserialize(BST<Person>* bst){
	ifstream in(fileRoute, ios::in);
	if (in.good())
		while (!in.eof() && in.good()){
			Person* p = new Person(in);	
			bst->insert(p);	
		}
	in.close();
}
void dataPersistence::serialize()
{
	/*int size = this->tree->size();
	if (size > 0) {
		ofstream out(this->fileRoute, ios::out);

		if (out.good())
		{
			for (int i = 0; i < size; i++)
			{
				Tree* t = //logica del arbol
				t->serialize(out);

				if (i != size - 1)
					out << endl;
			}

			out.close();
		}
	}*/
}

