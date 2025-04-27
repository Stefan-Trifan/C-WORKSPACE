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

typedef struct
{
    char *nombre;
    char *apellidos;
    char *email;
}
datos_t;

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
    char file_name[] = "emails.txt";
    datos_t datos[100];
    
    // Abrimos el archivo
    fd = fopen(file_name, "a+");
    if(fd = NULL)
    {
        printf("Error.");
        printf("\033[31m\n_________________________________________FAIL\n\n\033[0m");
        return EXIT_FAILURE;
    }


    

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