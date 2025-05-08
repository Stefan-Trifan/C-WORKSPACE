/*
    *   Autor
        Stefan Trifan

    *   Estado
        Doing

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
void mi_strcat_dinamico(char **destino, const char *origen);
char *leerFicheroDinamicoLinea(FILE *fd, int num_linea);
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    if(argc != 2)
    {
        printf("\033[31m\n_________________________________________FAIL\n\n\033[0m");
        return EXIT_FAILURE;
    }

    // Declaracion de variables
    FILE *fd = fopen(argv[1], "r");
    char *nombre_alumno   = NULL;
    char *apellido_alumno = NULL;
    char *nombre_completo = malloc(sizeof(char));
    nombre_completo[0] = '\0';

    if(fd == NULL)
    {
        printf("oopsi te has equivocado\n");
        printf("\033[31m\n_________________________________________FAIL\n\n\033[0m");
        return EXIT_FAILURE;
    }

    nombre_alumno   = leerFicheroDinamicoLinea(fd, 0);
    apellido_alumno = leerFicheroDinamicoLinea(fd, 1);

    mi_strcat_dinamico(&nombre_completo, nombre_alumno);
    mi_strcat_dinamico(&nombre_completo, " ");
    mi_strcat_dinamico(&nombre_completo, apellido_alumno);

    printf("nombre_alumno   = %s\n", nombre_alumno);
    printf("apellido_alumno = %s\n", apellido_alumno);
    printf("nombre_completo = %s\n", nombre_completo);

    printf("\n_________________________________________EXIT\n\n");
    return EXIT_SUCCESS;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa

// Funciones auxiliares
void mi_strcat_dinamico(char **destino, const char *origen)
{
    *destino = realloc(*destino, sizeof(char) * (strlen(*destino) + strlen(origen) + 1));

    if (*destino)
    {
        strcat(*destino, origen);
    }
}

char *leerFicheroDinamicoLinea(FILE *fd, int num_linea)
{
    char *p_texto_destino = malloc(sizeof(char) * TAM_BLOQUE);
    char c;
    int i = 0;
    int memoria_actual = TAM_BLOQUE;
    int linea_actual = 0;

    rewind(fd);

    while ((c = fgetc(fd)) != EOF)
    {
        if (c == '\n')
        {
            linea_actual++;
        }
        else if (linea_actual == num_linea)
        {
            if (i == memoria_actual - 1)
            {
                memoria_actual += TAM_BLOQUE;
                p_texto_destino = realloc(p_texto_destino, memoria_actual * sizeof(char));
            }
            p_texto_destino[i] = c;
            i++;
        }
    }
    p_texto_destino[i] = '\0';

    rewind(fd);

    return p_texto_destino;
}

void clearBuffer()
{
    while (getchar() != '\n');
}