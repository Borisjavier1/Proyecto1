/*
* @author Arnoldo González Quesada, Boris Monge Chaves,Carlos Álvarez Ramírez.
* @ v1.0
* .cpp file that contains the main function of this program.
* 
*/

#include "Menu.h"
#include "HeapPriorityQueue.h"
#include "Person.h"
int main(){
	/*
	Menu* main = new Menu();
	main->mainMenu();
	*/
	Vector<int>* h = new Vector<int>(50);
	h->insertPosition(356, h->getSize());
	h->insertPosition(423, h->getSize());

	cout << h->toString();
	Vector<Person>* vp = new Vector<Person>(10);
	vp->push_back(*(new Person("El Pepe",666,false,false,false,3)));
	vp->push_back(*(new Person("Prueba 2", 665, false, false, false, 3)));
	cout << vp->toString();
	delete h,vp;
	return 0;
}
