/*
    *   Autor
        Stefan Trifan

    *   Estado
        TODO no esta hecho

    *   Enunciado
        Lorem Ipsum
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_BLOQUE 5

// Funciones del programa

// Funciones auxiliares
char *leerCadenaDinamicaFichero();
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    // Declaracion de variables
    char *texto;
    FILE *fd;

    // Abrimos el fichero en modo lectura

    // Llamamos a la funcion
    texto = leerCadenaDinamicaFichero();

    // Imprimimos el texto
    printf("Texto: %s");

    printf("\n_________________________________________EXIT\n\n");
    return EXIT_SUCCESS;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa

// Funciones auxiliares
char *leerCadenaDinamicaFichero()
{

}

void clearBuffer()
{
    while (getchar() != '\n');
}