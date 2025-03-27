/*
	*   Autor
		Stefan Trifan

	*   Estado

	*   Enunciado
		Lorem Ipsum
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Funciones del programa

// Funciones auxiliares
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");

	FILE *fileDescriptor;

	fileDescriptor = fopen("./textos/letras.txt", "w");

	if(fileDescriptor != NULL)
	{
		printf("Error al abrir el archivo\n");
		return EXIT_FAILURE;
	}

	fputs("hola mundo", fileDescriptor);

	fclose(fileDescriptor);

	printf("\n_________________________________________END\n\n");
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