#pragma once

#include <iostream>

#include "AVLTree.h" 
#include "User.h"
#include "Message.h"
#define FILENAME "file.txt"

//singelton class

class ManageUsersData
{
private:
	static ManageUsersData* mud;
	static AVLTree<User> usersTree;
	ManageUsersData() {};

public:
	static ManageUsersData* getInstance();
	ManageUsersData(const ManageUsersData&) = delete;
	void isExistUserAndPasswordIsCorrect(string username, string password);
	bool SearchUser(string username);
	void pushMessage(string from, string username, string message);


};

