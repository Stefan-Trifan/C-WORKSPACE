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

    // Declaramos variables
    FILE *fd;
    char texto[] = "Hola Mundo";
    
    // Abrimps el archivo en modo escritura (posicion final)
    fd = fopen("prueba.txt", "a");

    // Comprobamos si se ha creado
    if(fd == NULL)
    {
        printf("No creado\n");
    }
    else
    {
        printf("Creado\n");
        fprintf(fd, "Texto escrito: 123 ");
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