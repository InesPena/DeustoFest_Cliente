#include "Cartelera.h"
#include "../concierto/Concierto.h"
#include <cstdlib>
#include <cstdio>

#include "iostream"
using namespace std;

Cartelera::Cartelera(int tam) {
	numConciertos = 0;
	conciertos = new Concierto*[tam];
}

Cartelera::~Cartelera() {
	// TODO Auto-generated destructor stub
}

void Cartelera::mostrarCartelera() {
	int i;
	for (i = 0; i < numConciertos; i++) {
		cout << "Dia: " << conciertos[i]->dia << " " << conciertos[i]->artista
				<< " " << conciertos[i]->escenario << endl;
	}

	/*ifstream archivo_entrada("dia22.txt");

	 string linea;

	 while (getline(archivo_entrada, linea))
	 {
	 cout << linea << endl;
	 }*/

}

void Cartelera::aniadirConcierto(Concierto *c) {
	conciertos[numConciertos] = c;
	numConciertos++;

}
