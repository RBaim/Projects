#include <WinSock2.h>
#include <WS2tcpip.h>
#include <iostream>

const int MAX_CLIENTS = 64;

SOCKET Connect;
SOCKET connections[MAX_CLIENTS];
SOCKET Listen;
SOCKADDR_IN name_conn[MAX_CLIENTS];

int ClientCount = 0;

void SendMessageToClient(int ID) {
    char *buffer = new char[1024];
    for (;; Sleep(75)) {
        for(int i = 0; i < 1024; i++) buffer[i] = 0;
        if (recv(connections[ID], buffer, 1024, 0) > 0) {
            printf(buffer);
            printf("\n");
            for (int i = 0; i <= ClientCount; i++) {
                send(connections[i], buffer, strlen(buffer), 0);
            }
        }
        else break;
    }
    printf("Client disconnected(%s)\n", inet_ntoa(name_conn[ID].sin_addr));
    for (int i = ID; i < ClientCount - 1; i++) {
        connections[i] = connections[i + 1];
        name_conn[i] = name_conn[i + 1];
    }
    ClientCount--;
    delete buffer;
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
    char m_connect[] = "Connected in server Rbaim";
    for (;;Sleep(75)) {
        int size = sizeof(name_conn[ClientCount]);
        if (Connect = accept(Listen, (SOCKADDR *)&name_conn[ClientCount], &size)) {
            printf("Client connected(%s)\n", inet_ntoa(name_conn[ClientCount].sin_addr));
            connections[ClientCount] = Connect;
            send(connections[ClientCount], m_connect, strlen(m_connect), 0);
            ClientCount++;
            CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)SendMessageToClient, (LPVOID)(ClientCount - 1), NULL, NULL);
        }
    }
}