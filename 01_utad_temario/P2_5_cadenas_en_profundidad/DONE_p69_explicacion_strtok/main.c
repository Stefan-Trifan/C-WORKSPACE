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
char *pedirCadenaDinamica();

// Funciones auxiliares
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    // Declaracion de variables
    char cadena_original[] = "uno;dos;tres;cuatro";
    char *token_primero;
    char *token_segundo;
    char *token_tercero;
    char *token_cuarto;

    // Imprimir
    printf("Antes de strtok, cadena_original   = %s\n\n\n\n", cadena_original);
    

    // Primer punto
    token_primero = strtok(cadena_original, ";");

    // Segundo Punto
    token_segundo = strtok(NULL, ";"); 

    // Tercero Punto
    token_tercero = strtok(NULL, ";");  

    // Cuarto Punto
    token_cuarto = strtok(NULL, ";");  

    // Imprimir
    printf("token_primero\n-> %s\n\n", token_primero);
    printf("token_segundo\n-> %s\n\n", token_segundo);
    printf("token_tercero\n-> %s\n\n", token_tercero);
    printf("token_cuarto\n-> %s\n\n\n\n", token_cuarto);

    printf("Despues de strtok, cadena_original = %s\n\n\n\n", cadena_original);
    
    
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

void clearBuffer()
{
    while (getchar() != '\n');
}