/*
    *   Autor
        Stefan Trifan

    *   Estado

    *   Enunciado
        Tomar un archivo de texto y con la funcion fgetc() leer todo su contenido

        fgetc(puntero_archivo);
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_BLOQUE 10
#define DIRECCION "datos.txt"

// Funciones del programa

// Funciones auxiliares
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    // Declaracion de variables
    FILE *fd;
    char c;

    // Abrimos el archivo
    fd = fopen(DIRECCION, "r");

    // Probamos fgetc
    while((c = fgetc(fd)) != EOF)
    {
        fputc(c, stdout);
    }


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