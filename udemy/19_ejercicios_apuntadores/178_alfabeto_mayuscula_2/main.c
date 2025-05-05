/*
    *   Autor
        Stefan Trifan
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>

// Funciones del programa

// Funciones auxiliares
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");

	char letra;
	char *pletra = &letra;

	for(letra = 'A'; letra <= 'Z'; letra++)
	{
		printf("%c ", *pletra);
	}

	for(letra = 'a'; letra <= 'z'; letra++)
	{
		printf("%c ", *pletra);
	}

	printf("\n_________________________________________EXIT\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa

// Funciones auxiliares
void clearBuffer()
{
	while (getchar() != '\n');
}