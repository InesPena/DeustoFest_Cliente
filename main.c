
void menuCliente()
{
	int op;

	Entrada *pEnt;
	Entrada ent;
	pEnt = &ent;

	Cliente *pCl;
	Cliente cl;
	pCl = &cl;

	do {
		obtenerCartelera(db, pCart);

		printf("\n\n\tCLIENTE\n");
		printf("--------------------------------\n\n");
		printf("1. Consultar Cartelera\n");
		printf("2. Comprar Entradas\n");
		printf("3. Volver atrás\n");

		op = elegirOpcion();

		switch (op) {

			case 1:
				imprimirCartelera(db, pCart, 1);
				break;

			case 2:
				if(lEntradas.numEntradas < MAX_ENTRADAS) {
					compraEntradas(pEnt, pCl);
					insertCliente(db,pCl);
					insertEntrada(db, pEnt);

				} else {
					printf("\nLo sentimos. No quedan entradas disponibles");
				}

				break;

			case 3:
				free(pEnt);
				free(pCl->nombre);
				free(pCl->mail);
				free(pCl);
				break;

			default:
				printf("\n¡ERROR! La opción seleccionada no existe\n");
				break;
		}

	} while (op != 3);
}




int elegirOpcion()
{
	int op;

	printf("\nOpción: ");
	fflush(stdout);
	scanf("%i", &op);
	getchar();

	return op;
}
