/*
    *   Autor
        Stefan Trifan
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Definiciones */
typedef struct
{
    char *linea;
} linea_t;

/* Funciones del programa */
char *leerLinea(FILE *f);
void procesarLinea(char *linea, FILE *salida, int max_chars);
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    // Variables
    FILE *entrada;
    FILE *salida;
    char *linea;
    int max_chars;

    // Comprobamos que se pasan los tres argumentos
    if (argc != 4)
    {
        printf("Error: Debes pasar el fichero de entrada, salida y número de caracteres\n");
        return EXIT_FAILURE;
    }

    // Convertimos el tercer argumento a entero
    max_chars = atoi(argv[3]);

    // Abrimos los ficheros
    entrada = fopen(argv[1], "r");
    salida = fopen(argv[2], "w");

    // Procesamos el fichero línea por línea
    while ((linea = leerLinea(entrada)) != NULL)
    {
        procesarLinea(linea, salida, max_chars);
        free(linea);
    }

    // Cerramos los ficheros
    fclose(entrada);
    fclose(salida);

    printf("\n_________________________________________EXIT\n\n");
    return EXIT_SUCCESS;
}

/* _________________________________________
   Inicio definicion de funciones */

// Leer una línea completa del fichero
// Uso malloc y realloc para que la memoria crezca a medida que leo
char *leerLinea(FILE *f)
{
    int tam = 10, i = 0;
    char *linea;
    char c;

    linea = (char *)malloc(tam * sizeof(char));

    while ((c = fgetc(f)) != EOF)
    {
        linea[i++] = c;

        // Si se llena la memoria, la agrando
        if (i == tam)
        {
            tam += 10;
            linea = (char *)realloc(linea, tam * sizeof(char));
        }

        // Si encuentro espacio seguido de salto de línea, corto la lectura
        if (c == ' ')
        {
            c = fgetc(f);
            if (c == '\n' || c == EOF)
            {
                linea[i++] = '\n';
                break;
            }
            else
            {
                linea[i++] = c;
            }
        }
    }

    if (i == 0)
    {
        free(linea);
        return NULL;
    }

    linea[i] = '\0';
    return linea;
}

// procesar cada línea
// Si la línea es más larga que max_chars, la corto en partes
void procesarLinea(char *linea, FILE *salida, int max_chars)
{
    int len = strlen(linea);
    int i = 0;
    int k;
    char *parte;

    parte = (char *)malloc((max_chars + 2) * sizeof(char)); // Para el guión y el '\n'

    while (i < len)
    {
        k = 0;

        // Copio hasta max_chars caracteres
        while (k < max_chars && i < len)
        {
            parte[k++] = linea[i++];
        }

        // Si corto en medio de una palabra, agrego un guión
        if (i < len && parte[k - 1] != ' ' && linea[i] != ' ')
        {
            parte[k - 1] = '-';
        }

        parte[k++] = '\n';
        parte[k] = '\0';

        // Escribo la parte al fichero de salida
        fputs(parte, salida);

        // Si el siguiente caracter es espacio, lo salto
        if (i < len && linea[i] == ' ')
        {
            i++;
        }
    }

    free(parte);
}

// Función para limpiar el buffer de entrada
void clearBuffer()
{
    while (getchar() != '\n')
        ;
}
