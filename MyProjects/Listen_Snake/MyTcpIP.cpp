#include "MyTcpIP.h"

MyTcpIP::MyTcpIP(const char* adrserv, int port) {
    WSAStartup(version, &data);
    Client = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in connect_c;
    connect_c.sin_family = AF_INET;
    connect_c.sin_port = htons(port);
    HOSTENT *hst;
    if (inet_addr(adrserv) != INADDR_NONE)
        connect_c.sin_addr.s_addr = inet_addr(adrserv);
    else {
        if (hst = gethostbyname(adrserv))
            ((unsigned long *)&connect_c.sin_addr)[0] =
                    ((unsigned long **)hst->h_addr_list)[0][0];
    }
    connect(Client, (sockaddr *)&connect_c, sizeof(connect_c));
}

MyTcpIP::~MyTcpIP() {
    closesocket(Client);
    WSACleanup();
}
