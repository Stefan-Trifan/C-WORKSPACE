/*
    *   Autor
        Stefan Trifan

    *   Estado

    *   Enunciado
        Tomar un archivo de texto y con la funcion fgetc() leer todo su contenido

        fgetc(puntero_archivo);
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
char *leerCadenaDinamicaFichero(FILE *fd);
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    // Declaracion de variables
    FILE *fd;
    char *p_contenido_fichero;

    // Abrimos el archivo
    fd = fopen(DIRECCION, "r");

    // Probamos fgetc
    p_contenido_fichero = leerCadenaDinamicaFichero(fd);

    printf("%s", p_contenido_fichero);

    printf("\n_________________________________________EXIT\n\n");
    return EXIT_SUCCESS;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa

// Funciones auxiliares
char *leerCadenaDinamicaFichero(FILE *fd)
{
    char *p_texto_destino = malloc(sizeof(char) * TAM_BLOQUE);
    int memoria_actual = TAM_BLOQUE;
    int i = 0;
    char c;

    while ((c = fgetc(fd)) != EOF)
    {
        if (i == memoria_actual - 1)
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

void clearBuffer()
{
    while (getchar() != '\n');
}