/*
* @author Arnoldo González Quesada, Boris Monge Chaves,Carlos Álvarez Ramírez.
* @ v1.0
* Binary Search Tree class using templates.
*
*/
#ifndef BST_H
#define BST_H
#include "Tree.h"
#include "RuntimeException.h"
template <class T>
class BST : public Tree<T> {
private:
	int coun;
    T* recursiveSearchId(long long, BSTNode<T>*);
protected:
	int size;
	BSTNode<T>* root;
	virtual bool recursiveInsert(T*, BSTNode<T>*);
	virtual bool recursiveSearch(T*, BSTNode<T>*);
	//---------------v1.1--------------------
	virtual void recursiveMakeEmpty(BSTNode<T>*);
	virtual BSTNode<T>* recursiveRemove(T*, BSTNode<T>*);
	virtual BSTNode<T>* recursiveFindMin(BSTNode<T>*);
	virtual BSTNode<T>* recursiveFindMax(BSTNode<T>*);
public:
	T* search(long long);
	virtual string inOrder(BSTNode<T>*);
	virtual string postOrder(BSTNode<T>*);
	virtual string preOrder(BSTNode<T>*);
	BST();
	virtual ~BST();
	virtual string toString();
	virtual BSTNode<T>* getRoot();
	virtual void setRoot(BSTNode<T>*);
	virtual int getSize();
	virtual void setSize(int);
	virtual bool insert(T*);
	virtual bool search(T*);
	virtual bool empty(); //Returns true if the tree is empty
	//---------------v1.1--------------------
	virtual void makeEmpty();
	virtual T* findMin();
	virtual T* findMax();
	virtual void remove(T*);
	virtual void serializeTree(ostream& out, BSTNode<T>* cursor);
	
	 
};
template <class T>
BST<T>::BST() {
	size = 0;
    coun = 0;
	root = new BSTNode<T>();//(NULL,NULL,NULL,NULL)//empty b-tree, root's parent is always NULL
	//BTNode(T* info, BTNode<T>* left, BTNode<T>* right, BTNode<T>* parent
}
template <class T>
void BST<T>::recursiveMakeEmpty(BSTNode<T>* cursor) {
	if (cursor) {
		recursiveMakeEmpty(cursor->getLeft());
		recursiveMakeEmpty(cursor->getRight());
		delete cursor;
	}
}
template <class T>
void BST<T>::makeEmpty() {
	recursiveMakeEmpty(root);
}
template <class T>
BST<T>::~BST() {
	makeEmpty();
}
template <class T>
bool BST<T>::empty() {
	return !root->getLeft() && !root->getData();
	//left == NULL and right == NULL && data == NULL
}
template <class T>
string BST<T>::preOrder(BSTNode<T>* cursor) {//parent,left,right
	stringstream s;
	if (cursor)
		if (cursor->getData()) {
			s << cursor->toString() << " ";
			s << preOrder(cursor->getLeft());
			s << preOrder(cursor->getRight());
		}
	return s.str();
}
template <class T>
string BST<T>::postOrder(BSTNode<T>* cursor) {//left,right,parent
	stringstream s;
	if (cursor)
		if (cursor->getData()) {
			s << postOrder(cursor->getLeft());
			s << postOrder(cursor->getRight());
			s << cursor->toString()<< " ";
		}
	return s.str();
}
template <class T>
string BST<T>::inOrder(BSTNode<T>* cursor) {//left,parent,right
	stringstream s;
	if (cursor)
		if (cursor->getData()) {
			s << inOrder(cursor->getLeft());
			s << cursor->toString() << " ";
			s << inOrder(cursor->getRight());
		}
	return s.str();
}
template <class T>
string BST<T>::toString() {
	stringstream s;
	s << "Quantity of items: " << size << "\n";
	s << "Pre-order traversal(P,L,R): \n" << preOrder(root) << "\n";
	s << "Post-order traversal(L,R,P): \n" << postOrder(root) << "\n";
	s << "In-order traversal(L,P,R): \n" << inOrder(root) << "\n";
	return s.str();
}
template <class T>
BSTNode<T>* BST<T>::getRoot() { return root; }
template <class T>
void BST<T>::setRoot(BSTNode<T>* root) { this->root = root; }
template <class T>
int BST<T>::getSize() {
	return size;
}
template <class T>
void BST<T>::setSize(int size) {
	this->size = size;
}
template<class T>
inline T* BST<T>::recursiveSearchId(long long id, BSTNode<T>* cursor)
{
	if (cursor) {
		if (cursor->isExternal()) return nullptr; // If it is an external node it means that the searched item doesnt exist in the bt.
		if (cursor->getData()) {
			if (cursor->getData()->getId() == id) return cursor->getData();
			if (id > cursor->getData()->getId())
				return recursiveSearchId(id, cursor->getRight());
			if (id < cursor->getData()->getId())
				return recursiveSearchId(id, cursor->getLeft());
		}
	}
	return nullptr;
}
template<class T>
inline T* BST<T>::search(long long id)
{
	return recursiveSearchId(id, root);
}

template <class T>
bool BST<T>::recursiveInsert(T* info, BSTNode<T>* cursor) {
	//if the tree is empty()
	if (!root->getData()) { root->setData(info); size++;  return true; }
	if (cursor && info) {
		if (info < cursor->getData()) {
			if (cursor->getLeft())
				return recursiveInsert(info, cursor->getLeft());
			else {
				cursor->setLeft(new BSTNode<T>(info, NULL, NULL, cursor));
				size++;
				return true;
			}
		}
		if (info > cursor->getData()) {
			if (cursor->getRight())
				return recursiveInsert(info, cursor->getRight());
			else {
				cursor->setRight(new BSTNode<T>(info, NULL, NULL, cursor));
				size++;
				return true;
			}
		}

	}
	return false;
}
template <class T>
bool BST<T>::recursiveSearch(T* info, BSTNode<T>* cursor) {
	if (cursor) {
		if (cursor->isExternal()) return false; // If it is an external node it means that the searched item doesnt exist in the bt.
		if (cursor->getData()) {
			if (*cursor->getData() == *info) return true;
			if (*info > *cursor->getData())
				return recursiveSearch(info, cursor->getRight());
			if (*info < *cursor->getData())
				return recursiveSearch(info, cursor->getLeft());
		}
	}
	return false;
}
template <class T>
bool BST<T>::insert(T* info) {
	return recursiveInsert(info, root);
}
template <class T>
BSTNode<T>* BST<T>::recursiveFindMin(BSTNode<T>* cursor) {
	if (!cursor) return nullptr;
	else if (!cursor->getLeft()) return cursor;
	else return recursiveFindMin(cursor->getLeft());
}
template <class T>
BSTNode<T>* BST<T>::recursiveFindMax(BSTNode<T>* cursor) {
	if (!cursor) return nullptr;
	else if (!cursor->getRight()) return cursor;
	else return recursiveFindMax(cursor->getRight());
}
template <class T>T* BST<T>::findMax() { return recursiveFindMax(root)->getData(); }
template <class T>T* BST<T>::findMin() { return recursiveFindMin(root)->getData(); }
template <class T>
BSTNode<T>* BST<T>::recursiveRemove(T* info, BSTNode<T>* cursor) {
	BSTNode<T>* temp;
	if (!cursor) return nullptr;
	else if (*info < *cursor->getData())
		cursor->setLeft(recursiveRemove(info, cursor->getLeft()));
	else if (*info > *cursor->getData())
		cursor->setRight(recursiveRemove(info, cursor->getRight()));
	else if (cursor->getLeft() && cursor->getRight())
	{
		temp = recursiveFindMin(root);
		cursor->setData(temp->getData());
		cursor->setRight(recursiveRemove(cursor->getData(), cursor->getRight()));
	}
	else {
		temp = cursor;
		if (!cursor->getLeft()) cursor = cursor->getRight();
		else if (!cursor->getRight()) cursor = cursor->getLeft();
		size--;
		delete temp;
	}
	return cursor;
}
template <class T>
void BST<T>::remove(T* info) {recursiveRemove(info, root);}

template<class T>
inline void BST<T>::serializeTree(ostream& out, BSTNode<T>* cursor)
{
	if (cursor)
		if (cursor->getData()) {
			 serializeTree(out, cursor->getLeft());
			 cursor->getData()->serialize(out);
			 if (coun != size - 1)
				 out << endl;
			 coun +=1;
			 serializeTree(out, cursor->getRight());
		}
}

template <class T>
bool BST<T>::search(T* info) { return recursiveSearch(info, root); }
#endif