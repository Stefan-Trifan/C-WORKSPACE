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

#define TAM_BLOQUE 10

// Funciones del programa
char* leeLineaDinamica();

// Funciones auxiliares
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");

    char* nombreapellido;

    printf("Introduce el nombre y apellido\n-> ");
    nombreapellido = leeLineaDinamica();

    printf("\nNombre es: %s\n", nombreapellido);

	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa
char* leeLineaDinamica () {
    char* cadena = (char*) malloc(sizeof(char) * TAM_BLOQUE);
    int i = 0;
    int tam_bloque = TAM_BLOQUE;
    char newchar;

    while((newchar = getchar()) != '\n') {
        cadena[i] = newchar;
        i++;
        if(i == tam_bloque) {
            tam_bloque += TAM_BLOQUE;
            cadena = (char*) realloc(cadena, tam_bloque * sizeof(char));
            // tam_bloque += tam_bloque + TAM_BLOQUE;
        }
    }

    cadena[i] = '\0';
    return cadena;
}

// Funciones auxiliares
void clearBuffer()
{
	while (getchar() != '\n');
}