#pragma once

#include <WS2tcpip.h>
#include <WinSock2.h>
#include <cstdio>

class MyTcpIP {
public:
    WSAData data;
    WORD version = MAKEWORD(2, 2);
    SOCKET Client;
    MyTcpIP();
    ~MyTcpIP();
};
