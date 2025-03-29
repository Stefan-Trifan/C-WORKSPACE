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
	Funcion Aleatoria: 

	srand(time(NULL));
	variable  = limite_inferior + rand() % ((limite_superior + 1 ) - limite_inferior);
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <stdlib.h> // Para rand() y srand()
#include <time.h>
#define limite_inferior 1
#define limite_superior 100000

void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");

	int resultado = 0;
    
    srand(time(NULL));
	resultado  = limite_inferior + rand() % ((limite_superior + 1 ) - limite_inferior);
	
	printf("%d\n", resultado);

	printf("\n_________________________________________EXIT\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}