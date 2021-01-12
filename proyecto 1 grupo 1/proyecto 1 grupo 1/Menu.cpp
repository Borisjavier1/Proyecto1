/*
* @author Arnoldo Gonz�lez Quesada, Boris Monge Chaves,Carlos �lvarez Ram�rez.
* @ v1.0
* .cpp file for menu class that handles the input and output interaction between the user and the console.
*
*/
#include "Menu.h"
Menu::Menu() {
	bst = new BST<Person>();
	data = new DataPersistence("Personas.csv");
}
Menu::~Menu() {
	delete bst;
	delete data;
}
void Menu::init() {
	
	try { data->deserialize(bst); }
	catch (RuntimeException e) { printn(e.ErrorMessage()); cont(); }
}
void Menu::startScreen() {
	setlocale(LC_ALL, "");
	printn("..............................................................................");
	printn("Autores: ");
	printn("	-Arnoldo Gonz�lez Quesada.");
	printn("	-Boris Monge Chaves.");
	printn("	-Carlos �lvarez Ram�rez.");
	printn("Grupo #1.");
	printn("Proyecto I. Estructuras de datos. EIF-207.");
	printn("Escuela de inform�tica. Universidad Nacional. Heredia, Costa Rica.");
	printn("Profesor: Ms.C Gregorio Villalobos Camacho.");
	printn("Enero, 2021.");
	printn("..............................................................................");
	cont();
}
void Menu::mainMenu() {
	setlocale(LC_ALL, ""); //For spanish accents
	startScreen();
	
	while (true) {
		clearScreen();
		printn("..............................................................................");
		printn("�Bienvenido!");
		printn("Seleccione una de las opciones: ");
		printn("1- Encolar todos los clientes.");
		printn("2- Encolar un cliente.");
		printn("3- Atender los siguientes 5 clientes.");
		printn("4- Mostrar el siguiente cliente a ser atendido.");
		printn("5- Simulaci�n de atenci�n de clientes.");
		printn("6- Agregar un cliente nuevo.");
		printn("7- Salir del programa.");
		printn("..............................................................................");
		try{
			switch (_getch()) {
			case '1': option1(); break;
			case '2': option2(); break;
			case '3': option3(); break;
			case '4': option4(); break;
			case '5': option5(); break;
			case '6': option6(); break;
			case '7': option7(); break;
			default: throw InvalidOption("La opci�n de men� digitada es inv�lida.");
			}
		}
		catch (RuntimeException e) { printnError(e.ErrorMessage()); cont(); }
	}
}

void Menu::option1() {
	
	
	clearScreen();
	printn("Opci�n 1: Encolar todos los clientes.");
	if (bst->empty()) {
		init();
		printn("�Se han cargado los clientes del archivo!");
		printn("�Desea ver la informaci�n de todos los clientes ingresados?");
		printn("1: S�.\n2: No.");
		while (1) {
			switch (_getch()) {
			case '1': printn(bst->toString()); cont(); return;
			case '2': cont(); return;
			}
		}
	}
	else
		printn("Los clientes ya fueron cargados.");
	cont();
}
void Menu::option2() {
	clearScreen();
	printn("Opci�n 2: Encolar un cliente.");
	if (bst->getRoot()->getData() == nullptr) { throw EmptyBST("El �rbol est� vac�o."); }
	cont();
	printn("Ingrese el n�mero de c�dula de la persona que desea encolar.");
	if (bst->search(readLongLong()) == nullptr)
		throw ClientNotFound("No existe una persona con dicho n�mero de c�dula.");
	else Person* p = bst->search(readLongLong());

	
}
void Menu::option3() {
	clearScreen();
	printn("Opci�n 3: Atender los siguientes 5 clientes.");
	cont();
}
void Menu::option4() {
	clearScreen();
	printn("Opci�n 4: Mostrar el siguiente cliente a ser atendido.");
	cont();
}
void Menu::option5() {
	clearScreen();
	printn("Opci�n 5: Simulaci�n de atenci�n de clientes");
	cont();
}

void Menu::option6() {
	clearScreen();
	printn("Opci�n 6: Agregar un cliente nuevo.");
	cont();
}

void Menu::option7()
{
	printn("Gracias por usar este programa!"); 
	// aqu� va prob� serializaci�n 
	//try { data->deserialize(bst); }
	//catch (RuntimeException e) { printn(e.ErrorMessage()); cont(); }
	delete this;
	programExit();
}
