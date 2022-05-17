#include "sockets/sockets.h"

#include <stdio.h>
#include <winsock2.h>
#include <iostream>
#include <string.h>

using namespace std;

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

void comCompra()
{
	char infoCompra[10];
	int idex = 0;

	int pEnt;
	int opBus, opCamp;
	int bus = 0, camp = 0;
	int dni, nom, email;

	int opEnt = menuEntrada();
	if (opEnt == 1) pEnt = 75;
	if (opEnt == 2) pEnt = 80;
	if (opEnt == 3) pEnt = 142;

	cout << "¿Desa reservar una plaza de camping? (s/n) "; cin >> opCamp;

	cout << "¿Desa reservar una plaza de autobus? (s/n) "; cin >> opBus;


	cout << endl << "Introduza sus datos personales.. " << endl;
	cout << "DNI: "; cin >> dni;
	cout << "Nombre: "; cin >> nom;
	cout << "E-mail_ "; cin >> email;
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
				comCompra();
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
	cerrarConexion(s);
}
