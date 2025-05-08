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
#define DIRECCION "datos.txt"

typedef struct
{
    int    num_lineas;
    char **lineas;
}
lineas_t;

// Funciones del programa
void guardarLineasFichero(lineas_t *caja_texto_fichero, FILE *fd);
int contarLineasFichero(FILE *fd);

// Funciones auxiliares
char *leerFicheroDinamicoLinea(FILE *fd, int num_linea);
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    // Declaracion de variables
    lineas_t caja_texto_fichero;
    FILE *fd;

    // Abrimos el fichero
    fd = fopen(DIRECCION, "r");

    // Contamos las lineas que tiene el fichero
    caja_texto_fichero.num_lineas = contarLineasFichero(fd);

    // Guardamos las lineas del fichero en nuestra estructura
    guardarLineasFichero(&caja_texto_fichero, fd);

    // Cerramos el archivo
    fclose(fd);

    printf("\n_________________________________________EXIT\n\n");
    return EXIT_SUCCESS;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa
int contarLineasFichero(FILE *fd)
{
    int num_lineas = 0;
    char c;

    if((c = fgetc(fd)) != EOF)
    {
        num_lineas = 1;
        while((c = fgetc(fd)) != EOF)
        {
            if(c == '\n')
            {
                num_lineas++;
            }
        }
    }
    rewind(fd);

    return num_lineas;
}

void guardarLineasFichero(lineas_t *caja_texto_fichero, FILE *fd)
{
    caja_texto_fichero->lineas = malloc(caja_texto_fichero->num_lineas * sizeof(char *));
    for(int i = 0; i < caja_texto_fichero->num_lineas; i++)
    {
        caja_texto_fichero->lineas[i] = leerFicheroDinamicoLinea(fd, i);
        printf("Linea %d: %s\n", i, caja_texto_fichero->lineas[i]);
    }
}

// Funciones auxiliares
char *leerFicheroDinamicoLinea(FILE *fd, int num_linea)
{
    char *p_texto_destino = malloc(sizeof(char) * TAM_BLOQUE);
    char c;
    int i = 0;
    int memoria_actual = TAM_BLOQUE;
    int linea_actual = 0;

    while ((c = fgetc(fd)) != EOF)
    {
        if(c == '\n')
        {
            linea_actual++;
        }
        else if(linea_actual == num_linea)
        {
            if (i == memoria_actual)
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
