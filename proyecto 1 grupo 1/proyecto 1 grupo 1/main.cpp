/*
* @author Arnoldo González Quesada, Boris Monge Chaves,Carlos Álvarez Ramírez.
* @ v1.0
* .cpp file that contains the main function of this program.
* 
*/

#include "Menu.h"
#include "VectorCompleteTree.h"
#include "Person.h"
#include "HeapPriorityQueue.h"
int main() {
	/*
	Menu* main = new Menu();
	main->mainMenu();
	*/

	/*Vector<int>* h = new Vector<int>(50);
	h->insertPosition(356, h->getSize());
	h->insertPosition(423, h->getSize());*/

	//cout << h->toString();
	/*Vector<Person*>* vp = new Vector<Person*>(10);
	vp->push_back(new Person("El Pepe",666,false,false,false,3));
	vp->push_back(new Person("Prueba 2", 665, false, false, false, 3));
	cout << vp->toString();
	delete vp;*/
	/*
	HeapPriorityQueue<Person>* p = new HeapPriorityQueue<Person>();
	p->insert(new Person("El Pepe", 666, false, false, false, 3));
	p->insert(new Person("Prueba 2", 665, false, false, false, 3));
	p->insert(new Person("Prueba 3", 665, false, false, false, 3));
	p->insert(new Person("Prueba 4", 665, false, false, false, 3));
	p->insert(new Person("Prueba 5", 665, false, false, false, 3));
	cout << p->toString() << "\n";
	delete p;
	*/
	
	
	VectorCompleteTree<Person>* p = new VectorCompleteTree<Person>();
	p->addLast(new Person("El Pepe", 666, true, true, false, 3));
	p->addLast(new Person("Prueba 2", 665, true, true, false, 3));
	p->addLast(new Person("Prueba 3", 665, true, true, false, 3));
	p->addLast(new Person("Prueba 4", 665, true, true, false, 3));
	p->addLast(new Person("Prueba 5", 665, false, false, false, 3));
	//cout << p->toString() << endl;
	delete p;
}
