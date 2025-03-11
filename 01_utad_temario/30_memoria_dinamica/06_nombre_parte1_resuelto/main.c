/*
	*   Autor
		Stefan Trifan

	*   Estado

	*   Enunciado X
		Lorem Ipsum
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <stdlib.h>

// Funciones del programa
char* leeLineaDinamica();

// Funciones auxiliares
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");

    int tam;
    char* nombreapellido;

    printf("Introduce el nombre y apellido\n-> ");
    nombreapellido = leeLineaDinamica ();

    printf("\nNombre es: %s\n", nombreapellido);

	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa
char* leeLineaDinamica () {
    int i = 1;
    char* cadena = (char*) malloc(sizeof(char));
    int pos = 0;
    char newChar = 0;

    while((newChar = getchar()) != '\n') {
        *(cadena + pos) = newChar;
        // cadena[pos] = newChar;
        pos++;
        cadena = (char*) realloc(cadena, (pos + 1) * sizeof(char));
    }

    *(cadena + pos) = '\0';

    return cadena;
}

// Funciones auxiliares
void clearBuffer()
{
	while (getchar() != '\n');
}