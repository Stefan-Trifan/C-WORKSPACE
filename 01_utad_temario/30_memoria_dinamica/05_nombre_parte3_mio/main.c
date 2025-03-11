/*
        *	Autor
                Stefan Trifan

        *   Estado

        * 	Enunciado 23
                LoremIpsum
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <stdlib.h>

#define TAM 10

// Funciones del programa
char *leeLineaDinamica();

// Funciones auxiliares
void clearBuffer();

/* _________________________________________
       Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    char *nombre;

    printf("Introduce tu nombre\n-> ");
    nombre = leeLineaDinamica();
    printf("Nombre es: %s\n", nombre);

    free(nombre);

    printf("\n_________________________________________END\n\n");
    return 0;
}

/* _________________________________________
       Inicio definicion de funciones */

// Funciones del programa
char *leeLineaDinamica()
{
    char *p_nombre_alumno = malloc(sizeof(char) * TAM), c;
    int i = 0, incremento_memoria = TAM;

    while ((c = getchar()) != '\n')
    {
        if (i == incremento_memoria)
        {
            incremento_memoria += TAM;
            p_nombre_alumno = realloc(p_nombre_alumno, incremento_memoria * sizeof(char));
        }
        p_nombre_alumno[i] = c;
        i++;
    }
    p_nombre_alumno[i] = '\0';

    return p_nombre_alumno;
}

// Funciones auxiliares
void clearBuffer()
{
    while (getchar() != '\n');
}