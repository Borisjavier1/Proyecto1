#pragma once
#include "Libraries.h"
#include "Vector.h"
template <class T>
class HeapPriorityQueue {
private:
	Vector<T>* v;
    int size;
public:
    HeapPriorityQueue();
    ~HeapPriorityQueue();
    T parent(int i,int &pos);
  	void swap(T p, T q);
    T leftChild(int i, int &pos);
    T rightChild(int i, int &pos);
    void shiftUp(int i);
    void shiftDown(int i);
    void insert(T p);
    T extractMax();
    void changePriority(int i, T p);
    T getMax();
    void remove(int i);
    virtual string toString();
    int getSize();
};
template <class T>
int HeapPriorityQueue<T>::getSize() { return size; }
template <class T>
HeapPriorityQueue<T>::HeapPriorityQueue() {
    v = new Vector<T>(10);
    size = 0;
}
template <class T>
HeapPriorityQueue<T>::~HeapPriorityQueue() {
    delete v;
}
template <class T>
T HeapPriorityQueue<T>::parent(int i, int &pos) {
    pos = (i - 1) / 2;
    return v->consult((i - 1) / 2);
}
template <class T>
void HeapPriorityQueue<T>::swap(T p, T q) {
    T e = q;
    q = p;
    p = e;
}
template <class T>
T HeapPriorityQueue<T>::leftChild(int i, int& pos)
{
    pos = (2 * i) + 1;
    return v->consult(((2 * i) + 1));
}
template <class T>
T HeapPriorityQueue<T>::rightChild(int i, int& pos)
{
    pos = ((2 * i) + 2);
    return v->consult(((2 * i) + 2));
}
template <class T>
void HeapPriorityQueue<T>::shiftUp(int i)
{
    int pos;
    while (true) {
        parent(i, pos);
        if (i > 0 && v->consult(pos) < v->consult(i)) {
            // Swap parent and current node 
            parent(i, pos);
            swap(v->consult(pos), v->consult(i));
            // Update i to parent of i 
            i = pos;
        }
        else
            return;
    }
}
template <class T>
void HeapPriorityQueue<T>::shiftDown(int i)
{
    int maxIndex = i;

    // Left Child 
    T l = leftChild(i);

    if (l <= size && v->consult(l) > v->consult(maxIndex)) {
        maxIndex = l;
    }

    // Right Child 
    int r = rightChild(i);

    if (r <= size && v->consult(r) > v->consult(maxIndex)) {
        maxIndex = r;
    }

    // If i not same as maxIndex 
    if (i != maxIndex) {
        swap(v->consult(i), v->consult(maxIndex));
        shiftDown(maxIndex);
    }
}
template <class T>
void HeapPriorityQueue<T>::insert(T p)
{
    size = size + 1;
    v->push_back(p);

    // Shift Up to maintain heap property 
    shiftUp(size);
}
template <class T>
T HeapPriorityQueue<T>::extractMax() {
    T result = v->consult(0);
    v->setPosition(0, v->consult(size));
    v->setSize(v->getSize() - 1);
    shiftDown(0);
    return result;
}

// Function to change the priority 
// of an element 
template <class T>
void HeapPriorityQueue<T>::changePriority(int i, T p) {
    T oldp = v[i];
    v->setPosition(i, *p);
    if (*p > *oldp)
        shiftUp(i);
    else
        shiftDown(i);
}

// Function to get value of the current 
// maximum element 
template <class T>
T HeapPriorityQueue<T>::getMax() {
    return v->consult(0);
}
template <class T>
void HeapPriorityQueue<T>::remove(int i) {
    v->setPosition(i, *getMax());
    shiftUp(i);
    extractMax();
    size--;
}
template <class T>
string HeapPriorityQueue<T>::toString() {
    stringstream s;
    s << v->toString();
    return s.str();
}