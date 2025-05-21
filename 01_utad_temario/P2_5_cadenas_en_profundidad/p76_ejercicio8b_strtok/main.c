/*
    *   Autor
        Stefan Trifan
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
    FILE *fd = fopen(DIRECCION, "w+");

    // Comprobamos que el archivo se abrio correctamente
    if(fd = NULL)
    {
        printf("\033[31mERROR: No fue posible abrir el archivo\n\033[0m");
        printf("\033[31m\n_________________________________________FAIL\n\n\033[0m");
        return EXIT_FAILURE;
    }

    // Solicita al usuario por teclado el nombre, el primer apellido y la edad de alumnos de Utad. 

    // El usuario puede estar introduciendo alumnos hasta que él lo determine. Esa información debe ser escrita en un fichero de texto (alumnos.txt).

    // La información de cada alumno será escrita en una línea separada por “;”. 

    // Para acabar se debe sacar la información del fichero y presentarla por el monitor con el siguiente formato: 

    // El alumno <apellido, nombre> nació el año <año_nacimeinto>

    // Liberamos memoria y cerramos fd

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