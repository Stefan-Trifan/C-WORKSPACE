/*
	*	Autor
		Stefan Trifan

	*   Estado

	* 	Enunciado 23
		LoremIpsum
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <stdlib.h>

#define TAM 20

// Funciones del programa
char *leeLineaDinamica();

// Funciones auxiliares
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");

	char *nombre;

	printf("Introduce tu nombre\n-> ");
	nombre = leeLineaDinamica();
	printf("Nombre es: %s\n", nombre);

	free(nombre);

	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa
char *leeLineaDinamica()
{
	char *p_cadena = (char *)malloc(sizeof(char) * TAM), c;
	int i = 0;

	while((c = getchar()) != '\n')
	{
		*(p_cadena + i) = c;
		if(i >= TAM)
		{
			char* p_cadena = (char *)malloc(sizeof(char));
		}
		i++;
	}
	*(p_cadena + i) = '\0';

	return p_cadena;
}

// Funciones auxiliares
void clearBuffer()
{
	while (getchar() != '\n');
}