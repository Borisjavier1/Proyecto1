#pragma once
#include "Libraries.h"
#include "VectorIterator.h"
template <class T>
class Vector{
private:
	T* data;
	int capacity;
	int quantity;
	VectorIterator<T>* ite;//iterator
	void ensureCapacity();
public:
	Vector(int capacity);
	VectorIterator<T>* getIterator();
	void push_back(T info);
	void pop_back();
	void insertPosition(T info, int position);
	void remove(int position);
	T consult(int position);
	bool contains(T info);
	int getPosition(T info);
	int size();
	void deleteData();
	string toString();
	int getSize();
	void setSize(int);
	~Vector();
	void setPosition(int i,T inf);
};
template <class T>
void Vector<T> ::setPosition(int i, T inf) {
	data[i] = inf;
}
template<class T>
VectorIterator<T>* Vector<T>::getIterator() {
	if (ite) return ite;
	return new VectorIterator<T>(data,quantity);
}
template<class T>
int Vector<T>::getSize() { return quantity; }
template<class T>
void Vector<T>::setSize(int quantity) { this->quantity = quantity; }
template<class T>
inline void Vector<T>::ensureCapacity()
{
	if (this->quantity == this->capacity)
	{
		// Se duplica la capacidad actual del arreglo.
		this->capacity = capacity * 2;
		T* newVector = new T[this->capacity];

		// Se copian los infos almacenados en el nuevo arreglo
		for (int i = 0; i < this->quantity; i++)
		{
			newVector[i] = this->data[i];
		}

		// Se elimina el arreglo anterior y se actualiza el arreglo actual
		delete[] this->data;
		this->data = newVector;
		/*
		// Se inicializan las nuevas positiones libres
		for (int i = this->quantity; i < this->capacity; i++)
		{
			this->data[i] = 0;
		}
		*/
	}
}




template<class T>
inline Vector<T>::Vector(int capacity)
{
	this->capacity = capacity;
	this->quantity = 0;
	this->data = new T[this->capacity];
	this->ite = nullptr;
	/*
	for (int i = 0; i < this->capacity; i++)
	{
		this->data[i] = 0;
	}
	*/
}

template<class T>
inline void Vector<T>::push_back(T info)
{
	ensureCapacity();
	this->data[this->quantity++] = info;
}
template<class T>
inline void Vector<T>::pop_back()
{
	quantity--;
}

template<class T>
inline void Vector<T>::insertPosition(T info, int position){
	if (position > this->quantity) return;
	ensureCapacity();
	for (int i = this->quantity - 1; i >= position; i--)
	{
		this->data[i + 1] = this->data[i];
	}
	this->data[position] = info;
	this->quantity++;
}

template<class T>
inline void Vector<T>::remove(int position)
{
	if (position >= this->quantity)
	{
		return;
	}

	if (this->data[position])
	{
		delete this->data[position];
	}

	for (int i = position; i < this->quantity - 1; i++) {
		this->data[i] = data[i + 1];
	}

	this->data[this->quantity - 1] = nullptr;
	this->quantity--;
}

template<class T>
inline T Vector<T>::consult(int position)
{
	if (position >= this->quantity)
	{
		return nullptr; 
	}

	return this->data[position];
}

template<class T>
inline bool Vector<T>::contains(T info)
{
	for (int i = 0; i < this->quantity; i++)
	{
		if (this->data[i] == info)
			return true;
	}
	return false;
}
template<class T>
inline int Vector<T>::getPosition(T info)
{
	for (int i = 0; i < this->quantity; i++)
		if (this->data[i] == info) return i;
	return -1;
}
template<class T>
inline int Vector<T>::size()
{
	return this->quantity;
}

template<class T>
inline void Vector<T>::deleteData()
{
	for (int i = 0; i < this->quantity; i++)
	{
		if (this->data[i])
		{
			delete this->data[i];
			this->data[i] = nullptr;
		}
	}

	this->quantity = 0;
}



template<class T>
inline string Vector<T>::toString()
{
	stringstream s;
	for (int i = 0; i < this->quantity; i++)
	{
		//if (this->data[i])
		//{
			s << this->data[i] << "\n";
	//	}
	}
	return s.str();
}

template<class T>
inline Vector<T>::~Vector()
{
	delete ite;
	delete[] this->data;
}
