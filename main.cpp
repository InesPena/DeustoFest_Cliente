#include "clases/cartelera/Cartelera.h"
#include "clases/concierto/Concierto.h"

#include <stdio.h>
#include <winsock2.h>
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <cstdio>

#include <iostream>
#include <fstream>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 6000
using namespace std;

#define PRECIO_CAMP 35
#define PRECIO_BUS 47

int elegirOpcion() {
	int op;
	cout << endl << "Opción: ";
	cin >> op;
	return op;
}

int menuEntrada() {
	cout << "ENTRADAS" << endl;
	cout << "------------------------------" << endl << endl;
	cout << "1. Entrada Día 22............75€" << endl;
	cout << "2. Entrada Día 23............80€" << endl;
	cout << "3. Abono completo...........142€" << endl;

	int op = elegirOpcion();
	return op;
}

int main(int argc, char *argv[]) {
	WSADATA wsaData;
	SOCKET s;
	struct sockaddr_in server;
	char sendBuff[512], recvBuff[512];
	char opcion;
	int numConciertos, i;
	Cartelera *cart;
	int opEnt;
	int pEnt;
	char opBus, opCamp;
	char dni[10], nom[20], email[50];

	cout<<"Initialising Winsock..."<<endl;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		cout<<"Failed. Error Code : "<<WSAGetLastError()<<endl;
		return -1;
	}

	cout<<"Initialised."<<endl;

//SOCKET creation
	if ((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
		cout<<"Could not create socket : "<<WSAGetLastError()<<endl;
		WSACleanup();
		return -1;
	}

	printf("Socket created.\n");

	server.sin_addr.s_addr = inet_addr(SERVER_IP); //INADDR_ANY;
	server.sin_family = AF_INET;
	server.sin_port = htons(SERVER_PORT);

//CONNECT to remote server
	if (connect(s, (struct sockaddr*) &server, sizeof(server)) == SOCKET_ERROR) {
		cout<<"Connection error: "<<WSAGetLastError()<<endl;
		closesocket(s);
		WSACleanup();
		return -1;
	}

	cout<<"Connection stablished with: "<<inet_ntoa(server.sin_addr)<<
			ntohs(server.sin_port)<<endl<<endl;

	/*EMPIEZA EL PROGRAMA DEL CLIENTE*/

	do {
		cout << "DEUSTOFEST" << endl;
		cout << "------------------------------" << endl << endl;
		cout << "1. Consultar Cartelera" << endl;
		cout << "2. Comprar Entrada" << endl;
		cout << "3. Devolver Entrada" << endl;
		cout << "4. Salir"<<endl << endl;
		cout << "Elige una opcion: ";
		cin >> opcion;
		sprintf(sendBuff, "%c", opcion);
		send(s, sendBuff, sizeof(sendBuff), 0);
		switch (opcion) {
		case '1':
			recv(s, recvBuff, sizeof(recvBuff), 0);
			sscanf(recvBuff, "%d", &numConciertos);
			cart = new Cartelera(numConciertos);
			for (i = 0; i < numConciertos; i++) {
				recv(s, recvBuff, sizeof(recvBuff), 0);
				Concierto *c = new Concierto();
				c->cod = atoi(strtok(recvBuff, ";"));
				char *arti = strtok(NULL, ";");
				c->artista = new char[strlen(arti) + 1];
				strcpy(c->artista, arti);
				c->escenario = atoi(strtok(NULL, ";"));
				c->dia = atoi(strtok(NULL, ";"));
				c->coste = atoi(strtok(NULL, ""));
				//sscanf(recvBuff, "%d %s %d %d %d", &c->cod, c->artista,	&c->escenario, &c->dia, &c->coste);
				cart->aniadirConcierto(c);
			}
			cart->mostrarCartelera();
			break;
		case '2':
			opEnt = menuEntrada();

			if (opEnt == 1)
				pEnt = 75;
			if (opEnt == 2)
				pEnt = 80;
			if (opEnt == 3)
				pEnt = 142;

			cout << "¿Desea reservar una plaza de camping? (s/n) ";
			cin >> opCamp;
			if (opCamp == 's') {
				pEnt += PRECIO_CAMP;
				sprintf(sendBuff, "1");
			} else {
				sprintf(sendBuff, "0");
			}
			send(s, sendBuff, sizeof(sendBuff), 0);

			cout << "¿Desa reservar una plaza de autobus? (s/n) ";
			cin >> opBus;
			if (opBus == 's') {
				pEnt += PRECIO_BUS;
				sprintf(sendBuff, "1");
			} else {
				sprintf(sendBuff, "0");
			}
			send(s, sendBuff, sizeof(sendBuff), 0);

			sprintf(sendBuff, "%d", pEnt);
			send(s, sendBuff, sizeof(sendBuff), 0);

			cout << endl << "Introduza sus datos personales.. " << endl;

			cout << "DNI: ";
			cin >> dni;
			sprintf(sendBuff, "%s", dni);
			send(s, sendBuff, sizeof(sendBuff), 0);

			cout << "Nombre: ";
			cin >> nom;
			sprintf(sendBuff, "%s", nom);
			send(s, sendBuff, sizeof(sendBuff), 0);

			cout << "E-mail_ ";
			cin >> email;
			sprintf(sendBuff, "%s", nom);
			send(s, sendBuff, sizeof(sendBuff), 0);
			break;
		case '3':
			cout << "DNI: ";
			cin >> dni;
			sprintf(sendBuff, "%s", dni);
			send(s, sendBuff, sizeof(sendBuff), 0); //Envia el dni introducido por teclado
			recv(s, recvBuff, sizeof(recvBuff), 0); //Recibe el mensaje de eliminacion correcta
			cout << recvBuff << endl;
			break;
		case '4':
			cout << "FIN" << endl;
			break;
		}
	} while (opcion != '4');

	/*ACABA EL PROGRAMA DEL CLIENTE*/
// CLOSING the socket and cleaning Winsock...
	closesocket(s);
	WSACleanup();

	return 0;

}
