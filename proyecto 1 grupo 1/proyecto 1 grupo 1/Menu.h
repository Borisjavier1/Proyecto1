/*
* @author Arnoldo González Quesada, Boris Monge Chaves,Carlos Álvarez Ramírez.
* @ v1.0
* Menu class that handles the input and output interaction between the user and the console.
*
*/
#ifndef MENU_H
#define MENU_H

#include "Tools.h"
#include "DataPersistence.h"

class Menu {
private:
	DataPersistence* data;
protected:
	BST<Person>* bst; //person binary search tree
	HeapPriorityQueue<Person>* hpq;
public:
	Menu();
	virtual ~Menu();
	void mainMenu();
	void init();
	void startScreen();
	void option1();
	void option2();
	void option3();
	void option4();
	void option5();
	void option6();
	void option7();
	Person* getDataPerson();
};

#endif