#pragma once
#include "Libraries.h"
#include "vector.h"
#include<algorithm>
template <typename T>
class HeapPriorityQueue
{
private:
    T vector[150];
    int capacity;
    int size;
public:
    HeapPriorityQueue();
    ~HeapPriorityQueue();
    void insert(T info);
    void shiftUp(int index);
    void shiftDown(int index);
    T getElement(int index);
    T extractMax();
    int getSize();
    T getMax();
    int parent(int index);
    int rightChild(int index);
    int leftChild(int index);
    string toString();
   
};


template<typename T>
inline T HeapPriorityQueue<T>::getElement(int index)
{
    return vector[index];
}

template<typename T>
void HeapPriorityQueue<T>::shiftUp(int index) {
    while (index > 0 && vector[parent(index)] < vector[index]) {
        swap(vector[parent(index)], vector[index]);
        index = parent(index);
    }
}

template<typename T>
void HeapPriorityQueue<T>::shiftDown(int index) {
    int maxIndex = index;
    int right = rightChild(index);
    int left = leftChild(index);

    if (right <= size && vector[right] > vector[maxIndex]) {maxIndex = right;}
    if (left <= size && vector[left] > vector[maxIndex]) {maxIndex = left;}
    if (index != maxIndex) {
        swap(vector[index], vector[maxIndex]);
        shiftDown(maxIndex);
    }
}

template<typename T>
inline HeapPriorityQueue<T>::HeapPriorityQueue()
{
    size = 0;
    capacity = 100;
}

template<typename T>
inline HeapPriorityQueue<T>::~HeapPriorityQueue()
{
    if (this->size > 0)
        delete[] vector;
}

template <typename T>
void HeapPriorityQueue<T>::insert(T item)
{
    T aux;
    vector[size] = item;
    shiftUp(size);
    size++;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (vector[j] < vector[j + 1]) {
                aux = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = aux;
            }
        }
    }
}

template <typename T>
T HeapPriorityQueue<T>::extractMax() {
    T max = vector[0];

    for (int i = 0; i < this->size; i++){
        vector[i] = vector[i + 1];
    }
    this->size -= 1;

    return max;
}

template<typename T>
inline int HeapPriorityQueue<T>::getSize()
{
    return this->size;
}

template<typename T>
inline T HeapPriorityQueue<T>::getMax()
{
    return vector[0];
}

template<typename T>
inline int HeapPriorityQueue<T>::parent(int index)
{
    return (index - 1) / 2;
}

template<typename T>
inline int HeapPriorityQueue<T>::leftChild(int index)
{
    return ((2 * index) + 1);
}

template<typename T>
inline string HeapPriorityQueue<T>::toString()
{
    stringstream s;
    for (int i = 0; i < size; i++)
    {
        s << vector[i]->toString();
    }
    return s.str();
}


template<typename T>
inline int HeapPriorityQueue<T>::rightChild(int index)
{
    return ((2 * index) + 2);
}

