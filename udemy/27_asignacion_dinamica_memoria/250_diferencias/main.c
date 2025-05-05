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

    int *hola = (int *)malloc(10*sizeof(int));

    *hola = 5;

    printf("hola = %p\n", hola);
    printf("hola = %d\n", *hola);

    printf("_________________________________\n\n");

    int *adios = (int *)calloc(1, sizeof(int));

    printf("adios = %p\n", adios);
    printf("adios = %d\n", *adios);

    printf("_________________________________\n\n");

    hola = (int*)realloc(hola, 20 * sizeof(int));

    *(hola + 19) = 10;

    printf("hola = %p\n", hola + 19);
    printf("hola = %d\n", *(hola + 19));

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