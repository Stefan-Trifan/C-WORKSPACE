/*
    *   Autor
        Stefan Trifan

    *   Estado
        Done

    *   Enunciado 4 
        Lista de la compra
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>

// Funciones del programa

// Funciones auxiliares
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");



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