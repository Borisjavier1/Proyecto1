/*
* @author Arnoldo González Quesada, Boris Monge Chaves,Carlos Álvarez Ramírez.
* @ v1.0
*  Tree abstract class that uses templates.
*
*/
#ifndef TREE_H
#define TREE_H
#include "BSTNode.h"
template<class T>
class Tree {
protected:
	int size;
	BSTNode<T>* root;
	virtual bool recursiveInsert(T*, BSTNode<T>*) = 0;
	virtual bool recursiveSearch(T*, BSTNode<T>*) = 0;
	virtual BSTNode<T>* recursiveRemove(T*, BSTNode<T>*) = 0;
public:
	virtual string toString() = 0;
	virtual BSTNode<T>* getRoot() = 0;
	virtual void setRoot(BSTNode<T>*) = 0;
	virtual int getSize() = 0;
	virtual void setSize(int) = 0;
	virtual bool insert(T*) = 0;
	virtual void remove(T*) = 0;
	virtual bool search(T*) = 0;
	virtual bool empty() = 0;
};
#endif
