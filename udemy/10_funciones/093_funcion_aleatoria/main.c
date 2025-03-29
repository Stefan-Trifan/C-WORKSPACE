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

/* 
	srand(time(NULL))
	variable = limiteInferior + rand()%((limiteSuperior + 1) - limiteInferior))
 */

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void funcionAleatoria();
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");
	
	funcionAleatoria();
    
	printf("\n_________________________________________EXIT\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void funcionAleatoria()
{
	int numRandom = 0, min = 1, max = 10000;

	srand(time(NULL));
	numRandom = min + rand() % (max - min +1);

	printf("%d", numRandom);
}

void clearBuffer()
{
	while (getchar() != '\n');
}

