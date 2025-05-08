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
void *mi_strcat_dinamico(char **destino, const char *origen);
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    // Declaracion de variables
    char *origen = "Cadena de origen";
    char *destino;

    mi_strcat_dinamico(&destino, origen);

    printf("%s", destino);

    printf("\n_________________________________________EXIT\n\n");
    return EXIT_SUCCESS;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa

// Funciones auxiliares
void *mi_strcat_dinamico(char **destino, const char *origen)
{
    *destino = realloc(*destino, sizeof(char) * (strlen(*destino) + strlen(origen) + 1));

    if (*destino)
    {
        strcat(*destino, origen);
    }
}

void clearBuffer()
{
    while (getchar() != '\n');
}