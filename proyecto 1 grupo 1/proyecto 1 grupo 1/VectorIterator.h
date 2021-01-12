#pragma once
template <class T>
#include "RuntimeException.h"
class  VectorIterator {
private:
	int cur;//cursor
	int size;
	T* v;
public:
	VectorIterator(int *, int);
	virtual bool hasMore();
	virtual void next();
	virtual T currenItem();
	virtual void first();
	virtual T begin();
	virtual T end();
};
template <class T>
VectorIterator<T>::VectorIterator(int* v, int size){
	this->cur = 0;
	this->v = v;
	this->size = size;
}
template <class T>
bool VectorIterator<T>::hasMore() {
	return  cur < size;
}
template <class T>
void VectorIterator<T>::next() {cur++;}
 template <class T>
 T VectorIterator<T>::currenItem(){
	 if (hasMore())
		 return  v[cur];
	throw IndexOverflow("Index overflow exception.\n");
 }
 template <class T>
 void VectorIterator<T>::first() {
	 if (size != 0) { 
		 cur = 0; 
		 return;
	 }
	 throw EmptyVector("Empty vector exception.\n");
 }
 template <class T>
 T VectorIterator<T>::begin() {
	 if (size != 0) return v[0];
	 throw EmptyVector("Empty vector exception.\n");
 }
 template <class T>
 T VectorIterator<T>::end() {
	 if (size != 0) return v[size];
	 throw EmptyVector("Empty vector exception.\n");
 }
