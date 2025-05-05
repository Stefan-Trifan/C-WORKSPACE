/*
    *   Autor
        Stefan Trifan
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIRECCION "./datos.txt"

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

    // Abrimos el fichero
    fd = fopen(DIRECCION, "a+");

    // Escribimos en el fichero
    printf("Introducir texto en \"datos.txt\"\n-> ");
    while((c = getchar()) != '\n')
    {
        putc(c, fd);
    }

    // Cerramos el archivo
    fclose(fd);

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