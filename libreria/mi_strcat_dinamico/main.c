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
void mi_strcat_dinamico(char **destino, char *origen);
char *pedirCadenaDinamica();
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    // Declaracion de variables
    char *origen;
    char *destino;

    // Pedimos
    printf("-> ");
    origen = pedirCadenaDinamica();
    printf("-> ");
    destino = pedirCadenaDinamica();

    // Copiamos
    mi_strcat_dinamico(&destino, origen);

    // Imprimimos
    printf("%s", destino);

    printf("\n_________________________________________EXIT\n\n");
    return EXIT_SUCCESS;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa

// Funciones auxiliares
void mi_strcat_dinamico(char **destino, char *origen)
{
    *destino = realloc(*destino, sizeof(char) * (strlen(*destino) + strlen(origen) + 1));
    
    if(*destino != NULL)
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
    while (getchar() != '\n');
}