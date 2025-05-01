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

    // Abrimos un archivo
    fd = fopen(DIRECCION, "r");

    // Leemos el archivo
    printf("+---------+\n");
    while((c = getc(fd)) != EOF)
    {
        if(c != ';')
        {
            printf(
                "| %c | %3d |\n"
                "+---------+\n", c, c);
        }
    }

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