/*
    *	Autor
        Stefan Trifan

    *   Estado

    * 	Enunciado
        Esta funcion se queda solo con los caracteres necesarios
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <stdlib.h>

#define TAM_BLOQUE 5

// Funciones del programa
char *escribeLineaDinamica();

// Funciones auxiliares
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    char *texto;
    texto = escribeLineaDinamica();
    printf("Texto es: %s", texto);

    free(texto);

    printf("\n_________________________________________END\n\n");
    return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa
char *escribeLineaDinamica()
{
    char *ptexto_destino = malloc(sizeof(char) * TAM_BLOQUE);
    char c;
    int i = 0;
    int memoria_actual = TAM_BLOQUE;

    while ((c = getchar()) != '\n')
    {
        if (i == memoria_actual)
        {
            memoria_actual += TAM_BLOQUE;
            ptexto_destino = realloc(ptexto_destino, memoria_actual * sizeof(char));
        }
        ptexto_destino[i] = c;
        i++;
    }
    ptexto_destino[i] = '\0';

    return ptexto_destino;
}

// Funciones auxiliares
void clearBuffer()
{
    while (getchar() != '\n');
}