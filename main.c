/*
    *   Autor
        Stefan Trifan

    *   Estado

    *   Enunciado X
        Lorem Ipsum
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"
// Funciones del programa

// Funciones auxiliares
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    printf(
        "\033[1;31mERROR: El tipo de dato introducido no es válido. \n"
        "Por favor, inténtelo de nuevo. \n"
        "-> \033[0m"
    );
    printf("\nAHORA BIEN \n");
    printf(
        "\033[1;31mERROR: El tipo de dato introducido no es válido.\n"
        "Por favor, inténtelo de nuevo.\n"
        "-> \033[0m"
    );
    printf("\nAHORA BIEN \n");
    printf(
        "\033[1;33mALERTA: El tipo de dato introducido no es válido.\n"
        "Por favor, inténtelo de nuevo.\n"
        "-> \033[0m"
    );
    printf("\nAHORA BIEN \n");
    printf("\n_________________________________________END\n\n");
    return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa

// Funciones auxiliares
void clearBuffer()
{
    while (getchar() != '\n');
}