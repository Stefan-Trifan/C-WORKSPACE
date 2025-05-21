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
#define DIRECCION "datos.txt"

// Funciones del programa
char *leerFicheroDinamicoLinea(FILE *fd);
char *pedirCadenaDinamica();

// Funciones auxiliares
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    // Declaracion de variables
    FILE *fd = fopen(DIRECCION, "r");
    char *cadena_original;
    char *token_nombre;
    char *token_apellido;
    int token_edad;

    // Guardamos la linea
    cadena_original = leerFicheroDinamicoLinea(fd);

    // Primer punto
    token_nombre = strtok(cadena_original, ";");

    // Segundo Punto
    token_apellido = strtok(NULL, ";"); 

    // Tercero Punto
    token_edad = atoi(strtok(NULL, ";"));  

    // Imprimir
    printf("token_nombre\n-> %s\n\n", token_nombre);
    printf("token_apellido\n-> %s\n\n", token_apellido);
    printf("token_edad\n-> %d\n\n", token_edad);

    // Liberar memoria y cerrar programa
    free(cadena_original);
    fclose(fd);
   
    printf("\n_________________________________________EXIT\n\n");
    return EXIT_SUCCESS;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa

// Funciones auxiliares
char *pedirCadenaDinamica()
{
    char *p_texto_destino = malloc(sizeof(char) * TAM_BLOQUE);
    char c;
    int i = 0;
    int memoria_actual = TAM_BLOQUE;

    while ((c = getchar()) != '\n')
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

char *leerFicheroDinamicoLinea(FILE *fd)
{
    char *p_texto_destino = malloc(sizeof(char) * TAM_BLOQUE);
    int memoria_actual = TAM_BLOQUE;
    int i = 0;
    char c;

    while ((c = fgetc(fd)) != EOF && c != '\n')
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

void clearBuffer()
{
    while (getchar() != '\n');
}