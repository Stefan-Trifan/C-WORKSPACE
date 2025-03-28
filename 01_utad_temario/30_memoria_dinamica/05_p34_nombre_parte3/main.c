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

    char **alumnos = (char **)malloc(sizeof(char *));
    int es_nuevo_alumno = 0,
        i_alumnos       = 0;

    do
    {
        // Pedimos nombre para un alumno
        printf("Introduce el nombre\n-> ");
        *(alumnos + i_alumnos) = leeLineaDinamica();
        printf("Nombre es: %s\n", *(alumnos + i_alumnos));

        // Preguntamos si el user quiere introducir mas alumnos
        // Si vamos a introducir ams alumnos, ajustamos el tam de **alumnos
        do
        {
            printf(
                "Introducimos otro alumno? Introduce: [1] - SI [O] - NO\n"
                "-> ");
            es_nuevo_alumno = pedirEnteroPos();
        } 
        while (es_nuevo_alumno != 1 && es_nuevo_alumno != 0);
        if(es_nuevo_alumno == 1)
        {
            i_alumnos++;
            alumnos = (char **)realloc(alumnos, sizeof(char *) * (i_alumnos + 1));
        }
    } 
    while (es_nuevo_alumno == 1);
    
    printf("\n\n\nLos alumnos que has introducido son: \n");
    for(int i = 0; i < i_alumnos + 1; i++)
    {
        printf("Alumno [%d]: %s\n", i, *(alumnos + i));
    }

    free(alumnos);

    printf("\n\033[1;32m_________________________________________EXIT_SUCCESS\033[0m\n\n");
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