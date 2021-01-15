#pragma once
#include "VectorCompleteTree.h"
#include "IsMore.h"
#include "Tools.h"
template<typename T>
class HeapPriorityQueue {
protected:
	VectorCompleteTree<T>* vct; // priority queue contents
public:
	HeapPriorityQueue();
	virtual ~HeapPriorityQueue();
	int size() const; // number of elements
	bool empty() const; // is the queue empty?
	void insert(T* e); // insert element
	const T* max(); // minimum element
	void removeMax();
	VectorCompleteTree<T>* getVCT();

};
template<typename T>
HeapPriorityQueue<T>::HeapPriorityQueue() { vct = new VectorCompleteTree<T>(); }
template<typename T>
HeapPriorityQueue<T>::~HeapPriorityQueue() { delete vct; }
template<typename T>
VectorCompleteTree<T>* HeapPriorityQueue<T>::getVCT() { return vct; }
template<typename T> // number of elements
int HeapPriorityQueue<T>::size() const {
	return vct->size();
}
template<typename T> // is the queue empty?
bool HeapPriorityQueue<T>::empty() const {
	return size() == 0;
}
template<typename T> // minimum element
const T* HeapPriorityQueue<T>::max(){
	return vct->root();
}
template<typename T> // insert element
void HeapPriorityQueue<T>::insert(T* e) {
	vct->addLast(e);
	T* v = vct->last();
	while (!vct->isRoot(v)) {
		T* u = vct->parent(v);
		if (*v <= *u) break;
		vct->swap(*v, *u);
		*v = *u;
	}
}
template<typename T> // remove minimum
void HeapPriorityQueue<T>::removeMax() {
	if (empty()) throw EmptyHeapPriorityQueue("ERROR: La cola se encuentra vacía.");
	if (size() == 1) vct->removeLast();
	else {
		T* u = vct->root();
		vct->swap(*u, *vct->last());
		vct->removeLast();
		while (vct->hasLeft(u)) { 
			T* v = vct->left(u);
			if (vct->hasRight(u) && (*vct->right(u) > *v))
				*v = *vct->right(u); 
			if (*v > *u) {
				vct->swap(*u, *v);
				*u = *v;
			}else break;
		}
	}
}