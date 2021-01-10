/*
* @author Arnoldo González Quesada, Boris Monge Chaves,Carlos Álvarez Ramírez.
* @ v1.0
* .cpp file that contain some useful functions in order to interact with
* the program's console.
*
*/
#include "Tools.h"

string read() {
	string x;
	getline(cin, x);
	return x;
}
void print(string x) { cout << x; }
void printn(string x) { cout << x <<"\n"; }
void printnError(string x) { cerr << "ERROR: " << x << "\n"; }


int readInt() {
	while (1) {
		try {
			int x;
			cin >> x;
			return x;
		}catch (...) {
			print("Digite un numero entero.\n");
		}
	}
}
float readFloat() {
	while (1) {
		try {
			float x;
			cin >> x;
			return x;
		}
		catch (...) {
			print("Digite un numero entero.\n");
		}
	}
}

long long readLongLong() {
	long long x;
	cin >> x;
	if (x == false) {
		throw invalidData("Valores inválidos ingresados.\n");
	}
	else {
		return x;
	}
}

void cont() { //continue
	printn("Digite cualquier tecla para continuar.");
	_getch();

}
void clearScreen() {
	if (system("cls")) system("clear");
}

void programExit()
{
	exit(0);
}
