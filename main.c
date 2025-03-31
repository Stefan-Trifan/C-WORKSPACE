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
char *escribeLineaDinamica();
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    char *texto;
    printf("Introduce tu linea dinamica: ");
    texto = escribeLineaDinamica();
    printf("Tu linea es: %s", *texto);
    // prueba

    printf("\n_________________________________________EXIT\n\n");
    return EXIT_SUCCESS;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa
char *escribeLineaDinamica()
{
    char *letra;

    *letra = 'a';

    return letra;
}

// Funciones auxiliares
void clearBuffer()
{
    while (getchar() != '\n');
}