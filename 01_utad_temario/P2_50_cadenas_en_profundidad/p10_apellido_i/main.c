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
char *cambiarMinuscula(char *cadena);
char *cambiarMayscula(char *cadena);

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
    char *apellidoOriginal = NULL;
    char *apellidoMinus;
    char *apellidoMayus;

    // Guardamos el apellido de argv a apellidoOriginal
    apellidoOriginal = (char *)malloc(sizeof(char) * (strlen(argv[1]) + 1));
    strcpy(apellidoOriginal, argv[1]);
    printf("Apellido es: %s", apellidoOriginal);

    // Convertimos cada una de las letras en minuscula y lo guaramos en apellidoMinus

    // Convertimos cada una de las letras en mayuscula y lo guardamos en apellidoMayus

    // Imprimmos los apellidos en mayuscula y en minuscula

    printf("\n_________________________________________EXIT\n\n");
    return EXIT_SUCCESS;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa
char *cambiarMinuscula(char *cadena)
{
    char * res;

    return res;
}

char *cambiarMayscula(char *cadena)
{

}

// Funciones auxiliares
void clearBuffer()
{
    while (getchar() != '\n');
}