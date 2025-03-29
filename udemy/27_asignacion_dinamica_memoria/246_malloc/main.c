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

    float *p_num;
    p_num = (float *)malloc(sizeof(float));
    if(p_num == NULL)
    {
        printf("Error\n");
        return 0;
    }

    *p_num = 5.2;

    printf("num %.2f\n", *p_num);
    free(p_num);

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