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
	vct->addLast(e); // add e to heap
	T* v = vct->last(); // e’s position
	while (!vct->isRoot(v)) { // up-heap bubbling
		T* u = vct->parent(v);
		//if (!IsMore<T>(v, u)) break; // if v in order, we’re done
		if (*u <= *v) break; // if v in order, we’re done
		vct->swap(*v, *u); // . . .else swap with parent
		*v = *u;
	}
}
template<typename T> 
void HeapPriorityQueue<T>::removeMax() {
	if (empty()) throw EmptyHeapPriorityQueue("ERROR: La cola se encuentra vacía.");
	if (size() == 1) // only one node?
		vct->removeLast(); // . . .remove it
	else {
		T* u = vct->root(); // root position
		vct->swap(*u, *vct->last()); // swap last with root
		vct->removeLast(); // . . .and remove last
		while (vct->hasLeft(u)) { // down-heap bubbling
			T* v = vct->left(u);
			//if (vct.hasRight(u) && IsMore<T>((vct.right(u)), v))
			if (vct->hasRight(u) && (*vct->right(u) > *v))
				*v = *vct->right(u); // v is u’s smaller child
			//if (IsMore<T>(v, u)) { // is u out of order?
			if (*v > *u) { // is u out of order?
				vct->swap(*u, *v); // . . .then swap
				*u = *v;
			}
			else break; // else we’re done
		}
	}
}