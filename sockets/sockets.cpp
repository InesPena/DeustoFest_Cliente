#include "sockets.h"

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 6000

void establecerConexion(SOCKET comm_socket, char sendBuff[], char recvBuff[])
{
	WSADATA wsaData;
	struct sockaddr_in server;

	cout << endl << "Initialising Winsock..." << endl;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		cout << "Failed. Error Code: " << WSAGetLastError();
		return -1;
	}
	cout << "Initialised" << endl;

	/* CREAR SOCKET */

	if ((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
	{
		cout << "Could not create socket: " << WSAGetLastError());
		WSACleanup();
		return -1;
	}
	cout << "Socket crated" << endl;

	server.sin_addr.s_addr = inet_addr(SERVER_IP);
	server.sin_family = AF_INET;
	server.sin_port = htons(SERVER_PORT);

	/* CONCECTAR AL SERVIDOR */

	if (connect(s, (struct sockaddr*) &server, sizeof(server)) == SOCKET_ERROR)
	{
		cout << "Connection error: " << WSAGetLastError();
		closesocket(s);
		WSACleanup();
		return -1;
	}
	cout << "Connection stablished with: " <<  inet_ntoa(server.sin_addr) << " (" <<  ntohs(server.sin_port) << ")";
}
