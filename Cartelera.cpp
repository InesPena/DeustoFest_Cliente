

#include "Cartelera.h"
#include "Concierto.h"
#include "iostream"
using namespace std;

Cartelera::Cartelera(int tam) {
	numConciertos = 0;
	conciertos = new Concierto*[tam];
}

Cartelera::~Cartelera() {
	// TODO Auto-generated destructor stub
}

void Cartelera::mostrarCartelera(){
	int i;
	for(i=0;i<numConciertos;i++){
		cout<<"Dia: "<<conciertos[i]->dia<<" "<<conciertos[i]->artista<<" "<<conciertos[i]->escenario<<endl;
	}
}

void Cartelera::aniadirConcierto(Concierto *c){
	conciertos[numConciertos] = c;
	numConciertos++;

}
