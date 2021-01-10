#pragma once
#include "Libraries.h"
#include "Vector.h"
template<typename E>
class VectorCompleteTree {
private:
	Vector<E> v;
public:
	typedef typename VectorIterator<E> Pos;
	VectorCompleteTree() : v(1) {}
	int size() const { return v.size() - 1; }
	Pos left(const Pos& p) { return pos(2 * idx(p)); }
	Pos right(const Pos& p) { return pos(2 * idx(p) + 1); }
	Pos parent(const Pos& p) { return pos(idx(p) / 2); }
	bool hasLeft(const Pos& p) const { return 2 * idx(p) <= v.size(); }
	bool hasRight(const Pos& p) const { return 2 * idx(p) + 1 <= v.size(); }
	bool isRoot(const Pos& p) const { return idx(p) == 1; }
	Pos root() { return pos(1); }
	Pos last() { return pos(v.size()); }
	void addLast(const E& e) { v.push_back(e); }
	E smallest() { return v[1]; }
	void removeLast() { v.pop_back(); }
	void swap(const Pos& p, const Pos& q) {
		E e = *q;
		*q = *p;
		*p = e;
	}
protected:
	Pos pos(int i) { return v.begin() + i; }
	int idx(const Pos& p) const { return p - v.begin(); }
};