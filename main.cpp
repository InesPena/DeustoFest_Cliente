#include "sockets/sockets.h"

#include <winsock2.h>


void menu();
void protocoloCompra();

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
				break;

			case 2:
				protocoloCompra();
				break;

			case 3:
				break;

			default:
				cout << endl << "ERROR! La opci�n seleccionada no existe" << enld;
				break;
		}

	} while (op != 4);
}

int elegirOpcion()
{
	int op;
	cout << endl << "Opci�n";
	cin >> op;
	return op;
}

int protocoloCompra()
{
	strcpy(sendBuff, "COMPRA");
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, "72106669J");
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, "INES");
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, "inespena@opendeusto.es");
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, "COMPRA-END");
	send(s, sendBuff, sizeof(sendBuff), 0);
}
