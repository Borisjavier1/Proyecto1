/*
* @author Arnoldo González Quesada, Boris Monge Chaves,Carlos Álvarez Ramírez.
* @ v1.0
* .cpp file that contains the main function of this program.
* 
*/
#include "Menu.h"
int main(){
	Menu* main = new Menu();
	main->mainMenu();
	delete main;
}
