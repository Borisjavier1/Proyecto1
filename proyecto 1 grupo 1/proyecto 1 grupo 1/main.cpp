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
	HeapPriorityQueue<int>* h = new HeapPriorityQueue<int>();
	h->insert(new int(666));
	h->insert(new int(345));
	h->insert(new int(23));
	h->insert(new int(22));
	h->insert(new int(34));
	cout << h->getSize();

}
