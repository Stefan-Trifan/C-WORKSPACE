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

#define TAM_BLOQUE 10

// Funciones del programa

// Funciones auxiliares
char *leerCadenaDinamicaFichero(FILE *fd);
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    // Declaracion de variables
    FILE *fd;
    char *linea;
    char *nombre;
    char *apellido;
    int edad;

    // Abrimos el fichero
    fd = fopen("./datos.csv", "r");
    if (fd == NULL) {
        printf("Error abriendo el archivo");
        printf("\033[31m\n_________________________________________FAIL\n\n\033[0m");
        return EXIT_FAILURE;
    }

    // Sacamos la linea del fichero
    linea = leerCadenaDinamicaFichero(fd);

    // Leemos los datos
    nombre   = strtok(linea, ";");
    apellido = strtok(NULL, ";");
    edad     = atoi(strtok(NULL, ";"));

    // Imprimos los datos
    printf("Nombre:   %s\n", nombre);
    printf("Apellido: %s\n", apellido);
    printf("Edad:     %d\n", edad);

    printf("\n_________________________________________EXIT\n\n");
    return EXIT_SUCCESS;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa
char *leerCadenaDinamicaFichero(FILE *fd)
{
    char *p_texto_destino = malloc(sizeof(char) * TAM_BLOQUE);
    int memoria_actual = TAM_BLOQUE;
    int i = 0;
    char c;

    while ((c = fgetc(fd)) != EOF)
    {
        if (i == memoria_actual - 1)
        {
            memoria_actual += TAM_BLOQUE;
            p_texto_destino = realloc(p_texto_destino, memoria_actual * sizeof(char));
        }
        p_texto_destino[i] = c;
        i++;
    }
    p_texto_destino[i] = '\0';

    return p_texto_destino;
}

// Funciones auxiliares
void clearBuffer()
{
    while (getchar() != '\n');
}