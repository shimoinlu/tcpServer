#pragma once

#include <iostream>
#include <cstring>
#include <string>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <map>
#include <sstream>
#include <exception>
#include "AVLTree.h" 
#include "User.h"
#include "ManageUsersData.h"
#pragma comment(lib, "Ws2_32.lib")
typedef struct {
	SOCKET& s;
	string username;
}socket2User;
enum TypeRequest
{
	LOGIN,EXIT,SEND_MESSAGE,RECIVE_MESSAGES
};

class ManageClientsConnections
{
public:
	ManageClientsConnections() :mud() {};
	void HandleConnectionRequest(void* clientSocket);
	
private:
	void RunThredForClient(const socket2User& s2u);
	ManageUsersData mud;
	TypeRequest indicateRequest(string request);
	string getValueFromRequest(string request, string key);
	void RetHttpOk(SOCKET& cs, std::string message);
	void RetErrorHttpRespone(SOCKET& cs, std::string message);
};

