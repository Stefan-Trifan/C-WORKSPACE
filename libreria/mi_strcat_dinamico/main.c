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
void *mi_strcat_dinamico(char **destino, const char *origen);
char *pedirCadenaDinamica();
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    // Declaracion de variables
    char *cadena_1;
    char *cadena_2;

    printf("Introduce la priemra cadena\n-> ");
    cadena_1 = pedirCadenaDinamica();

    printf("Introduce la segunda cadena\n-> ");
    cadena_2 = pedirCadenaDinamica();

    mi_strcat_dinamico(&cadena_1, cadena_2);

    printf("%s", cadena_1);

    printf("\n_________________________________________EXIT\n\n");
    return EXIT_SUCCESS;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa

// Funciones auxiliares
void *mi_strcat_dinamico(char **destino, const char *origen)
{
    *destino = realloc(*destino, sizeof(char) * (strlen(*destino) + strlen(origen) + 1));

    if (*destino)
    {
        strcat(*destino, origen);
    }
}

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
    while (getchar() != '\n')
        ;
}