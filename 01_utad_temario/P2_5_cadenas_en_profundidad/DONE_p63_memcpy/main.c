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
    char *origen = "cadena1";
    char destino[8];

    printf("Antes:\n");
    printf("origen : %s\n", origen);
    printf("destino: %s\n", destino);

    // memcpy
    memcpy(destino, origen, 7);
    destino[7] = '\0';

    printf("\n\nDespues:\n");
    printf("origen : %s\n", origen);
    printf("destino: %s\n", destino);

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