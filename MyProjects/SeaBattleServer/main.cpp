#include <WS2tcpip.h>
#include <WinSock2.h>
#include <cstdio>
#include <ctime>
#include <iostream>

const int MAX_CLIENTS = 2;

SOCKET Connect;
SOCKET connections[MAX_CLIENTS];
SOCKET Listen;
SOCKADDR_IN name_conn[MAX_CLIENTS];

int ClientCount = 0;
bool free_one = true;
bool free_two = true;
bool ch;

void SendMessageToClient(int ID) {
    x: while(ClientCount != 2) {}
    char buffer[106];
    for (int i = 0; i < 106; i++) buffer[i] = 0;
    switch(ID) {
        case 0: buffer[104] = ch; break;
        case 1: buffer[104] = !ch;
    }
    buffer[101] = 1;
    send(connections[ID], buffer, 106, 0);
    for (;; Sleep(75)) {
        if (recv(connections[ID], buffer, 106, 0) > 0) {
            if (ClientCount != 1) {
                switch (ID) {
                    case 0:
                        send(connections[1], buffer, 106, 0);
                        break;
                    case 1:
                        send(connections[0], buffer, 106, 0);
                        break;
                }
            } else goto x;
        } else break;
        for (int i = 0; i < 106; i++) buffer[i] = 0;
    }
    printf("Client disconnected(%s) %d\n", inet_ntoa(name_conn[ID].sin_addr), ID + 1);
    /*for (int i = ID; i < ClientCount - 1; i++) {
        connections[i] = connections[i + 1];
        name_conn[i] = name_conn[i + 1];
    }*/
    for(int i = 0; i < 106; i++) buffer[i] = 0;
    buffer[101] = 1;
    switch(ID) {
        case 0: free_one = true; send(connections[1], buffer, 106, 0); break;
        case 1: free_two = true; send(connections[0], buffer, 106, 0);
    }
    ClientCount--;
}

int main() {
    srand(unsigned(time(0)));
    setlocale(LC_ALL, "Russian");
    char port[10];
    WSAData data;
    WORD version = MAKEWORD(2, 2);
    int res = WSAStartup(version, &data);
    if (res != 0) {
        return 0;
    }
    struct addrinfo hints;
    struct addrinfo *result;
    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_flags = AI_PASSIVE;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    printf("Input port: ");
    std::cin >> port;
    getaddrinfo(NULL, port, &hints, &result);
    Listen = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    bind(Listen, result->ai_addr, result->ai_addrlen);
    listen(Listen, SOMAXCONN);
    freeaddrinfo(result);
    printf("Server started\n");
    int conn;
    ch = rand() % 2;
    for (;; Sleep(75)) {
        if (ClientCount < 2) {
            if (free_one) { conn = 0; }
            if (free_two && !free_one) { conn = 1; }
            int size = sizeof(name_conn[conn]);
            if (Connect = accept(Listen, (SOCKADDR *) &name_conn[conn], &size)) {
                printf("Client connected(%s) %d\n", inet_ntoa(name_conn[conn].sin_addr), conn + 1);
                connections[conn] = Connect;
                ClientCount++;
                switch(conn) {
                    case 0: free_one = false; break;
                    case 1: free_two = false;
                }
                if(ClientCount == 2) ch = rand() % 2;
                CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE) SendMessageToClient, (LPVOID) (conn), NULL,
                             NULL);
            }
        }
    }
}