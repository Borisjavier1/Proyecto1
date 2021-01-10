#pragma once
template <class T>
class  VectorIterator {
private:
	int cur;//cursor
	int size;
	T* v;
public:
	VectorIterator(int *, int);
	virtual bool hasMore();
	virtual void getNext();
	virtual T* currenItem();
	virtual void first();
	virtual T* begin();
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
void VectorIterator<T>::getNext() {cur++;}
 template <class T>
 T* VectorIterator<T>::currenItem() {
	 if (isDone()) { 
		 return  v[cur];
	 }
	 return nullptr;
 }
 template <class T>
 void VectorIterator<T>::first() {
	 cur = 0;
 }
 template <class T>
 T* VectorIterator<T>::begin() {
	 if (size != 0) return v[0];
	 return nullptr;
 }
