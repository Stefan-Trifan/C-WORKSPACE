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
    printf("\n_________________________________________START\n\n");

    // Declaracion de variables
    char letras1[]  = "Hola";
    char letras2[5] = "Hola";
    char *letras3   = "Hola";
    char letras4[]  = {'H', 'o', 'l', 'a', '\0'};

    scanf("%s", letras1);
    clearBuffer();

    printf("letras1: %s\n", letras1);
    printf("letras2: %s\n", letras2);
    printf("letras3: %s\n", letras3);
    printf("letras4: %s\n", letras4);

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