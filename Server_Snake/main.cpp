#include <WinSock2.h>
#include <WS2tcpip.h>
#include <iostream>

const int MAX_CLIENTS = 2;

SOCKET Connect;
SOCKET connections[MAX_CLIENTS];
SOCKET Listen;
SOCKADDR_IN name_conn[MAX_CLIENTS];

int ClientCount = 0;
bool free_one = true;
bool free_two = true;

void SendMessageToClient(int ID) {
    char buffer[785];
    for (;; Sleep(75)) {
        for (int i = 0; i < 785; i++) buffer[i] = 0;
        if (recv(connections[ID], buffer, 785, 0) > 0) {
            if (ClientCount != 1) {
                switch (ID) {
                    case 0:
                        send(connections[1], buffer, 785, 0);
                        break;
                    case 1:
                        send(connections[0], buffer, 785, 0);
                        break;
                }
            }
        } else break;
    }
    printf("Client disconnected(%s) %d\n", inet_ntoa(name_conn[ID].sin_addr), ID + 1);
    /*for (int i = ID; i < ClientCount - 1; i++) {
        connections[i] = connections[i + 1];
        name_conn[i] = name_conn[i + 1];
    }*/
    switch(ID) {
        case 0: free_one = true; break;
        case 1: free_two = true;
    }
    ClientCount--;
}

int main() {
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
                CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE) SendMessageToClient, (LPVOID) (conn), NULL,
                             NULL);
            }
        }
    }
}