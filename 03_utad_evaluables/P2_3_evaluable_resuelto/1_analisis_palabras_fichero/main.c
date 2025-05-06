/*
    *   Autor
        Stefan Trifan

    *   Testing
        ./main datos.txt Hola
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_BLOQUE 10
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"

// Estructura para almacenar la información de las palabras que se van a buscar
typedef struct
{
    char *palabra;
    int num_ocurrencias;
    int *numeros_de_linea;
} palabra_info_t;

// Estructura para almacenar la lista de información
typedef struct
{
    palabra_info_t *palabra_info;
    int num_palabras;
} caja_palabras_t;

// Funciones del programa
void examinaLinea(char *linea_aux, int num_linea, caja_palabras_t caja_palabras);
void escribirResultado(caja_palabras_t caja_palabras, char *nombre_fichero_origen);

// Funciones auxiliares
char *leerLineaDinamicaFichero(FILE *fd);
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    // Declaracion de variables
    caja_palabras_t caja_palabras;
    FILE *fd_in;
    FILE *fd_out;
    char *nombre_fichero_salida;
    int num_lineas = 0;

    // Comprobamos el numero de parametros
    if (argc < 3)
    {
        fprintf(stderr, RED "Error. Uso: ./main <Nombre de fichero> <Palabras a buscar>\n" RESET);
        printf("\033[31m\n_________________________________________FAIL\n\n\033[0m");
        return EXIT_FAILURE;
    }

    // Comprobamos si el archivo existe
    fd_in = fopen(argv[1], "r");
    if (fd_in == NULL)
    {
        fprintf(stderr, RED "ERROR: El archivo no se ha encontrado" RESET);
        printf("\033[31m\n_________________________________________FAIL\n\n\033[0m");
        return EXIT_FAILURE;
    }

    // Creamos el nombre del archivo de salida
    nombre_fichero_salida = malloc((strlen(argv[1]) + 10) * sizeof(char));
    char *punto = strrchr(argv[1], '.');
    if (punto != NULL)
    {
        strncpy(nombre_fichero_salida, argv[1], punto - argv[1]);
        nombre_fichero_salida[punto - argv[1]] = '\0';
        strcat(nombre_fichero_salida, ".out");
        strcat(nombre_fichero_salida, punto);
    }
    else
    {
        strcpy(nombre_fichero_salida, argv[1]);
        strcat(nombre_fichero_salida, ".out");
    }
    fd_out = fopen(nombre_fichero_salida, "w");

    // Iniciamos la lista de palabras
    caja_palabras.num_palabras = argc - 2;
    caja_palabras.palabra_info = malloc(caja_palabras.num_palabras * sizeof(palabra_info_t));
    for (int i = 0; i < caja_palabras.num_palabras; i++)
    {
        caja_palabras.palabra_info[i].palabra = malloc(sizeof(char) * (strlen(argv[i + 2]) + 1));
        strcpy(caja_palabras.palabra_info[i].palabra, argv[i + 2]);
        caja_palabras.palabra_info[i].num_ocurrencias = 0;
        caja_palabras.palabra_info[i].numeros_de_linea = NULL;
    }

    // Volvemos al principio del archivo
    fseek(fd_in, 0, SEEK_SET);

    // Procesamos el fichero línea por línea
    int num_linea = 1;
    while (!feof(fd_in))
    {
        char *linea = leerLineaDinamicaFichero(fd_in);
        if (linea[0] != '\0')
        {
            examinaLinea(linea, num_linea, caja_palabras);
            num_linea++;
        }
        free(linea);
    }

    fclose(fd_in);

    // Escribimos los resultados
    escribirResultado(caja_palabras, nombre_fichero_salida);

    // Liberamos memoria
    for (int i = 0; i < caja_palabras.num_palabras; i++)
    {
        free(caja_palabras.palabra_info[i].palabra);
        free(caja_palabras.palabra_info[i].numeros_de_linea);
    }
    free(caja_palabras.palabra_info);
    free(nombre_fichero_salida);

    printf(GREEN "\n_________________________________________EXIT\n\n" RESET);
    return EXIT_SUCCESS;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa

void examinaLinea(char *linea_aux, int num_linea, caja_palabras_t caja_palabras)
{
    for (int i = 0; i < caja_palabras.num_palabras; i++)
    {
        char *posicion = linea_aux;
        while ((posicion = strstr(posicion, caja_palabras.palabra_info[i].palabra)) != NULL)
        {
            caja_palabras.palabra_info[i].num_ocurrencias++;
            caja_palabras.palabra_info[i].numeros_de_linea = realloc(caja_palabras.palabra_info[i].numeros_de_linea, caja_palabras.palabra_info[i].num_ocurrencias * sizeof(int));
            caja_palabras.palabra_info[i].numeros_de_linea[caja_palabras.palabra_info[i].num_ocurrencias - 1] = num_linea;
            posicion += strlen(caja_palabras.palabra_info[i].palabra);
        }
    }
}

void escribirResultado(caja_palabras_t caja_palabras, char *nombre_fichero_origen)
{
    FILE *fd_out = fopen(nombre_fichero_origen, "w");
    if (fd_out == NULL)
    {
        fd_out = stdout; // Si falla, escribe en salida estándar
    }

    for (int i = 0; i < caja_palabras.num_palabras; i++)
    {
        fprintf(fd_out, "%s. Numero de ocurrencias: %d. Lineas:", caja_palabras.palabra_info[i].palabra, caja_palabras.palabra_info[i].num_ocurrencias);
        for (int j = 0; j < caja_palabras.palabra_info[i].num_ocurrencias; j++)
        {
            fprintf(fd_out, " %d", caja_palabras.palabra_info[i].numeros_de_linea[j]);
        }
        fprintf(fd_out, "\n");
    }

    if (fd_out != stdout)
        fclose(fd_out);
}

// Funciones auxiliares

char *leerLineaDinamicaFichero(FILE *fd)
{
    char *p_texto_destino = malloc(sizeof(char) * TAM_BLOQUE);
    int memoria_actual = TAM_BLOQUE;
    int i = 0;
    char c;

    while ((c = fgetc(fd)) != EOF && c != '\n')
    {
        if (i == memoria_actual - 1)
        {
            memoria_actual += TAM_BLOQUE;
            p_texto_destino = realloc(p_texto_destino, memoria_actual * sizeof(char));
        }
        p_texto_destino[i++] = c;
    }
    p_texto_destino[i] = '\0';

    return p_texto_destino;
}

void clearBuffer()
{
    while (getchar() != '\n')
        ;
}
