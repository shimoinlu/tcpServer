#pragma once

#include <iostream>

#include "AVLTree.h" 
#include "User.h"

#define FILENAME "file.txt"
class ManageUsersData
{
public:
	ManageUsersData():
		usersTree(FILENAME) {};
	void isExsistUserAndPAsswordIsCorrect(string username, string password);
private:
	AVLTree<User> usersTree;
};

