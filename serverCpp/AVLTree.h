#pragma once
#include "Node.h"
#include <fstream>
#include <string>

template <typename T>
class AVLTree
{
private:
	Node<T>* root;
public:

	AVLTree();
	AVLTree(std::string fileName);

	void insertToTree(T newItem);
	Node<T>* findNode(Node<T>* root, T node);
	Node<T>* findNode(T node);
};

template<typename T>
inline AVLTree<T>::AVLTree()
	: root(nullptr)
{
}

template<typename T>
inline AVLTree<T>::AVLTree(std::string fileName)
:AVLTree()
{
	ifstream inputFile(fileName);

	// Check if the file is successfully opened 
	if (!inputFile.is_open()) {
	}

	string line; // Declare a string variable to store each 
	// line of the file 

// Read each line of the file and print it to the 
// standard output stream 
	while (getline(inputFile, line)) {
		insertToTree(line);
	}
}

template<typename T>
inline void AVLTree<T>::insertToTree(T newItem)
{
	root = insert(root, newItem);
}

template<typename T>
inline Node<T>* AVLTree<T>::findNode(Node<T>* root,T node)
{
	if (root == nullptr)
		return nullptr;
	if (root->val == node)
		return root;
	else if (node > root->val)
		return findNode(root->right,node);
	else
		return findNode(root->left, node);
}

template<typename T>
inline Node<T>* AVLTree<T>::findNode(T node)
{
	return findNode(root,node);
}
