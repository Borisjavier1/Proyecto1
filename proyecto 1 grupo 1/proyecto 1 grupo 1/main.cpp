/*
* @author Arnoldo González Quesada, Boris Monge Chaves,Carlos Álvarez Ramírez.
* @ v1.0
* .cpp file that contains the main function of this program.
* 
*/

#include "Menu.h"
#include "HeapPriorityQueue.h"
int main(){
	/*
	Menu* main = new Menu();
	main->mainMenu();
	*/
	Vector<int>* h = new Vector<int>(50);
	h->insertPosition(356, h->getSize());
	h->insertPosition(423, h->getSize());
	h->insertPosition(37, h->getSize());
	h->insertPosition(25, h->getSize());
	cout << h->toString();
	delete h;
	return 0;
}
