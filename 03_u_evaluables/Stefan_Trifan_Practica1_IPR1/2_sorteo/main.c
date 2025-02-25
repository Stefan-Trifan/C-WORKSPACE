/*
    *   Autor
        Stefan Trifan

    *   Estado
        Done

    *   Enunciado 2 
        Sorteo
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>

#define TAM_STRING 20

typedef struct jugadores_t
{
    char nombre[TAM_STRING];
}jugadores_t;
// Funciones del programa

// Funciones auxiliares
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    jugadores_t jugador[10];

    printf("\n_________________________________________END\n\n");
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