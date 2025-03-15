/*
    *   Autor
        Stefan Trifan

    *   Estado

    *   Enunciado X
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

    char nombre[20], *p_nombre;
    int longitud;

    strcpy(nombre, "Steve");
    longitud = strlen(nombre);

    p_nombre = (char *)malloc((longitud + 1) * sizeof(char));

    strcpy(p_nombre, nombre);

    printf("Longitud %d\n", longitud);
    printf("Nombre %s\n", p_nombre);

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