

#ifndef CONCIERTO_H_
#define CONCIERTO_H_

class Concierto {
public:
	int cod;
	char *artista;
	int escenario;
	int dia;
	int coste;
	Concierto();
	virtual ~Concierto();
};

#endif /* CONCIERTO_H_ */
