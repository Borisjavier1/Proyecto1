#pragma once
#include "Libraries.h"
#include "Vector.h"
template<typename T>
class VectorCompleteTree {
private:
	Vector<T>* v;
public:
	VectorCompleteTree();
	virtual ~VectorCompleteTree();
	int size();
	T* left(T* p);
	T* right(T* p);
	T* parent(T* p);
	bool hasLeft(T* p);
	bool hasRight(T* p);
	bool isRoot(T* p);
	T* last();
	T* root();
	void addLast(T* t);
	Vector<T>* getVector();
	T* biggest();
	void removeLast(bool = false);//if ersMem flag is enabled, memory of the object will be erased, otherwise not.
	void swap(T& p, T& q);
	string toString();
	bool searchById(long long id);
protected:
	T* pos(int i);
	int idx(T* info);
};
template<typename T>
VectorCompleteTree<T>::VectorCompleteTree() { v = new Vector<T>(); }
template<typename T>
VectorCompleteTree<T>::~VectorCompleteTree() { delete v; }
template<typename T>
int VectorCompleteTree<T>::size() { return v->size(); }
template<typename T>
T* VectorCompleteTree<T>::left(T* p) { return pos((2 * idx(p))+1); }
template<typename T>
T* VectorCompleteTree<T>::right(T* p) { return pos((2 * idx(p))+2); }
template<typename T>
T* VectorCompleteTree<T>::parent(T* p) { return pos((idx(p)-1) / 2); }
template<typename T>
bool VectorCompleteTree<T>::hasLeft(T* p) { return (2 * idx(p)) <= v->size(); }
template<typename T>
bool VectorCompleteTree<T>::hasRight(T* p) { return (2 * idx(p)) +1 <=v->size(); }
template<typename T>
bool VectorCompleteTree<T>::isRoot(T* p) { return idx(p) == 0; }
template<typename T>
T* VectorCompleteTree<T>::root() { return pos(0); }
template<typename T>
T* VectorCompleteTree<T>::last() { return pos(v->size() - 1); }
template<typename T>
void VectorCompleteTree<T>::addLast(T* t) { v->push_back(t); }
template<typename T>
Vector<T>* VectorCompleteTree<T>::getVector() { return v; }
template<typename T>
T* VectorCompleteTree<T>::biggest() {
	VectorIterator<T>* ite = v->getIterator();
	return ite->begin();
}
template<typename T>
void VectorCompleteTree<T>::removeLast(bool ersMem) { v->pop_back(ersMem); }
template<typename T>
void VectorCompleteTree<T>::swap(T& p, T& q) {
	T e = q;
	q = p;
	p = e;
}
template<typename T>
string VectorCompleteTree<T>::toString() {
	stringstream s;
	s << v->toString();
	return s.str();
}
template<typename T>
bool VectorCompleteTree<T>::searchById(long long id) { return v->searchById(id); }
template<typename T>
T* VectorCompleteTree<T>::pos(int i) { return v->getByIndex(i); }
template<typename T>
int VectorCompleteTree<T>::idx(T* info) { return v->getPosition(info); }