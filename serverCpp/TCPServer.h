#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <map>
#include <thread>
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
	ManageClientsConnections mcc;
	SOCKET listenSocket;
	void newThread(void* args);
};

