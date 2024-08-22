#include "ManageClientsConnections.h"
#include <thread>

void a(int e) {}

void ManageClientsConnections::HandleConnectionRequest(void* clientSocket)
{
    cout << "i in child thread my id is: " << this_thread::get_id() << '\n';

    static int c = 0;
    c++;
    char recvbuf[512];
    int recvbuflen = 512;

    SOCKET* pClientSocket = static_cast<SOCKET*>(clientSocket);
    SOCKET ClientSocket = *pClientSocket;
    int iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
    cout << "c is: " << c << " " << recvbuf << '\n';
    if (iResult > 0) {
        std::string request(recvbuf, iResult);
        TypeRequest r = indicateRequest(getValueFromRequest(request, "TypeRequest"));
        try {
            switch (r)
            {
            case LOGIN: {
                string username = getValueFromRequest(request, "Username");
                string password = getValueFromRequest(request, "Password");
                mud.isExistUserAndPasswordIsCorrect(username, password);
                break;
            }
            case EXIT:
                break;
            case SEND_MESSAGE: {
                cout << "***********" << request << "*************" << "\n";
                string from = getValueFromRequest(request, "Username");
                string data = request.substr(request.find("recipient"));
                string recipient = data.substr(data.find_first_of("=") + 1);
                recipient = recipient.substr(0, recipient.find("&"));
                string message = data.substr(data.find_last_of("=") + 1);
                mud.pushMessage(from, recipient, message);
                break;
            }
            case RECIVE_MESSAGES:
                break;
            default:
                break;
            }
            RetHttpOk(ClientSocket, "are you connected");
        }
        catch (exception& e)
        {
            RetErrorHttpRespone(ClientSocket, e.what());
            closesocket(ClientSocket);
        }
        closesocket(ClientSocket);
        free(pClientSocket);
    }
    else {
        int e = WSAGetLastError();
            std::cout << "error is: " << e;
    }
}


TypeRequest ManageClientsConnections::indicateRequest(string request)
{
    if (request.compare("login") == 0)
        return TypeRequest::LOGIN;
    else if (request.compare("sendMessage") == 0)
        return TypeRequest::SEND_MESSAGE;
}

string ManageClientsConnections::getValueFromRequest(string request, string key)
{
    std::istringstream requestStream(request);

    // Parse the request line
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
        

    return headers[key];
}
void ManageClientsConnections::RetHttpOk(SOCKET& cs, std::string message)
{
    std::string httpResponse =
        "HTTP/1.1 200 OK\r\n"  // Status line
        "Content-Type: text/plain\r\n"  // Content-Type header
        "Content-Length: " + std::to_string(message.length()) + "\r\n"  // Content-Length header
        "\r\n"  // End of headers
        + message;
    send(cs, httpResponse.c_str(), httpResponse.size(), 0);

}
void ManageClientsConnections::RetErrorHttpRespone(SOCKET& cs, std::string message)
{
    std::string httpResponse =
        "HTTP/1.1 487 Miss Data\r\n"  // Status line
        "Content-Type: text/plain\r\n"  // Content-Type header
        "Content-Length: " + std::to_string(message.length()) + "\r\n"  // Content-Length header

        "\r\n"  // End of headers
        + message;
    send(cs, httpResponse.c_str(), httpResponse.size(), 0);

}

