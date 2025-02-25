/*
	*	Autor
		Stefan Trifan

	*   Estado

	* 	Enunciado X
		LoremIpsum
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#define TAM 5
// Funciones del programa

// Funciones auxiliares
pedirCadena(char *texto, int tam);
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");

	char texto[TAM];
    
    printf("Introduce una cadena: ");
	pedirCadena(texto, TAM);
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa

// Funciones auxiliares
pedirCadena(char *texto, int tam)
{
	
}

void clearBuffer()
{
	while (getchar() != '\n');
}