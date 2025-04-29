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
int pedirEnteroPos();
void clearBuffer();

/* _________________________________________
       Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    // Reservamos espacio para 1 grupo inicialmente
    char ***alumno = (char***)malloc(sizeof(char**));

    // Reservamos espacio para 1 alumno en grupo 0
    alumno[0] = (char**)malloc(sizeof(char*));

    printf("Introduce el nombre del 1 alumno 1 grupo\n-> ");
    alumno[0][0] = leeLineaDinamica();

    // Expandiendo para un 2do alumno en grupo 0
    alumno[0] = (char**)realloc(alumno[0], 2 * sizeof(char*));
    printf("Introduce el nombre del 2 alumno 1 grupo\n-> ");
    alumno[0][1] = leeLineaDinamica();

    // Expandiendo para un nuevo grupo alumno[1]
    alumno = (char***)realloc(alumno, 2 * sizeof(char**));
    alumno[1] = (char**)malloc(sizeof(char*));
    printf("Introduce el nombre del 1 alumno 2 grupo\n-> ");
    alumno[1][0] = leeLineaDinamica();

    printf("alumno[0][0] %s\n", alumno[0][0]);
    printf("alumno[0][1] %s\n", alumno[0][1]);
    printf("alumno[1][0] %s\n", alumno[1][0]);

    printf("\n_________________________________________EXIT\n\n");
    return 0;
}

/* _________________________________________
       Inicio definicion de funciones */

// Funciones del programa
char *leeLineaDinamica()
{
    char *p_nombre = malloc(sizeof(char) * TAM), c;
    int i = 0, incremento_memoria = TAM;

    while ((c = getchar()) != '\n')
    {
        if (i == incremento_memoria)
        {
            incremento_memoria += TAM;
            p_nombre = realloc(p_nombre, incremento_memoria * sizeof(char));
        }
        p_nombre[i] = c;
        i++;
    }
    p_nombre[i] = '\0';

    return p_nombre;
}

// Funciones auxiliares
int pedirEnteroPos()
{
    int num = 0, esValido = 0;
    do
    {
        esValido = scanf("%d", &num);
        clearBuffer();
        if (esValido == 0 || num < 0)
        {
            printf(
                "\033[1;31mERROR: El tipo de dato introducido no es válido.\n"
                "-> \033[0m"
            );
            esValido = 0;
        }
    }
    while (esValido != 1);
    return num;
}
void clearBuffer()
{
    while (getchar() != '\n');
}