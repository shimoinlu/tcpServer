#include <iostream>
using namespace std;
#include "AVLTree.h" 
int main()
{
	AVLTree<int> a;
	Node<int>* result;
	for (int i =0; i < 3000;++i)
		a.insertToTree(i);
	for (int i = 0; i < 3000; ++i)
	{
		if (i % 6 == 0)
			result = a.findNode(-i);
		else
			result = a.findNode(i);
		if (result == nullptr)
			cout << "NULLPTR" << endl;

		else
			cout << result->val << endl;
	}
	return 0;
}