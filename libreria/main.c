/**
 * Nombre: Stefan Trifan
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"

// Funciones del programa

// Funciones auxiliadres

/*  ______________________________________________
    INICIO MAIN */

int main(int argc, char *argv[])
{
    printf("\n___________________________________________START\n\n");
    
    // Delcaracion de variables
    printf("Hola");

    printf("\n___________________________________________START\n\n");
    return EXIT_SUCCESS;
}

/*  ______________________________________________
    INICIO DEFINICION DE FUNCIONES */

// Funciones del programa

// Funciones auxiliadres

void clearBuffer()
{
    while((getchar()) != '\n');

}
