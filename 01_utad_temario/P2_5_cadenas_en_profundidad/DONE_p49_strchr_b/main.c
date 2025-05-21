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
    char *cadena;
    char caracter;
    char *primera_coincidencia;
    char *ultima_coincidencia;

    // Pedimos la cadena y el caracter
    printf("Introduce la cadena de caracteres: ");
    cadena = pedirCadenaDinamica();

    printf("Introduce el caracter: ");
    scanf("%c", &caracter);
    clearBuffer();
    
    // Buscamos la primera coincidencia
    primera_coincidencia = strchr(cadena, caracter);

    // Buscamos la ultima coincidencia
    ultima_coincidencia = strrchr(cadena, caracter);

    // Imprimos el resultado
    if(primera_coincidencia == ultima_coincidencia)
    {
        printf("Aparece una sola vez en la posicion %ld", primera_coincidencia - cadena);
    }
    else
    {
        printf("No cumple");
    }

    free(cadena);

    printf("\n_________________________________________EXIT\n\n");
    return EXIT_SUCCESS;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa
char *pedirCadenaDinamica()
{
    char *p_texto_destino = malloc(sizeof(char) * TAM_BLOQUE);
    char c;
    int i = 0;
    int memoria_actual = TAM_BLOQUE;

    while ((c = getchar()) != '\n')
    {
        if (i == memoria_actual)
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