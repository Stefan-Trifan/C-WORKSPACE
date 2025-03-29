/*
        *	Autor
            Stefan Trifan

        *   Estado
            Sin terminar. No funciona

        * 	Enunciado 
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

    int opcion    = 0,
        i_alumnos = 0,
        i_grupos  = 0;

    // 1 Reservamos espacio para la lista de grupos
    // 2 Reservamos espacio para la lista de alumnos dentro del primer grupo
    char ***grupo       = (char ***)malloc(sizeof(char **));
    *(grupo + i_grupos) = (char ** )malloc(sizeof(char * ));

    do
    {
        // Menu
        printf(
            "SELECCIONA\n"
            "[1] - Introducir alumno en grupo actual (%d)\n"
            "[2] - Introducir alumno en nuevo grupo\n"
            "[3] - Imprimir alumnos\n"
            "[4] - Salir\n"
            "-> ", i_grupos);
        opcion = pedirEnteroPos();

        // Introducir alumno en grupo actual
        if(opcion == 1)
        {
           // Pedimos nombre para un alumno
            printf("Introduce el nombre\n-> ");
            *(grupo + i_grupos) = (char **)realloc(*(grupo + i_grupos), (i_alumnos + 1) * sizeof(char *));
            *(*(grupo + i_grupos) + i_alumnos) = leeLineaDinamica();
            i_alumnos++;
            printf("\n\n");
        }

         // Introducir alumno en nuevo grupo
        if(opcion == 2)
        {
            printf("Introduce el nombre\n-> ");
            i_grupos++;
            grupo = (char ***)realloc(grupo, (i_grupos + 1) * sizeof(char **));
            *(grupo + i_grupos) = (char **)malloc(sizeof(char *));  

            // Expandimos el nuevo grupo para su primer alumno
            *(grupo + i_grupos) = (char **)realloc(*(grupo + i_grupos), (i_alumnos + 1) * sizeof(char *));
            *(*(grupo + i_grupos) + i_alumnos) = leeLineaDinamica();
            i_alumnos = 0;
            printf("\n\n");
        }

        // Imprimir alumnos
        if (opcion == 3)
        {
            for (int i = 0; i <= i_grupos; i++) 
            {
                printf("Grupo %d:\n", i + 1);
                for (int j = 0; j < i_alumnos; j++)
                {
                    printf("- %s\n", *(*(grupo + i) + j));
                }
            }

            printf("\n\n");
        }
    } while (opcion != 4);

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