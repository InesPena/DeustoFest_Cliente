#include "sockets/sockets.h"

#include <winsock2.h>

void menu();

SOCKET s;
char sendBuff[512];
char recvBuff[512];

int main(int argc, char *argv[])
{
	establecerConexion(s, sendBuff, recvBuff);
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
				strcpy(sendBuff, "COMANDO 1");
				send(s, sendBuff, sizeof(sendBuff), 0);
				break;

			case 2:
				strcpy(sendBuff, "COMANDO 2");
				send(s, sendBuff, sizeof(sendBuff), 0);
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
