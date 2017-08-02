#pragma once

#include <WS2tcpip.h>
#include <WinSock2.h>

class MyTcpIP {
public:
    WSAData data;
    WORD version = MAKEWORD(2, 2);
    SOCKET Client;
    MyTcpIP(const char* adrserv, int port);
    ~MyTcpIP();
};
