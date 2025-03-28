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
	char textoDestino[12];

	// Creamos el fichero
	fileDescriptor = fopen("./textos/letras.txt", "w");

	// Comprobamos si tiene extio
	if(fileDescriptor == NULL)
	{
		printf("Error al abrir el archivo\n");
		return EXIT_FAILURE;
	}

	// Escribimos en el archivo
	fputs("hola mundo", fileDescriptor);

	// Cerramos el archivo
	fclose(fileDescriptor);

	// Leemos el contenido del archivo
	fileDescriptor = fopen("./textos/letras.txt", "r");
	fgets(textoDestino, 12, fileDescriptor);

	// Imprimimos el contenido por pantalla
	printf("En el archivo pone: %s", textoDestino);

	printf("\n\033[1;32m_________________________________________EXIT_SUCCESS\033[0m\n\n");
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