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

    // Declaracion de variables
    int array[10];
    int *puntero = NULL;

    array[0] = 5;
    puntero = array; /* (1) Equivale a puntero = &array[0];
                        esto se lee como "dirección del primer
                        elemento de array" */

    *(puntero)++;    /* (2) Equivale a array[0]++; (2) */
    puntero++;       /* (3) puntero equivale a asignar a puntero el valor &array[1] */

    *(puntero +2)=5;

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