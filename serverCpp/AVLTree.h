#pragma once
#include "Node.h"

template <typename T>
class AVLTree
{
private:
	Node<T>* root;
public:
	AVLTree();
	void insertToTree(T newItem);
};

template<typename T>
inline AVLTree<T>::AVLTree()
	: root(nullptr)
{
}

template<typename T>
inline void AVLTree<T>::insertToTree(T newItem)
{
	root = insertToTree(root, newItem);
}
