// Day started: Dec/3/2023
// Genre Binary Search Tree header file
// Eric Roquel Correa
// S01468715

#include "GBSTNode.h"
using namespace std;

// Class representing a Binary Search Tree (BST)
template <class T>
class GBSTree {

public:
	GBSTree();																									// Default constructor		
	~GBSTree();																									// Destructor
	void insert(T val);																							// Insert a node with a given value
	bool remove(T val);																							// Remove a node with a given value
	GBSTNode<T>* search(T val);																					// Search for a node with a given value
	bool isEmpty();																								// Check if the tree is empty
	void printInOrder();																						// Print the tree in in-order traversal
	void printPreOrder();																						// Print the tree in pre-order traversal
	void printPostOrder();																						// Print the tree in post-order traversal

private:
	GBSTNode<T>* root;																							// Pointer to the root of the tree
	void visitInOrder(GBSTNode<T>* node);																		// Helper function for in-order traversal
	void visitPreOrder(GBSTNode<T>* node);																		// Helper function for pre-order traversal
	void visitPostOrder(GBSTNode<T>* node);																		// Helper function for post-order traversal
	void removePostOrder(GBSTNode<T>* node);																	// Helper function to remove nodes in post-order
	GBSTNode<T>* recursiveSearch(GBSTNode<T>* node, T val);														// Helper function for recursive search
	bool recursiveSearchForRemove(GBSTNode<T>* node, T val);													// Helper function for recursive search for removal
	GBSTNode<T>* findLowest(GBSTNode<T>* node);																	// Helper function to find the lowest node
};

// Default constructor
template <class T>
GBSTree<T>::GBSTree()
{
	root = 0;
}

// Destructor
template <class T>
GBSTree<T>::~GBSTree()
{
	removePostOrder(root);
}

// Helper function to remove nodes in post-order
template <class T>
void GBSTree<T>::removePostOrder(GBSTNode<T>* node)
{
	if (node != 0) {
		removePostOrder(node->getLeft());
		removePostOrder(node->getRight());
		delete node;
	}
}

// Search for a node with a given value
template <class T>
GBSTNode<T>* GBSTree<T>::search(T val)
{
	return recursiveSearch(root, val);
}

// Helper function for recursive search
template <class T>
GBSTNode<T>* GBSTree<T>::recursiveSearch(GBSTNode<T>* node, T val)
{
	GBSTNode<T>* res;
	res = 0;
	if (node != 0)
	{
		if (val == node->getInfo())
			res = node;
		else if (val < node->getInfo())
			res = recursiveSearch(node->getLeft(), val);
		else 
			res = recursiveSearch(node->getRight(), val);
	}
	return res;
}

// Helper function for recursive search for removal
template <class T>
bool GBSTree<T>::recursiveSearchForRemove(GBSTNode<T>* node, T val)
{
	bool res;
	res = false;
	GBSTNode<T>* tmp, * found;
	if ((node->getLeft() != 0) && (val < node->getInfo())) {													// Check if the left child is non-null and the value is less than the current node's value
		if (node->getLeft()->getInfo() == val)																	// If the left child has the value to be removed
		{
			found = node->getLeft();
			if (found->getRight() == 0) {																		// If the found node has no right child
				node->setLeft(found->getLeft());																// Set the left child of the current node to the left child of the node being removed
			}
			else {																								// If the found node has a right child
				tmp = findLowest(found->getRight());															// Find the node with the lowest value in the right subtree of the node being removed
				node->setLeft(tmp);																				// Set the left child of the current node to the node identified as the lowest node in the right subtree
			}
			res = true;
		}
		else																									// Continue searching for the value in the left subtree
			res = recursiveSearchForRemove(node->getLeft(), val);
	}
	else if ((node->getRight() != 0) && (val > node->getInfo()))												// Check if the right child is non-null and the value is greater than the current node's value
	{
		if (node->getRight()->getInfo() == val) {																// If the right child has the value to be removed
			found = node->getRight();																			// Assign the right child of the current node to the variable 'found'
			if (found->getRight() == 0)																			// If the found node has no right child
				node->setRight(found->getLeft());																// Set the right child of the current node to the left subtree of the node to be deleted
			else {																								// If the found node has a right child
				tmp = findLowest(found->getRight());															// Find the lowest (leftmost) node in the right subtree of the node to be deleted
				node->setRight(tmp);																			// Set the right child of the current node to the successor node
			}
			res = true;
		}
		else																									// Continue searching for the value in the right subtree
			res = recursiveSearchForRemove(node->getRight(), val);
	}
	return res;
}

// Helper function to find the lowest node
template <class T>
GBSTNode<T>* GBSTree<T>::findLowest(GBSTNode<T>* node)
{
	GBSTNode<T>* tmp;
	if (node->getLeft() == 0) {
		tmp = node;
	}
	else { 
		while (node->getLeft()->getLeft() != 0)
			node = node->getLeft();
		tmp = node->getLeft();
		node->setLeft(tmp->getRight());
	}
	return tmp;
}

// Print the tree in in-order traversal
template <class T>
void GBSTree<T>::printInOrder()
{
	cout << "Genre List: " << endl;
	visitInOrder(root);
}

// Helper function for in-order traversal
template <class T>
void GBSTree<T>::visitInOrder(GBSTNode<T>* node)
{
	if (node != 0) {
		visitInOrder(node->getLeft());
		cout << "[" << node->getInfo().getGenre() << "]"<<endl;
		visitInOrder(node->getRight());
	}
}

// Print the tree in pre-order traversal
template <class T>
void GBSTree<T>::printPreOrder()
{
	visitPreOrder(root);
}

// Helper function for pre-order traversal
template <class T>
void GBSTree<T>::visitPreOrder(GBSTNode<T>* node)
{
	if (node != 0) {
		cout << "-" << node->getInfo() << "-";
		visitPreOrder(node->getLeft());
		visitPreOrder(node->getRight());
	}
}

// Print the tree in post-order traversal
template <class T>
void GBSTree<T>::printPostOrder()
{
	visitPostOrder(root);
}

// Helper function for post-order traversa
template <class T>
void GBSTree<T>::visitPostOrder(GBSTNode<T>* node)
{
	if (node != 0) {
		visitPostOrder(node->getLeft());
		visitPostOrder(node->getRight());
		cout << "-" << node->getInfo() << "-";
	}
}

// Remove a node with a given value
template <class T>
bool GBSTree<T>::remove(T val)
{
	bool res = false;
	if (root != 0)																								// Check if the root node contains the value to be removed
	{
		if (root->getInfo() == val) {																			// If root has no children
			if ((root->getLeft() == 0) && (root->getRight() == 0)) {
				delete root;
				root = 0;
			}
			else {
				GBSTNode<T>* tmp;
				tmp = root;
				if (root->getLeft() == 0)																		// If root has only a right child
					root = root->getRight();			
				else if (root->getRight() == 0)																	// If root has only a left child
					root = root->getLeft();
				else {																							// If root has both left and right children
					GBSTNode<T>* lowest;
					lowest = findLowest(root->getRight());

					if (root->getRight() == lowest) {															// If root's right child is the lowest
						lowest->setLeft(root->getLeft());
						root = lowest;
					}
					else {																						// Else Set root to the lowest and adjust connections
						root = lowest;
						root->setLeft(tmp->getLeft());
						root->setRight(tmp->getRight());
					}
				}	delete tmp;
			}	res = true;
		}
		else																									// If the value is not in the root, perform a recursive search for removal
			res = recursiveSearchForRemove(root, val);
	}	return res;
}

// Insert a node with a given value
template <class T>
void GBSTree<T>::insert(T val) {
	if (root == 0) {																							// If the tree is empty, create a new node as the root
		root = new GBSTNode<T>(0, val, 0);
	}
	else {
		GBSTNode<T>* tmp, * sroot;
		tmp = root;
		sroot = 0;

		while (tmp != 0) {																						// Searches the tree to find the appropriate position for insertion
			sroot = tmp;
			if (val < sroot->getInfo())																			// Move to the left subtree if the value is less than the current node's value
				tmp = tmp->getLeft();																			// Move to the left subtree 
			else																								// Move to the right subtree if the value is greater than or equal to the current node's value
				tmp = tmp->getRight();																			// Move to the right subtree
		}

		if (val < sroot->getInfo())																				// Insert a new node to the left or right of the last non-null node based on the comparison with the value
			sroot->setLeft(new GBSTNode<T>(0, val, 0));
		else
			sroot->setRight(new GBSTNode<T>(0, val, 0));
	}
}

