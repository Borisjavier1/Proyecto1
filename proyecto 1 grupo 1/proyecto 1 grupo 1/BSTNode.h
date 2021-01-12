/*
* @author Arnoldo González Quesada, Boris Monge Chaves,Carlos Álvarez Ramírez.
* @ v1.0
* Binary Search Tree node class using templates.
*
*/
#ifndef BST_NODE_H
#define BST_NODE_H
#include "Libraries.h"
template <class T>
class BSTNode {
protected:
	T* data;
	BSTNode* left;
	BSTNode* right;
	BSTNode* parent;
public:
	BSTNode(T* = NULL, BSTNode<T>* = NULL, BSTNode<T>* = NULL, BSTNode<T>* = NULL);
	virtual ~BSTNode();
	virtual T* getData();
	virtual void setData(T*);
	virtual string toString();
	virtual BSTNode<T>* getLeft();
	virtual BSTNode<T>* getRight();
	virtual void setLeft(BSTNode<T>*);
	virtual void setRight(BSTNode<T>*);
	virtual BSTNode<T>* getParent();
	virtual void setParent(BSTNode<T>*);
	virtual bool isExternal();
	virtual bool isRoot();
};

template <class T>
BSTNode<T>::BSTNode(T* data, BSTNode<T>* left, BSTNode<T>* right, BSTNode<T>* parent) {
	this->data = data;
	this->left = left;
	this->right = right;
	this->parent = parent;
}
template <class T>
BSTNode<T>::~BSTNode() {
	delete data;
}

template <class T>
bool BSTNode<T>::isExternal() { return !left && !right; }//left== NULL and right == NULL
template <class T>
bool BSTNode<T>::isRoot() { return !parent ; }
template <class T>
T* BSTNode<T>::getData() {
	return data;
}
template <class T>
void BSTNode<T>::setData(T* data) { this->data = data; }
template <class T>
string BSTNode<T>::toString() {
	stringstream s;
	s << *(data);
	return s.str();
}
template <class T>
BSTNode<T>* BSTNode<T>::getLeft() { return left; }
template <class T>
BSTNode<T>* BSTNode<T>::getRight() { return right; }
template <class T>
void BSTNode<T>::setLeft(BSTNode<T>* left) { this->left = left; }
template <class T>
void BSTNode<T>::setRight(BSTNode<T>* right) {this->right = right;}
template <class T>
BSTNode<T>* BSTNode<T>::getParent() { return parent; }
template <class T>
void BSTNode<T>::setParent(BSTNode<T>* parent) { this->parent = parent; }
#endif