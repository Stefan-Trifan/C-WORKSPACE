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
char *mi_strdup(const char *origen);
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    // Declaracion de variables


    printf("\n_________________________________________EXIT\n\n");
    return EXIT_SUCCESS;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa

// Funciones auxiliares
char *mi_strdup(const char *origen)
{
    char *destino = NULL;
    int len = strlen(origen) + 1;
    destino = (char *)malloc(len * sizeof(char));
    if (destino) 
    {
        strcpy(destino, origen);
    }
    return destino;
}

void clearBuffer()
{
    while (getchar() != '\n');
}