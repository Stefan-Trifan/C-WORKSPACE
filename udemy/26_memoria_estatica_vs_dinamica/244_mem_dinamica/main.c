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

// Funciones del programa

// Funciones auxiliares
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n___________________________START\n\n");

    int *mi_entero;
    mi_entero = (int *)malloc(sizeof(int));
    if (mi_entero != NULL)
    {
        printf("Exito\n");
    }
    else
    {
        printf("Fracaso\n");
    }

    int* mi_array;
    mi_array = (int *)malloc(sizeof(int)*4);
    if(mi_array != NULL)
    {
        printf("Exito\n");
    }
    else
    {
        printf("Fracaso\n");
    }
    free(mi_array);
    free(mi_entero);

    printf("\n\033[1;32m___________________________EXIT_SUCCESS\033[0m\n\n");
    return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa

// Funciones auxiliares
void clearBuffer()
{
    while (getchar() != '\n')
        ;
}