#include "TCPServer.h"

TCPServer::TCPServer()
    :mcc()
{
    WSADATA wsaData;
    int iResult;

    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        std::cerr << "WSAStartup failed: " << iResult << std::endl;
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
    }

    // Create a socket for connecting to the client
    listenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (listenSocket == INVALID_SOCKET) {
        std::cerr << "Error at socket(): " << WSAGetLastError() << std::endl;
        freeaddrinfo(result);
        WSACleanup();
    }

    // Setup the TCP listening socket
    iResult = bind(listenSocket, result->ai_addr, (int)result->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        std::cerr << "bind failed: " << WSAGetLastError() << std::endl;
        freeaddrinfo(result);
        closesocket(listenSocket);
        WSACleanup();
    }

    freeaddrinfo(result);

    // Listen on the socket
    iResult = listen(listenSocket, SOMAXCONN);
    if (iResult == SOCKET_ERROR) {
        std::cerr << "Listen failed: " << WSAGetLastError() << std::endl;
        closesocket(listenSocket);
        WSACleanup();
    }

    std::cout << "Waiting for client to connect..." << std::endl;

    // Accept a client socket

    std::cout << "Client connected." << std::endl;
    // Receive data from the client

}

TCPServer::~TCPServer()
{
    closesocket(listenSocket);
    WSACleanup();
}

void TCPServer::runServer()
{
    while (1)
    {
        cout << "#########################\n";
        SOCKET clientSocket;
        clientSocket = accept(listenSocket, NULL, NULL);
        if (clientSocket == INVALID_SOCKET) {
            std::cerr << "accept failed: " << WSAGetLastError() << std::endl;
            closesocket(listenSocket);
            WSACleanup();
        }
        try {
            mcc.HandleConnectionRequest(clientSocket);
            RetHttpOk(clientSocket, "connection succeeded\r\n");
        }
        catch (exception& e)
        {
            RetErrorHttpRespone(clientSocket, e.what());
            closesocket(clientSocket);
           
        }
    }
}

void TCPServer::RetHttpOk(SOCKET& cs, std::string message)
{
    std::string httpResponse =
        "HTTP/1.1 200 OK\r\n"  // Status line
        "Content-Type: text/plain\r\n"  // Content-Type header
        "Content-Length: " + std::to_string(message.length()) + "\r\n"  // Content-Length header
        "\r\n"  // End of headers
        + message;
    send(cs, httpResponse.c_str(), httpResponse.size(), 0);

}
void TCPServer::RetErrorHttpRespone(SOCKET& cs, std::string message)
{
    std::string httpResponse =
        "HTTP/1.1 487 Miss Data\r\n"  // Status line
        "Content-Type: text/plain\r\n"  // Content-Type header
        "Content-Length: " + std::to_string(message.length()) + "\r\n"  // Content-Length header
        
        "\r\n"  // End of headers
        + message;
    send(cs, httpResponse.c_str(), httpResponse.size(),0);

}
