#pragma once

#include <iostream>
#include <cstring>
#include <string>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <map>
#include <sstream>
#include "AVLTree.h" 
#include "User.h"
#include "ManageUsersData.h"
#pragma comment(lib, "Ws2_32.lib")

class ManageClientsConnections
{
public:
	ManageClientsConnections() :mud() {};
	void HandleConnectionRequest(SOCKET& clientSocket);

private:
	ManageUsersData mud;

};

