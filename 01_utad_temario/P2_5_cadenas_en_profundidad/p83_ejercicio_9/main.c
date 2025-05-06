/*
    *   Autor
        Stefan Trifan
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct direccion
{
    char *nombre_calle;
    char *piso;
    char puerta;
}
direccion_t;

typedef struct ciudadano
{
    char *nombre;
    int edad;
    direccion_t direccion;
}
ciudadano_t;

// Funciones del programa

// Funciones auxiliares
char *mi_strdup(const char *origen);
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    // Declaracion de variables
    char *p_nombre_fichero;

    // Comprobamos los parametros del main
    if(argc != 2)
    {
        printf("Faltan parametros\n");
        printf("\033[31m\n_________________________________________FAIL\n\n\033[0m");
        return EXIT_FAILURE;
    }

    // Guardamos el nombre del fichero que vamos a utilizar
    p_nombre_fichero = mi_strdup(argv[1]);
    printf("%s", p_nombre_fichero);

    printf("\n_________________________________________EXIT\n\n");
    return EXIT_SUCCESS;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa

// Funciones auxiliares
char *mi_strdup(const char *origen)
{
    char *destino = NULL;
    int len = strlen(origen) + 1;
    destino = (char *)malloc(len * sizeof(char));
    if (destino) 
    {
        strcpy(destino, origen);
    }
    return destino;
}

void clearBuffer()
{
    while (getchar() != '\n');
}