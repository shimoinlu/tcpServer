#include <iostream>
#include <cstring>
#include "AVLTree.h" 
#include "User.h"
#include <string>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <map>
#include <sstream>


#pragma comment(lib, "Ws2_32.lib")

#define PORT "8080"

using namespace std;

int main() {
    AVLTree<User> allUsers("file.txt");
    WSADATA wsaData;
    int iResult;

    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        std::cerr << "WSAStartup failed: " << iResult << std::endl;
        return 1;
    }

    struct addrinfo* result = NULL, hints;

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;       // IPv4
    hints.ai_socktype = SOCK_STREAM; // TCP socket
    hints.ai_protocol = IPPROTO_TCP; // TCP protocol
    hints.ai_flags = AI_PASSIVE;     // Bind to the IP address of the local host

    // Resolve the local address and port to be used by the server
    iResult = getaddrinfo(NULL, PORT, &hints, &result);
    if (iResult != 0) {
        std::cerr << "getaddrinfo failed: " << iResult << std::endl;
        WSACleanup();
        return 1;
    }

    // Create a socket for connecting to the client
    SOCKET ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (ListenSocket == INVALID_SOCKET) {
        std::cerr << "Error at socket(): " << WSAGetLastError() << std::endl;
        freeaddrinfo(result);
        WSACleanup();
        return 1;
    }

    // Setup the TCP listening socket
    iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        std::cerr << "bind failed: " << WSAGetLastError() << std::endl;
        freeaddrinfo(result);
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    freeaddrinfo(result);

    // Listen on the socket
    iResult = listen(ListenSocket, SOMAXCONN);
    if (iResult == SOCKET_ERROR) {
        std::cerr << "Listen failed: " << WSAGetLastError() << std::endl;
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    std::cout << "Waiting for client to connect..." << std::endl;

    // Accept a client socket
    SOCKET ClientSocket;
    while (1)
    {
        cout << "#########################\n";

         ClientSocket = accept(ListenSocket, NULL, NULL);
        if (ClientSocket == INVALID_SOCKET) {
            std::cerr << "accept failed: " << WSAGetLastError() << std::endl;
            closesocket(ListenSocket);
            WSACleanup();
            return 1;
        }

        std::cout << "Client connected." << std::endl;

        // Receive data from the client
        char recvbuf[512];
        int recvbuflen = 512;

        iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
        if (iResult > 0) {
            std::string request(recvbuf, iResult);

            // Parse HTTP Request
            std::istringstream requestStream(request);
            std::string method;
            std::string path;
            std::string httpVersion;

            // Parse the request line
            requestStream >> method >> path >> httpVersion;
            std::string headerLine;
            std::map<std::string, std::string> headers;
            while (std::getline(requestStream, headerLine) && headerLine != "\r\n") {
                size_t pos = headerLine.find(": ");
                if (pos != std::string::npos) {
                    std::string headerName = headerLine.substr(0, pos);
                    std::string headerValue = headerLine.substr(pos + 2);
                    headers[headerName] = headerValue.substr(0, headerValue.length() - 1);
                }
            }
            auto u = allUsers.findNode(User{ headers["Username"],headers["Password"] });
            if (u == nullptr)
                cout << headers["Username"] << " is not exist" << endl;
            else if (u->val.validatePassword(headers["Password"]))
                cout << headers["Username"] << " is exist and password is correct" << endl;
            else
                cout << headers["Username"] << " is exist and password is incorrect" << endl;



            for (auto k : headers)
                cout << k.first << " " << k.second << endl;
            // Print request details
        }
        else if (iResult == 0) {
            std::cout << "Connection closing..." << std::endl;
        }
        else {
            std::cerr << "recv failed: " << WSAGetLastError() << std::endl;
        }
    }
    // Shutdown the connection for sending since no more data will be sent
    iResult = shutdown(ClientSocket, SD_SEND);
    if (iResult == SOCKET_ERROR) {
        std::cerr << "shutdown failed: " << WSAGetLastError() << std::endl;
    }

    // Cleanup
    closesocket(ClientSocket);
    closesocket(ListenSocket);
    WSACleanup();

    return 0;
}
//vector<User> vc;

//for (int i = 0; i < 6; ++i) {
//	const string un =  std::to_string(i);
//	const string pas =  std::to_string(i*100);
//	User u = { un +" " + pas};
//	vc.push_back(u);
//}
//for (auto& u : vc)
//	UsersTree.insertToTree(u);
//AVLTree<User> a;
//Node<int>* result;
//for (int i =0; i < 10;++i)
//	a.insertToTree(i);
