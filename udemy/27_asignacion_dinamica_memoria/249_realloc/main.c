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

    int *vector, *vectorConvertido;
    int i;
    vector = malloc(3 * sizeof(int));
    // Reserva memoria para 3 elementos

    // Primer vector
    vector[0] = 1;
    vector[1] = 2;
    vector[2] = 3;

    for(int i = 0; i < 3; i++)
    {
        printf("cooredana %d\n", vector[i]);
    }

    // Ampliamos el arreglo a 5
    vectorConvertido = realloc(vector, 5 * sizeof(int));

    // Nuevos valores
    vector[3] = 4;
    vector[4] = 5;
    printf("\n\n");

    for(int i = 0; i < 5; i++)
    {
        printf("cooredana %d\n", vectorConvertido[i]);
    }

    printf("\n_________________________________________EXIT\n\n");
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