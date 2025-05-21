/*
    *   Autor
        Stefan Trifan
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_BLOQUE 10

// Funciones del programa

// Funciones auxiliares
char *pedirCadenaDinamica();
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    // Declaracion de variables
    char **nombres = NULL;
    int cont = 0;

    // Reservamos memoria para el primer nombre
    nombres = (char **)malloc(sizeof(char *));
    printf("-> ");
    nombres[cont] = pedirCadenaDinamica();

    // Pedimos los nombres
    while(strcasecmp(nombres[cont], "fin"))
    {
        cont++;
        nombres = (char **)realloc(nombres, sizeof(char *) * (cont + 1));
        printf("-> ");
        nombres[cont] = pedirCadenaDinamica();
    }

    // Imprimimos los nombres desordenados
    printf("NOMBRES DESORDENADOS: \n");
    for(int i = 0; i < cont; i++)
    {
        printf("%s\n", nombres[i]);
    }

    // Imprimimos los nombres ordenados
    for(int i = 0; i < cont - 1; i++)
    {
        for(int j = 0; j < cont - i - 1; j++)
        {
            if(strcmp(nombres[j], nombres[j + 1]) > 0)
            {
                char *temp = nombres[j];
                nombres[j] = nombres[j + 1];
                nombres[j + 1] = temp;
            }
        }
    }

    // Imprimimos los nombres ordenados
    printf("NOMBRES ORDENADOS: \n");
    for(int i = 0; i < cont; i++)
    {
        printf("%s\n", nombres[i]);
    }

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