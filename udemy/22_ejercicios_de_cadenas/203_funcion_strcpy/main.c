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
    char origen[] = "Hola Mundo";
    char destino[30];
    
    // Copiamos
    strcpy(destino, origen);
    
    // Imprimimos
    printf("destino: %s\n", destino);
    
    // Cambiamos
    strcpy(destino + 5, "soy el mejor en C jeje");

    // Imprimmos nuevamente
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