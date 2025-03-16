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
    printf("\n_________________________________________START\n\n");

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

    printf("\n_________________________________________END\n\n");
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