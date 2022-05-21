#include "sockets/sockets.h"

#include <stdio.h>
#include <winsock2.h>
#include <iostream>
#include <string.h>

using namespace std;
using namespace gestores;

#define PRECIO_CAMP 35
#define PRECIO_BUS 47

SOCKET s;
char sendBuff[512];
char recvBuff[512];

int elegirOpcion()
{
	int op;
	cout << endl << "Opción";
	cin >> op;
	return op;
}

int menuEntrada()
{
	cout << "ENTRADAS" << endl;
	cout << "------------------------------" << endl << endl;
	cout << "1. Entrada Día 22............75€" << endl;
	cout << "2. Entrada Día 23............80€" << endl;
	cout << "3. Abono completo...........142€" << endl;

	int op = elegirOpcion();
	return op;
}

void envioCompra()
{
	/*
	 * ENVIAR INFORMACIÓN
	 * 	0. Camping
	 *	1. Bus
	 * 	2. Precio
	 * 	3. DNI
	 * 	4. Nombre
	 * 	5. Email
	 */

	int pEnt;
	char opBus, opCamp;
	string dni, nom, email;

	int opEnt = menuEntrada();

	if (opEnt == 1)pEnt = 75;
	if (opEnt == 2) pEnt = 80;
	if (opEnt == 3) pEnt = 142;

	cout << "¿Desa reservar una plaza de camping? (s/n) "; cin >> opCamp;
	if (strcmp(&opCamp, "s")){
		pEnt += PRECIO_CAMP;
		sprintf(sendBuff, "%c", "1");
	} else {
		sprintf(sendBuff, "%c", "0");
	}
	send(s, sendBuff, sizeof(sendBuff), 0);

	cout << "¿Desa reservar una plaza de autobus? (s/n) "; cin >> opBus;
	if (strcmp(&opBus, "s")){
		pEnt += PRECIO_BUS;
		sprintf(sendBuff, "%c", "1");
	} else {
		sprintf(sendBuff, "%c", "0");
	}
	send(s, sendBuff, sizeof(sendBuff), 0);

	sprintf(sendBuff, "%s", to_string(pEnt));
	send(s, sendBuff, sizeof(sendBuff), 0);

	cout << endl << "Introduza sus datos personales.. " << endl;

	cout << "DNI: "; cin >> dni;
	sprintf(sendBuff, "%s", dni);
	send(s, sendBuff, sizeof(sendBuff), 0);

	cout << "Nombre: "; cin >> nom;
	sprintf(sendBuff, "%s", nom);
	send(s, sendBuff, sizeof(sendBuff), 0);

	cout << "E-mail_ "; cin >> email;
	sprintf(sendBuff, "%s", nom);
	send(s, sendBuff, sizeof(sendBuff), 0);
}

void respCompra()
{
	recv(s, recvBuff, sizeof(recvBuff), 0);
	cout << recvBuff;
}

void menu()
{
	int op;
	char comando;

	do {
		sprintf(sendBuff, "%s", comando);
		send(s, sendBuff, sizeof(sendBuff), 0);

		cout << "DEUSTOFEST" << endl;
		cout << "------------------------------" << endl << endl;
		cout << "1. Consultar Cartelera" << endl;
		cout << "2. Comprar Entrada" << endl;
		cout << "3. Devolver Entrada" << endl;
		cout << "4. Salir" << endl;

		op = elegirOpcion();

		switch (op) {

			case 1:
				strcpy(&comando, "CARTELERA");
				break;

			case 2:
				strcpy(&comando, "COMPRA");
				envioCompra();
				respCompra();
				break;

			case 3:
				strcpy(&comando, "DEVOLUCION");
				break;

			default:
				cout << endl << "ERROR! La opción seleccionada no existe" << endl;
				break;
		}

	} while (op != 4);

}

int main(int argc, char *argv[])
{
	establecerConexion(s, sendBuff, recvBuff);
	menu();
	// cerrarConexion(s);
}
