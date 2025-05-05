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

	FILE *fichDesc;
	char c;

	fichDesc = fopen("./ficheros/letras.txt", "w");
	if (fichDesc == NULL) //Comprobar si ha habido errores
	{
		printf("Error, el archivo no existe\n");
	}
		
	for(int i = 'a'; i <= 'z'; i++)
	{
		c = i;
		putc(c, fichDesc);
		putc(';', fichDesc);
	}

	for(int i = 'A'; i <= 'Z'; i++)
	{
		c = i;
		putc(c, fichDesc);
		putc(';', fichDesc);
	}

	fclose(fichDesc);

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