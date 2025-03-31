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

#define TAM_BLOQUE 5

// Funciones del programa

// Funciones auxiliares
char *escribeLineaDinamica();
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    char *p_mi_texto;

    printf("Introduce tu linea dinamica: ");
    p_mi_texto = escribeLineaDinamica();

    printf("\nTu linea es: %s", p_mi_texto);

    free(p_mi_texto);

    printf("\n_________________________________________EXIT\n\n");
    return EXIT_SUCCESS;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa
char *escribeLineaDinamica()
{
    char *p_texto = (char *)malloc(TAM_BLOQUE * sizeof(char));
    char c;
    int i = 0;
    int memoria_actual = TAM_BLOQUE;

    while((c = getchar()) != '\n')
    {
        if(i == memoria_actual)
        {
            memoria_actual += TAM_BLOQUE;
            p_texto = realloc(p_texto, memoria_actual * sizeof(char));
        }
        p_texto[i] = c;
        i++;
    }
    p_texto[i] = '\0';


    return p_texto;
}

// Funciones auxiliares
void clearBuffer()
{
    while (getchar() != '\n');
}