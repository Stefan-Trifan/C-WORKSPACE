/*
    *   Autor
        Stefan Trifan

    *   Estado

    *   Enunciado
        ./main Trifan
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_BLOQUE 10

// Funciones del programa
void convertir_a_mayus(char *cadena);
void convertir_a_minus(char *cadena);

// Funciones auxiliares
char *pedirCadenaDinamica();
char *mi_strdup(const char *origen);
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    // Declaramos las variables
    char *cadena;
    char *cadena_mayus;
    char *cadena_minus;

    // Guardamos el cadena
    cadena = pedirCadenaDinamica();

    cadena_mayus = mi_strdup(cadena);
    cadena_minus = mi_strdup(cadena);

    // Convertimos
    convertir_a_mayus(cadena_mayus);
    convertir_a_minus(cadena_minus);

    // Imprimmos los cadenas en mayuscula y en minuscula
    printf("cadena:          %s\n", cadena);
    printf("cadena_mayus:    %s\n", cadena_mayus);
    printf("cadena_minus:    %s\n", cadena_minus);

    // Liberamos la memoria reservada
    free(cadena);
    free(cadena_mayus);
    free(cadena_minus);

    printf("\n_________________________________________EXIT\n\n");
    return EXIT_SUCCESS;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa
void convertir_a_mayus(char *cadena)
{
    int i = 0;

    while((cadena[i]) != '\0')
    {
        if(cadena[i] >= 'a' && cadena[i] <= 'z')
        {
            cadena[i] -= 32;
        }
        i++;
    }
}

void convertir_a_minus(char *cadena)
{
    int i = 0;

    while((cadena[i]) != '\0')
    {
        if(cadena[i] >= 'A' && cadena[i] <= 'Z')
        {
            cadena[i] += 32;
        }
        i++;
    }
}

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

char *mi_strdup(const char *origen)
{
    char *destino = NULL;
    int len;

    len = strlen(origen) + 1;
    destino = (char *)malloc(len * sizeof(char));
    if(destino)
    {
        strcpy(destino, origen);
    }
    
    return destino;
}

void clearBuffer()
{
    while (getchar() != '\n');
}