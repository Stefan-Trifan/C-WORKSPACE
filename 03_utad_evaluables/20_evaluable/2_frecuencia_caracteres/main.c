/*
    *   Autor
        Stefan Trifan

    *   Estado

    *   Enunciado 2 - Frecuencia de caracteres
        Lorem Ipsum
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct letra_t
{
    char letra;
    int contador;
}
letra_t;

// Funciones del programa

// Funciones auxiliares
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    // Declaracion de variables

    // Comprobamos que el usuario introduce al menos un caracter

    // Contamos los caracteres repetidos
    // Ignoramos aquellos valores que sean una cadena de más de un carácter.

    // Mostramos por pantalla los caracteres repetidos y sus frecuencias

    // Liberamos memoria reservada

    printf("\n_________________________________________END\n\n");
    return EXIT_SUCCESS;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa

// Funciones auxiliares
void clearBuffer()
{
    while (getchar() != '\n');
}