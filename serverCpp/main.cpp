#include <iostream>
#include <cstring>
#include <string>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <map>
#include <sstream>
#include "TCPServer.h"

#pragma comment(lib, "Ws2_32.lib")


using namespace std;
int main() {
    TCPServer tcpServer;
    tcpServer.runServer();

    return 0;
}