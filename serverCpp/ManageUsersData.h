#pragma once

#include <iostream>

#include "AVLTree.h" 
#include "User.h"
#include "Message.h"
#define FILENAME "file.txt"
class ManageUsersData
{
public:
	ManageUsersData():
		usersTree(FILENAME) {};
	void isExistUserAndPasswordIsCorrect(string username, string password);
	bool SearchUser(string username);
	void pushMessage(string from, string username, string message);


private:
	AVLTree<User> usersTree;
};

