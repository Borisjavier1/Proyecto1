#pragma once
#include "Libraries.h"
#include "VectorIterator.h"
#include "RuntimeException.h"
const int MAX_V = 100;
template <class T>
class Vector {
private:
	T** v;
	int v_capacity;
	int v_size;
	VectorIterator<T>* ite;
public:
	Vector(int = MAX_V);
	virtual ~Vector();
	virtual string toString();
	virtual void push_back(T* data);
	virtual void pop_back();
	virtual bool remove(T* data);
	virtual int getPosition(T* data);
	virtual bool search(T* data);
	virtual bool searchById(long long id);
	virtual void emptyVector();
	virtual T* getByIndex(int pos);
	virtual int size();
	virtual void setSize(int can);
	virtual bool empty();
	virtual void setIndex(int idx,T* info);
	virtual VectorIterator<T>* getIterator();
};

template <class T>
Vector<T>::Vector(int tam) {
	this->v_capacity = tam;
	this->v_size = 0;
	this->ite = nullptr;
	v = new T * [tam];
	for (int i = 0; i < tam; i++)
		v[i] = NULL;
}
template <class T>
VectorIterator<T>* Vector<T>::getIterator() {
	if (ite) return ite;
	return new VectorIterator<T>(v,v_size);
}
template <class T>
void Vector<T>::setIndex(int idx, T* info) {
	if (idx >= 0 && idx < v_size) {
		T* aux = v[idx];
		v[idx] = info;
		delete aux;
	}
}
template <class T>
T* Vector<T>::getByIndex(int pos) {
	if (pos >= 0 && pos < v_size)
		return v[pos];
	return nullptr;
}
template <class T>
bool Vector<T>::empty() { return !v_size; } //can == 0
template <class T>
int Vector<T>::size() { return v_size; }
template <class T>
void Vector<T>::setSize(int can) {
	this->v_size = can;
}
template <class T>
Vector<T>::~Vector() {
	for (int i = 0; i < v_size; i++)
		delete v[i];
	delete[] this->v;
}

template <class T>
string Vector<T>::toString() {
	stringstream s;
	for (int i = 0; i < v_size; i++)
		s << "[" << i + 1 << "]: " << *v[i] << "\n";
	return s.str();
}

template <class T>
void Vector<T>::push_back(T* elemento) {
	if (v_size < v_capacity) {
		v[v_size] = elemento;
		v_size++;
	}
}
template <class T>
void Vector<T>::pop_back() {
	delete v[v_size];
	v[v_size] = nullptr;
	v_size--;
}
template <class T>
bool Vector<T>::remove(T* elemento) {
	int pos = search(elemento);
	if (pos == -1) return false;
	T* aux = v[pos];
	for (int i = pos; i < v_size; i++) v[i] = v[i + 1];//Corrimiento
	delete aux;
	v[v_size] = nullptr;//El final queda apuntando a NULL
	v_size--;

	return true;
}

template <class T>
bool Vector<T>::search(T* elemento) {//Búsqueda lineal, se debe arreglar para reducir el tiempo O(n)
	if (!v_size) return false;
	if (*v[0] == *elemento) return 0;
	for (int i = 0; i < v_size; i++)
		if (*elemento == *(v[i]))
			return true;
	return false;
}
template <class T>
bool Vector<T>::searchById(long long id) {//Búsqueda lineal, se debe arreglar para reducir el tiempo O(n)
	if (!v_size) return false;
	for (int i = 0; i < v_size; i++)
		if (id == (v[i]->getId()))
			return true;
	return false;
}
template <class T>
int Vector<T>::getPosition(T* elemento) {//Búsqueda lineal, se debe arreglar para reducir el tiempo O(n)
	if (!v_size) return -1;
	if (v_size == 1) if (v[0] == elemento) return 0;
	for (int i = 0; i < v_size; i++)
		if (*elemento == *v[i])
			return i;
	return -1;
}
template <class T>
void Vector<T>::emptyVector() {
	for (int i = 0; i < v_size; i++)
		delete v[i];
	v_size = 0;
}