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

// Funciones del programa

// Funciones auxiliares
char *leerFicheroDinamicoLinea(FILE *fd, int num_linea);
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    // Declaracion de variables
    FILE *fd;
    char *contenido_fichero;

    // Abrimos el fichero
    fd = fopen(DIRECCION, "r");

    // Leemos el fichero
    contenido_fichero = leerFicheroDinamicoLinea(fd, 4);

    printf("%s", contenido_fichero);

    printf("\n_________________________________________EXIT\n\n");
    return EXIT_SUCCESS;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa

// Funciones auxiliares
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
        if(c == '\n')
        {
            linea_actual++;
        }
        else if(linea_actual == num_linea)
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