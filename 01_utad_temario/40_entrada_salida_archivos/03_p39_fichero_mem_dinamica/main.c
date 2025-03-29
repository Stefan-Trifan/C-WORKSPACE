/*
	*   Autor
		Stefan Trifan

	*   Estado

	*   Enunciado
		Recupera una cadena de caracteres escrita en un fichero e imprímela por pantalla.
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_BLOQUE 5

// Funciones del programa
char *leeLineaDinamicaFichero(FILE *fileDescriptor);

// Funciones auxiliares
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n___________________________START\n\n");

	FILE *fileDescriptor;
	char *txtDestino = (char*)malloc(sizeof(char));

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
	txtDestino = leeLineaDinamicaFichero(fileDescriptor);

	// Imprimimos el contenido por pantalla
	printf("En el archivo pone: %s", txtDestino);

	printf("\n\033[1;32m___________________________EXIT_SUCCESS\033[0m\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa
char *leeLineaDinamicaFichero(FILE *fileDescriptor)
{
    char *txt_destino = malloc(sizeof(char) * TAM_BLOQUE);
    char c;
    int i = 0;
    int memoria_actual = TAM_BLOQUE;

    while ((c = fgetc(fileDescriptor)) != EOF)
    {
        if (i == memoria_actual)
        {
            memoria_actual += TAM_BLOQUE;
            txt_destino = realloc(txt_destino, memoria_actual * sizeof(char));
        }
        txt_destino[i] = c;
        i++;
    }
    txt_destino[i] = '\0';

    return txt_destino;
}

// Funciones auxiliares
void clearBuffer()
{
	while (getchar() != '\n');
}