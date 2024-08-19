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
	Node<T>* findNode(Node<T>* root, T node);
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

template<typename T>
inline Node<T>* AVLTree<T>::findNode(Node<T>* root,T node)
{
	if (root == nullptr)
		return nullptr;
	if (*root == node)
		return root;
	else if (node > *root)
		return findNode(root->right,node);
	else
		return findNode(root->left, node);
}
