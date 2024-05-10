#include <iostream>
using namespace std;

// Class representing a node in a Binary Search Tree (BST)
template <class T>
class GBSTNode
{
public:
	GBSTNode();								   // Default constructor
	GBSTNode(GBSTNode<T> *, T, GBSTNode<T> *); // Constructor with parameters
	T getInfo();							   // Get information stored in the node
	GBSTNode<T> *getLeft();					   // Get the left child node
	GBSTNode<T> *getRight();				   // Get the right child node
	void setInfo(T);						   // Set information in the node
	void setLeft(GBSTNode<T> *);			   // Set the left child node
	void setRight(GBSTNode<T> *);			   // Set the right child node

private:
	GBSTNode<T> *left;	// Pointer to the left child node
	T info;				// Data stored in the node
	GBSTNode<T> *right; // Pointer to the right child node
};

// Default constructor
template <class T>
GBSTNode<T>::GBSTNode()
{
	right = left = 0;
}

// Constructor with parameters
template <class T>
GBSTNode<T>::GBSTNode(GBSTNode<T> *l, T i, GBSTNode<T> *r)
{
	info = i;
	left = l;
	right = r;
}

// Get information stored in the node
template <class T>
T GBSTNode<T>::getInfo() { return info; }

// Get the right child node
template <class T>
GBSTNode<T> *GBSTNode<T>::getRight() { return right; }

// Get the left child node
template <class T>
GBSTNode<T> *GBSTNode<T>::getLeft() { return left; }

// Set information in the node
template <class T>
void GBSTNode<T>::setInfo(T i)
{
	info = i;
}

// Set the right child node
template <class T>
void GBSTNode<T>::setRight(GBSTNode<T> *r)
{
	right = r;
}

// Set the left child node
template <class T>
void GBSTNode<T>::setLeft(GBSTNode<T> *l)
{
	left = l;
}
