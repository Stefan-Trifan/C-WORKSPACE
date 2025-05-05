/*
    *   Autor
        Stefan Trifan
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

	FILE *fd; // file descriptor
	fd = fopen("datos.txt", "r");
	if(fd == NULL)
	{
		printf("El archivo no existe. Lo creamos ahora\n");
		fd = fopen("datos.txt", "w+");
	}
	else
	{
		printf("El archivo ya existe\n");
	}
	fclose(fd);

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