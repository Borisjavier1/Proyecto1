#pragma once
#include "Libraries.h"
#include "Vector.h"
template<typename T>
class VectorCompleteTree {
private:
	Vector<T> v;
public:
	VectorCompleteTree() : v(1) {}
	int size() { return v.size(); }
	T left(const T& p) { return pos(2 * idx(p)); }
	T right(const T& p) { return pos(2 * idx(p) + 1); }
	T parent(const T& p) { return pos(idx(p) / 2); }
	bool hasLeft(T& p) { return 2 * idx(p) <= v.size(); }
	bool hasRight(T& p) { return 2 * idx(p) + 1 <= v.size(); }
	bool isRoot(T& p) { return idx(p) == 1; }
	T root() { return pos(1); }
	T last() { return pos(v.size()); }
	void addLast(const T& e) { v.push_back(e); }
	T smallest() {
		VectorIterator<T>* ite = v.getIterator();
		return ite->begin();
	}
	void removeLast() { v.pop_back(); }
	void swap(T& p, T& q) {
		T e = q;
		q = p;
		p = e;
	}
	string toString() {
		stringstream s;
		VectorIterator<T>* ite = v.getIterator();
		int i = 0;
		ite->first();
		while (ite->hasMore()) {
			s << "[" << ++i << "]: " << ite->currenItem() << "\n";
			ite->next();
		}
		return s.str();
	}
protected:
	T pos(int i) { return v.consult(i); }
	int idx(T info) { return v.getPosition(info); }
};