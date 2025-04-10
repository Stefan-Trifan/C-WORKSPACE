/*
    *   Autor
        Stefan Trifan

    *   Estado

    *   Enunciado
        ./main Trifan
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

    if(argc != 2)
    {
        printf("Tienes que introducir parametros\n");
        printf("\n_________________________________________FAIL\n\n");
        return EXIT_FAILURE;
    }

    // Declaramos las variables
    char *apellidoOriginal = *argv[1];
    char *apellidoMinus;
    char *apellidoMayus;

    // Guardamos el apellido de argv a apellidoOriginal
    printf("Apellido es: %s", *apellidoOriginal);

    // Convertimos cada una de las letras en mayuscula y lo guardamos en apellidoMayus

    // Convertimos cada una de las letras en minuscula y lo guaramos en apellidoMinus

    // Imprimmos los apellidos en mayuscula y en minuscula

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