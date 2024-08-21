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
#include "ManageClientsConnections.h"

#pragma comment(lib, "Ws2_32.lib")



#define PORT "8080"

class TCPServer
{
public:
	TCPServer();
	~TCPServer();
	void runServer();
private:
	void RetHttpOk(SOCKET& cs, std::string message);
	void RetErrorHttpRespone(SOCKET& cs, std::string message);
	ManageClientsConnections mcc;
	SOCKET listenSocket;

};

