/*
    *   Autor
        Stefan Trifan

    *   Estado

    *   Enunciado
        Lorem Ipsum
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_BLOQUE 10

typedef struct nombres_t
{
    int num_lineas;
    char **lineas;
} 
nombres_t;

// Funciones del programa

// Funciones auxiliares
char *mi_strcpy_dinamico(const char *origen);
char *leerFicheroDinamicoLinea(FILE *fd);
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    // Comprobamos que se han introducido los aprametros
    if(argc != 2)
    {
        printf("\033[1;31mUSO: ./main datos.txt\n");
        printf("\033[31m\n_________________________________________FAIL\n\n\033[0m");
        return EXIT_FAILURE;
    }

    // Declaracion de variables
    FILE *fd = fopen(argv[1], "r");
    nombres_t container_nombre;
    container_nombre.num_lineas = 0;
    container_nombre.lineas = (char **)malloc(sizeof(char*));

    // Comprobamos que el archivo se ha abierto correctamente
    if(fd == NULL)
    {
        printf("\033[1;31mERROR: Archivo no encontrado\n");
        printf("\033[31m\n_________________________________________FAIL\n\n\033[0m");
        return EXIT_FAILURE;
    }

    // Guardamos los nombres en la estructura nombre
    while(!feof(fd))
    {
        container_nombre.lineas = (char **)realloc(container_nombre.lineas, sizeof(char *) * (container_nombre.num_lineas + 1));
        container_nombre.lineas[container_nombre.num_lineas] = leerFicheroDinamicoLinea(fd);
        container_nombre.num_lineas++;
    }

    // Ordenamos la estructura nombre
    for(int i = 0; i < container_nombre.num_lineas - 1; i++)
    {
        for(int j = 0; j < container_nombre.num_lineas - i - 1; j++)
        {
            if(strcmp(container_nombre.lineas[j], container_nombre.lineas[j + 1]) > 0)
            {
                char *temp = container_nombre.lineas[j];
                container_nombre.lineas[j] = container_nombre.lineas[j + 1];
                container_nombre.lineas[j + 1] = temp;
            }
        }
    }

    // Mostramos el resultado por pantalla
    for(int i = 0; i < container_nombre.num_lineas; i++)
    {
        printf("%s \n", container_nombre.lineas[i]);
    }

    printf("\n_________________________________________EXIT\n\n");
    return EXIT_SUCCESS;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa

// Funciones auxiliares
char *leerFicheroDinamicoLinea(FILE *fd)
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
        p_texto_destino[i] = c;
        i++;
    }
    p_texto_destino[i] = '\0';

    return p_texto_destino;
}

char *mi_strcpy_dinamico(const char *origen)
{
    char *destino = NULL;
    int len;

    len = strlen(origen) + 1;
    destino = (char *)malloc(len * sizeof(char));
    if(destino)
    {
        strcpy(destino, origen);
    }
    
    return destino;
}

void clearBuffer()
{
    while (getchar() != '\n');
}