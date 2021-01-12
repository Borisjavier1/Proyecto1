/*
* @author Arnoldo González Quesada, Boris Monge Chaves,Carlos Álvarez Ramírez.
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
	printn("	-Arnoldo González Quesada.");
	printn("	-Boris Monge Chaves.");
	printn("	-Carlos Álvarez Ramírez.");
	printn("Grupo #1.");
	printn("Proyecto I. Estructuras de datos. EIF-207.");
	printn("Escuela de informática. Universidad Nacional. Heredia, Costa Rica.");
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
		printn("¡Bienvenido!");
		printn("Seleccione una de las opciones: ");
		printn("1- Encolar todos los clientes.");
		printn("2- Encolar un cliente.");
		printn("3- Atender los siguientes 5 clientes.");
		printn("4- Mostrar el siguiente cliente a ser atendido.");
		printn("5- Simulación de atención de clientes.");
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
			default: throw InvalidOption("La opción de menú digitada es inválida.");
			}
		}
		catch (RuntimeException e) { printnError(e.ErrorMessage()); cont(); }
	}
}

void Menu::option1() {
	
	
	clearScreen();
	printn("Opción 1: Encolar todos los clientes.");
	if (bst->empty()) {
		init();
		printn("¡Se han cargado los clientes del archivo!");
		printn("¿Desea ver la información de todos los clientes ingresados?");
		printn("1: Sí.\n2: No.");
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
	printn("Opción 2: Encolar un cliente.");
	if (bst->getRoot()->getData() == nullptr) { throw EmptyBST("El árbol está vacío."); }
	cont();
	printn("Ingrese el número de cédula de la persona que desea encolar.");
	if (bst->search(readLongLong()) == nullptr)
		throw ClientNotFound("No existe una persona con dicho número de cédula.");
	else Person* p = bst->search(readLongLong());

	
}
void Menu::option3() {
	clearScreen();
	printn("Opción 3: Atender los siguientes 5 clientes.");
	cont();
}
void Menu::option4() {
	clearScreen();
	printn("Opción 4: Mostrar el siguiente cliente a ser atendido.");
	cont();
}
void Menu::option5() {
	clearScreen();
	printn("Opción 5: Simulación de atención de clientes");
	cont();
}

void Menu::option6() {
	clearScreen();
	printn("Opción 6: Agregar un cliente nuevo.");
	cont();
}

void Menu::option7()
{
	printn("Gracias por usar este programa!"); 
	// aquí va probé serialización 
	//try { data->deserialize(bst); }
	//catch (RuntimeException e) { printn(e.ErrorMessage()); cont(); }
	delete this;
	programExit();
}
