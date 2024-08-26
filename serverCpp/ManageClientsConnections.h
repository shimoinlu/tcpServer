#pragma once

#include <iostream>
#include <cstring>
#include <string>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <exception>
#include "AVLTree.h" 
#include "User.h"
#include "ManageUsersData.h"
#include "DisconnectedException.h"


#pragma comment(lib, "Ws2_32.lib")


class ManageClientsConnections
{
public:

	static std::set< std::string,std::string> dataConnection;
	ManageClientsConnections();
	void HandleConnectionRequest(void* clientSocket);
private:
	ManageUsersData* mud;
	string getValueFromRequest(string request, string key);
	void RetHttpOk(SOCKET& cs, std::string message);
	void RetErrorHttpRespone(SOCKET& cs, std::string message);
};

