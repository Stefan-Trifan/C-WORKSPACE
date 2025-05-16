/**
 * Autor: Stefan Trifan
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"

#define TAM_BLOQUE 10

// Declaracion de funciones
char *generaNombreSalida(char *nombreEntrada);

// Funciones auxiliares
char *leeLineaDinamicaFichero(FILE *fd, int num_linea);

int main(int argc, char *argv[])
{
    printf("\n____________________________________START\n\n");

    if (argc = 2)
    {
        printf(RED "Error: Tienes que introducir el nombre del archivo\n" RESET);
        printf("\033[31m\n_________________________________________FAIL\n\n\033[0m");
        return EXIT_FAILURE;
    }

    // Configuramos el nombre del archivo de entrada
    char *direccion_fichero_entrada = (char *)malloc(sizeof(char) * strlen(argv[1]));
    strcpy(direccion_fichero_entrada, argv[1]);

    // Declaracion de variables
    char *direccion_fichero_salida;
    FILE *fd_in = fopen(direccion_fichero_entrada, "r");
    char *fila_actual;
    int num_lineas_fichero;

    // Comprobamos que el archivo se ha abierto correctamente
    if (fd_in == NULL)
    {
        printf(RED "Error: No se ha podido encontrar el archivo\n" RESET);
        printf("\033[31m\n_________________________________________FAIL\n\n\033[0m");
        return EXIT_FAILURE;
    }

    // Generamos el nombre del fichero de salida
    direccion_fichero_salida = generaNombreSalida(direccion_fichero_entrada);

    // Construimos el archivo de salida con la extension .out
    FILE *fd_out = fopen(direccion_fichero_salida, "w");

    // Contamos el numero de filas
    char c = fgetc(fd_in);
    if (c != EOF)
    {
        num_lineas_fichero++;
    }
    while ((c = fgetc(fd_in)) != EOF)
    {
        if (c == '\n')
        {
            num_lineas_fichero++;
        }
    }

    // Recorremos cada una de las filas para procesarlas
    for (int i = 1; i <= num_lineas_fichero; i++)
    {
        char etiqueta[50];
        char contenido[100];

        // Extraemos el valor de las etiquetas
        fila_actual = leeLineaDinamicaFichero(fd_in, i);

        strcpy(etiqueta, strstr(fila_actual, ">"));
        strcpy(etiqueta, strtok(fila_actual, ">"));
        strcpy(etiqueta, strtok(fila_actual, "<"));

        // Extraemos el contenido de las etiquetas
        fila_actual = leeLineaDinamicaFichero(fd_in, i);

        strcpy(contenido, strtok(fila_actual, "<"));
        strcpy(contenido, strstr(fila_actual, ">")); 
        contenido[0] = ' ';

        // Imprimimos en pantalla la etiqueta y el contenido
        printf("Etiqueta: %s\n", etiqueta);
        printf("Contenido:%s\n\n", contenido);

        // Escribimos en el archivo solamente el contenido de las etiquetas
        fprintf(fd_out, "%s\n", contenido);
    }

    free(direccion_fichero_entrada);
    free(direccion_fichero_salida);
    fclose(fd_in);
    fclose(fd_out);

    printf("\n____________________________________START\n\n");
}

// Declaracion de funciones
/**
 * Función para generar nombre de salida con extensión .out
 */
char *generaNombreSalida(char *nombreEntrada)
{
    char *nombre_salida = (char *)malloc(sizeof(char) * strlen(nombreEntrada));

    // Copiamos el nombre original
    if (nombre_salida)
    {
        strcpy(nombre_salida, nombreEntrada);
    }

    // Quitamos la extension .txt
    nombre_salida = strtok(nombre_salida, ".");

    // Aniadimos la extension .out
    strcat(nombre_salida, ".out");

    return nombre_salida;
}

// Funciones auxiliares
/**
 * Lee una línea almacenada en memoria dinámica
 * usando getc o fgetc
 */
char *leeLineaDinamicaFichero(FILE *fd, int num_linea)
{
    char *p_cadena_destino = (char *)malloc(sizeof(char) * TAM_BLOQUE);
    int memoria_actual = TAM_BLOQUE;
    int linea_actual = 1;
    int i = 0;
    char c;

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
                p_cadena_destino = (char *)realloc(p_cadena_destino, sizeof(char) * memoria_actual);
            }
            p_cadena_destino[i] = c;
            i++;
        }
    }
    p_cadena_destino[i] = '\0';

    rewind(fd);

    return p_cadena_destino;
}