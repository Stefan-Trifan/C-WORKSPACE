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

#define NOMBRE_ARCHIVO_ORIGEN "datos1.txt"
#define NOMBRE_ARCHIVO_DESTINO "datos2.txt"

// Funciones del programa

// Funciones auxiliares
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    // Declaracion de variables
    FILE *fd1;
    FILE *fd2;
    char c;

    // Abrimos los archivos
    fd1 = fopen(NOMBRE_ARCHIVO_ORIGEN, "r");
    fd2 = fopen(NOMBRE_ARCHIVO_DESTINO, "w");

    // Comprobamos
    if(fd1 == NULL || fd2 == NULL)
    {
        printf("Error\n");
        printf("\033[31m\n_________________________________________FAIL\n\n\033[0m");
        return EXIT_FAILURE;
    }

    // Preparamos el segundo archivo
    while((c = getc(fd1)) != EOF)
    {
        if(c == ';')
        {
            putc('-', fd2);
        }
        else
        {
            putc(c, fd2);
        }
    }

    // Cerramos los archivos
    fclose(fd1);
    fclose(fd2);

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