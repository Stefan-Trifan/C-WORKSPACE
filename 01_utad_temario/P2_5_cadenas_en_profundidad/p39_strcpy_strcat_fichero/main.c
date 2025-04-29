/*
    *   Autor
        Stefan Trifan

    *   Estado
        Doing

    *   Enunciado
        Lorem Ipsum
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_BLOQUE 10

// Funciones del programa

// Funciones auxiliares
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    // Comprobamos que el programa recibe los parametros
    if(argc != 2)
    {
        printf("ERROR: Tienes que introducir el nombre del fichero.\n");
        printf("USO: ./main datos.txt");
        printf("\n_________________________________________FAIL\n\n");
        return EXIT_FAILURE;
    }

    // Declaracion de variables
    char *nombre_fichero;

    // Calculamos la longitud del nombre fichero
    printf("Tam nombre fichero: %d", strlen(argv[1]));

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