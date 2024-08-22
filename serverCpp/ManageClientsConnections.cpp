#include "ManageClientsConnections.h"
#include <thread>

void a(int e) {}

void ManageClientsConnections::HandleConnectionRequest(SOCKET & clientSocket)
{
    static int c = 0;
    c++;
    char recvbuf[512];
    int recvbuflen = 512;

    int iResult = recv(clientSocket, recvbuf, recvbuflen, 0);
    cout << "c is: " << c << " " << recvbuf << '\n';
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
        mud.isExistUserAndPasswordIsCorrect(headers["Username"], headers["Password"]);
        socket2User s2u{ clientSocket,headers["Username"] };
//        std::thread t(a, 10);
        std::thread t(&ManageClientsConnections::RunThredForClient,*this,s2u);
        t.detach();
    }
}



void ManageClientsConnections::RunThredForClient(const socket2User& s2u)
{
    cout << "from new thread\n";
    while (true)
    {
        char buf[256];
        int size = recv(s2u.s, buf,256, 0);
        if (size != 0)
        {
            int t = 0;
        }
        buf[size] = '\0';
        printf("%s", buf);
        int i = 0;

    }
}
