/*
    *   Autor
        Stefan Trifan

    *   Estado

    *   Enunciado 3 - Autopista
        Se debe desarrollar un programa que simule el funcionamiento de una autopista. 
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



    printf("\n\033[1;32m_________________________________________EXIT_SUCCESS\033[0m\n\n");
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