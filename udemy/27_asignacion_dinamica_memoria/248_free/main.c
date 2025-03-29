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
    printf("\n___________________________START\n\n");

    int *p1 = NULL;

    p1 = malloc(sizeof(int));

    if(p1 == NULL)
    {
        printf("La memoria está llena\n");  
    }
    else
    {
        printf("Hay espacio\n");
        *p1 = 15;
        printf("p1 %d\n", *p1);
    }

    free(p1);
    printf("p1 %d\n", *p1);

    printf("\n\033[1;32m___________________________EXIT_SUCCESS\033[0m\n\n");
    return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa

// Funciones auxiliares
void clearBuffer()
{
    while (getchar() != '\n');
}