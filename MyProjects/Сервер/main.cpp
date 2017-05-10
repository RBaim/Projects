#pragma comment(lib, "Ws2_32.lib")
#include <WinSock2.h>
#include <iostream>
#include <WS2tcpip.h>

SOCKET Connect;
SOCKET *connections;
SOCKET Listen;

int ClienCount = 0;

void SendMessageToClient(int ID)
{
	char *buffer = new char[1024];
	for (;; Sleep(75))
	{
		memset(buffer, 0, sizeof(buffer));
		if (recv(connections[ID], buffer, 1024, NULL))
		{
			printf(buffer);
			printf("\n");
			for (int i = 0; i <= ClienCount; i++)
			{
				send(connections[i], buffer, strlen(buffer), NULL);
			}
		}
	}
	delete buffer;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	char port[10];
	WSAData data;
	WORD version = MAKEWORD(2, 2);
	int res = WSAStartup(version, &data);
	if (res != 0)
	{
		return 0;
	}
	struct addrinfo hints;
	struct addrinfo *result;
	connections = (SOCKET*)calloc(64, sizeof(SOCKET));
	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_flags = AI_PASSIVE;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	printf("¬ведите порт сервера\n");
	std::cin >> port;
	getaddrinfo(NULL, port, &hints, &result);
	Listen = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	bind(Listen, result->ai_addr, result->ai_addrlen);
	listen(Listen, SOMAXCONN);
	freeaddrinfo(result);
	printf("Server started\r");
	char m_connect[] = "Connected";
	for (;; Sleep(75))
	{
		if (Connect = accept(Listen, NULL, NULL))
		{
			printf("Client connection: %s\n");
			connections[ClienCount] = Connect;
			send(connections[ClienCount], m_connect, strlen(m_connect), NULL);
			ClienCount++;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)SendMessageToClient, (LPVOID)(ClienCount - 1), NULL, NULL);
		}
	}
	return 1;
}