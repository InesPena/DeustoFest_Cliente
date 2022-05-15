#include <winsock2.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 6000

void menu();

SOCKET s;
char sendBuff[512];
char recvBuff[512];

int main(int argc, char *argv[])
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

	/*
	 * CREAR SOCKET
	 */

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

	/*
	 * CONECTAR AL SERVIDOR
	 */

	if (connect(s, (struct sockaddr*) &server, sizeof(server)) == SOCKET_ERROR)
	{
		cout << "Connection error: " << WSAGetLastError();
		closesocket(s);
		WSACleanup();
		return -1;
	}
	cout << "Connection stablished with: " <<  inet_ntoa(server.sin_addr) << " (" <<  ntohs(server.sin_port) << ")";

	/*
	 * ENVIAR Y RECIBIR
	 */



}


void menu()
{
	int op;

	do {

		cout << "DEUSTOFEST" << endl;
		cout << "------------------------------" << endl << endl;
		cout << "1. Consultar Cartelera" << endl;
		cout << "2. Comprar Entrada" << endl;
		cout << "3. Devolver Entrada" << endl;
		cout << "4. Salir" << endl;


		op = elegirOpcion();

		switch (op) {

			case 1:
				break;

			case 2:
				break;

			case 3:
				break;

			default:
				cout << endl << "ERROR! La opción seleccionada no existe" << enld;
				break;
		}

	} while (op != 4);
}

int elegirOpcion()
{
	int op;
	cout << endl << "Opción";
	cin >> op;
	return op;
}
