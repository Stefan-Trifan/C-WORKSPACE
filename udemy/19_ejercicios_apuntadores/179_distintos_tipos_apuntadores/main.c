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

    // Declaracion de variables

    int   numero   = 10;
    float flotante = 10.5;
    char  caracter = 'a';

    int   *pnumero   = &numero;
    float *pflotante = &flotante;
    char  *pcaracter = &caracter;

    // Direcciones de memoria

    printf("%p\n", &numero);
    printf("%p\n", &flotante);
    printf("%p\n", &caracter);

    printf("\n");

    printf("%p\n", pnumero);
    printf("%p\n", pflotante);
    printf("%p\n", pcaracter);

    printf("\n_________________________________________EXIT\n\n");
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