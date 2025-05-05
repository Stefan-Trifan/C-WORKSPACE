/*
    *   Autor
        Stefan Trifan
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lineas_t
{
    int  num_lineas;
    char **lineas;
}
lineas_t;

// Funciones del programa
char *leeLineaDinamicaFichero(FILE *fd);

// Funciones auxiliares
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    

    printf("\n_________________________________________EXIT\n\n");
    return EXIT_SUCCESS;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa
char *leeLineaDinamicaFichero(FILE *fd)
{

}

// Funciones auxiliares
void clearBuffer()
{
    while (getchar() != '\n');
}