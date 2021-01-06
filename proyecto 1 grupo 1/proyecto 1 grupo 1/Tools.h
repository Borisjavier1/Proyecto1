/*
* @author Arnoldo González Quesada, Boris Monge Chaves,Carlos Álvarez Ramírez.
* @ v1.0
* .h file that contain some useful functions in order to interact with
* the program's console.
*
*/
#ifndef TOOLS_H
#define TOOLS_H
#include "Libraries.h"
string read(); //Function that reads a string
void print(string x);
void printn(string x); //prints with\n 
int readInt();
float readFloat();
void cont(); //continue
void clearScreen();
#endif