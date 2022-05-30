#include "Cartelera.h"
#include "../concierto/Concierto.h"
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>

#include "iostream"
using namespace std;

Cartelera::Cartelera(int tam) {
	numConciertos = 0;
	conciertos = new Concierto*[tam];
}

Cartelera::~Cartelera() {
	// TODO Auto-generated destructor stub
}

void Cartelera::mostrarCartelera(int cont1, int cont2) {
	/*int i;
	 for (i = 0; i < numConciertos; i++) {
	 cout << "Dia: " << conciertos[i]->dia << " " << conciertos[i]->artista
	 << " " << conciertos[i]->escenario << endl;
	 }*/

	char cadena[128];

	ifstream fe("dia22.txt");
	while (!fe.eof()) {
		fe >> cadena;
		cout << cadena << endl;
	}
	fe.close();

	ifstream fe2("dia23.txt");
	while (!fe2.eof()) {
		fe2 >> cadena;
		cout << cadena << endl;
	}
	fe2.close();

}

void Cartelera::aniadirConcierto(Concierto *c) {
	conciertos[numConciertos] = c;
	numConciertos++;

}
