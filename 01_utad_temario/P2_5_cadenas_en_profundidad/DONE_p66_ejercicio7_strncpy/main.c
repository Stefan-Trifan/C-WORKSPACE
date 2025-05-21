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
char *mi_strcpy_dinamico(const char *origen);
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    // Declaracion de variables
    char cadena_origen[] = "<numeros>123456789</numeros>";
    char *puntero_auxiliar;
    char *cadena_destino;
    
    puntero_auxiliar = cadena_origen;

    puntero_auxiliar += 9;

    cadena_destino = malloc(sizeof(char) * 6);
    strncpy(cadena_destino, puntero_auxiliar, 5);
    cadena_destino[5] = '\0';

    printf("%s", cadena_destino);


    printf("\n_________________________________________EXIT\n\n");
    return EXIT_SUCCESS;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa

// Funciones auxiliares
char *mi_strcpy_dinamico(const char *origen)
{
    char *destino = NULL;
    int len;

    len = strlen(origen) + 1;
    destino = (char *)malloc(len * sizeof(char));
    if(destino)
    {
        strcpy(destino, origen);
    }
    
    return destino;
}

void clearBuffer()
{
    while (getchar() != '\n');
}