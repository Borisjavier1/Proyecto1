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
	hpq = new HeapPriorityQueue<Person>();
	init();
}
Menu::~Menu() {
	delete bst;
	delete data;
	delete hpq;
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
	printn("..............................................................................");
	printn("Opción 1: Encolar todos los clientes.");
	printn("..............................................................................");
	if (hpq->empty()) {
		bst->moveData(hpq, bst->getRoot());
		printn("¡Clientes tranferidos exitosamente!");
	}else  
		throw DataTransferred("Los clientes ya han sido tranferidos."); 
	
	cont();
}
void Menu::option2() {
	clearScreen();
	printn("..............................................................................");
	printn("Opción 2: Encolar un cliente.");
	printn("..............................................................................");
	printn("Ingrese el número de cédula de la persona que desea encolar.");
	long long id = readLongLong();
	Person* p = bst->search(id);
	if (!p) { throw ClientNotFound("No existe la persona con el número de cédula digitado.\n"); }
	else {
		if (hpq->getVCT()->searchById(id))
			throw DuplicatedClient("¡El cliente "+ p->getName() + " ya se encuentra en cola!");
		else {
			hpq->insert(p);
			printn("Cliente ingresado correctamente.");
		}
	}
	cont();
}
void Menu::option3() {
	clearScreen();
	const int MAX_TO_SHOW = 5;
	printn("..............................................................................");
	printn("Opción 3: Atender los siguientes 5 clientes.");
	printn("..............................................................................");
	if (hpq->empty()) throw EmptyHeapPriorityQueue("La cola se encuentra vacía.");
	printn("............................................");
	try {
		for (int i = 0; i < MAX_TO_SHOW; i++) {
			if (hpq->empty())  throw EmptyHeapPriorityQueue(
				"No hay más clientes por ser atendidos.");
			else {
				printf("[%d] Atendiendo a:\n",i+1);
				printn(hpq->min()->toString());
				hpq->removeMin();
			}
			printn("..........................................");
		}
	}
	catch (RuntimeException e) {throw e;}
	cont();
}
void Menu::option4() {
	clearScreen();
	printn("..............................................................................");
	printn("Opción 4: Mostrar el siguiente cliente a ser atendido.");
	printn("..............................................................................");
	if (hpq->empty())
		throw EmptyHeapPriorityQueue("La cola se encuentra vacía.");
	else
		printn("El siguiente cliente para ser atendido es: \n"+
		hpq->min()->toString());
	cont();
}
void Menu::option5() {
	clearScreen();
	printn("..............................................................................");
	printn("Opción 5: Simulación de atención de clientes");
	printn("..............................................................................");
	if (hpq->empty())
		throw EmptyHeapPriorityQueue("La cola se encuentra vacía.");
	else {
		printn("¡Atendiendo a todos los clientes!");
		int i= 0;
		try {
			while (!hpq->empty()) {
				if (hpq->min()) {
					printf("[%d] Atendiendo a:\n", ++i);
					printn(hpq->min()->toString());
					hpq->removeMin();
				}
			}
		}
		catch (RuntimeException e) {
			throw e;
		}
	}
	cont();
}

void Menu::option6() {
	clearScreen();
	printn("..............................................................................");
	printn("Opción 6: Agregar un cliente nuevo.");
	printn("..............................................................................");
	Person* person = getDataPerson();
	if (person) {
		bst->insert(person);
		printn("Se ha insertado la persona " + person->getName() + ".\n");
	}
	else
		printn("Fallo al ingresar a la persona. ");
	cont();
}
Person* Menu::getDataPerson() {
	printn("Digite el id de la persona. ");
	long long id = readLongLong();
	if (!bst->search(id)) {
		printn("Digite el nombre de la persona.    ");
		string name = read();
		printn("Digite 1 si la persona viene acompañada o 0 de lo contrario.");
		bool withChild = readBoolean();
		printn("Digite 1 si la persona esta embarazada o 0 de lo contrario.");
		bool pregnant = readBoolean();
		printn("Digite 1 si la persona es una adulta mayor o 0 de lo contrario. ");
		bool elderly = readBoolean();
		printn("Digite la categoria de la persona ya sea, 1 2 o 3.");
		int category;
		while (1) {
			category = readInt();
			if (category <= 3 and category >= 1) 
				return new Person(name, id, withChild, pregnant, elderly, category);
			else 
				printn("Digite un numero entre 1 y 3");
		}
	}else
		throw DuplicatedClient("El ID de la persona ya existe. No puede ingresar personas repetidas al sistema.");
	return nullptr;
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
