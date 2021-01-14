#pragma once
#include "Libraries.h"
#include "Vector.h"
template<typename T>
class VectorCompleteTree {
private:
	Vector<T>* v;
public:
	VectorCompleteTree() {v = new Vector<T>();}
	virtual ~VectorCompleteTree() { delete v; }
	int size() { return v->size(); }
	T* left(T* p) { return pos(2 * idx(p)); }
	T* right(T* p) { return pos(2 * idx(p)); }
	T* parent(T* p) { return pos(idx(p) / 2); }
	bool hasLeft(T* p) { return 2 * idx(p) <= v->size(); }
	bool hasRight(T* p) { return 2 * idx(p) <= v->size(); }
	bool isRoot(T* p) { return idx(p) == 0; }
	T* root() { return pos(0); }
	T* last() { return pos(v->size()-1); }
	void addLast(T* t) { v->push_back(t); }
	T* smallest() {
		VectorIterator<T>* ite = v->getIterator();
		return ite->begin();
	}
	void removeLast() { v->pop_back(); }
	void swap(T& p, T& q) {
		T e = q;
		q = p;
		p = e;
	}
	string toString() {
		stringstream s;
		s << v->toString();
		return s.str();
	}
	bool searchById(long long id) {return v->searchById(id);}
protected:
	T* pos(int i) { return v->getByIndex(i); }
	int idx(T* info) { return v->getPosition(info); }
};