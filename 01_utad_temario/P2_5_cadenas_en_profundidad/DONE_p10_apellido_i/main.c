/*
    *   Autor
        Stefan Trifan

    *   Estado

    *   Enunciado
        ./main Trifan
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_BLOQUE 10

// Funciones del programa
char *convertir_a_mayus(char *cadena);
char *convertir_a_minus(char *cadena);

// Funciones auxiliares
char *mi_strdup(const char *origen);
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    // TODO recibir nombre_completo por linea de comandos
    if(argc != 2)
    {
        printf("\033[31m\n_________________________________________FAIL\n\n\033[0m");
        return EXIT_FAILURE;
    }

    // Declaramos las variables
    char *nombre_completo;
    char *nombre_mayus;
    char *nombre_minus;

    // Guardamos los nombres en las variables
    nombre_completo = mi_strdup(argv[1]);

    nombre_mayus = mi_strdup(nombre_completo);
    nombre_minus = mi_strdup(nombre_completo);

    // Convertimos
    convertir_a_mayus(nombre_mayus);
    nombre_minus = convertir_a_minus(nombre_completo);

    // Imprimmos los apellidos en mayuscula y en minuscula
    printf("nombre_completo: %s\n", nombre_completo);
    printf("nombre_mayus: %s\n", nombre_mayus);
    printf("nombre_minus: %s\n", nombre_minus);

    printf("\n_________________________________________EXIT\n\n");
    return EXIT_SUCCESS;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa
char *convertir_a_mayus(char *cadena)
{
    int i = 0;

    while((cadena[i]) != '\0')
    {
        if(cadena[i] >= 'a' && cadena[i] <= 'z')
        {
            cadena[i] -= 32;
        }
        i++;
    }

    return cadena;
}

char *convertir_a_minus(char *cadena)
{
    int i = 0;

    while((cadena[i]) != '\0')
    {
        if(cadena[i] >= 'A' && cadena[i] <= 'Z')
        {
            cadena[i] += 32;
        }
        i++;
    }

    return cadena;
}

// Funciones auxiliares
char *mi_strdup(const char *origen)
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