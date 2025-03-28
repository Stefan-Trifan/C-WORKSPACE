/*
	*	Autor
		Stefan Trifan

	* 	Compilar
		mac     : comp (compilar)
				  run  (ejecutar)
				  brun (compilar y ejecutar)
		windows : gcc main.c -o main.exe
				: ./main.exe

	*   Estado: 

	* 	Enunciado
		LoremIpsum
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#define TARIFA1 "Premium"    // De 1000 a 1500
#define TARIFA2 "Intermedia" // De 500 a 999
#define TARIFA3 "Basica"     // De 100 a 499
 
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");

	float presupuesto = 0;
	int esFlotante = 0;
    
	do{
		printf("Cuanto estas dispuesto a pagar: ");
		esFlotante = scanf("%f", &presupuesto); // Comprobamos si introduce un numero valido
		// Si no introdice un numero valido, limpiamos buffer

		if(!esFlotante){
			printf("Entrada no valida. Por favor, introduce un numero.\n");
			clearBuffer();
			presupuesto = 0;
		}

	} while ( presupuesto < 100 || presupuesto > 1500);

	if(presupuesto >= 1000 && presupuesto <= 1500){
		printf("Has elegido la tarifa %s", TARIFA1);
	}
	if(presupuesto >= 500 && presupuesto <= 999){
		printf("Has elegido la tarifa %s", TARIFA2);
	}
	if(presupuesto >= 100 && presupuesto <= 499){
		printf("Has elegido la tarifa %s", TARIFA3);
	}

    
	printf("\n\033[1;32m_________________________________________EXIT_SUCCESS\033[0m\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}