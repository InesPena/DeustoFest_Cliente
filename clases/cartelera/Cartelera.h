

#ifndef CARTELERA_H_
#define CARTELERA_H_

#include "../concierto/Concierto.h"

class Cartelera {
public:
	int numConciertos;
	Concierto **conciertos;
	Cartelera(int tam);
	virtual ~Cartelera();
	void mostrarCartelera(int cont1, int cont2);
	void aniadirConcierto(Concierto *c);
};

#endif /* CARTELERA_H_ */
