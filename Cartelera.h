

#ifndef CARTELERA_H_
#define CARTELERA_H_
#include "Concierto.h"
class Cartelera {
public:
	int numConciertos;
	Concierto **conciertos;
	Cartelera(int tam);
	virtual ~Cartelera();
	void mostrarCartelera();
	void aniadirConcierto(Concierto *c);
};

#endif /* CARTELERA_H_ */
