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

	/*
	VectorCompleteTree<Person>* p = new VectorCompleteTree<Person>();
	p->addLast(new Person("El Pepe", 666, true, true, false, 3));
	p->addLast(new Person("Prueba 2", 665, true, true, false, 3));
	p->addLast(new Person("Prueba 3", 665, true, true, false, 3));
	p->addLast(new Person("Prueba 4", 665, true, true, false, 3));
	p->addLast(new Person("Prueba 5", 665, false, false, false, 3));
	//cout << p->toString() << endl;
	delete p;
	*/
	HeapPriorityQueue<Person>* p = new HeapPriorityQueue<Person>();
	p->insert(new Person("El Pepe", 123, true, true, true, 3));
	p->insert(new Person("Prueba 2", 124, true, true, true, 3));
	p->insert(new Person("Prueba 3", 125, true, true, true, 3));
	p->insert(new Person("Prueba 4", 126, true, true, true, 3));
	p->insert(new Person("Prueba 5", 127, true, true, true, 3));
	while (!p->empty()) {
		cout << *p->min();
		p->removeMin();
	}
	delete p;
}
