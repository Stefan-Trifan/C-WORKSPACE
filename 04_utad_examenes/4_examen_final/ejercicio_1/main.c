/**
 *  Nombre:
 *      Stefan Trifan
 * 
 * Hora Inicio:
 *      09: 30
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DIRECCION "precipitacionesMadrid2024.txt"
#define TAM_BLOQUE 10
#define CANTIDAD_MESES 12

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"

// Funciones del programa
char* leeLineaDinamicaFichero(FILE *fd);
float obtenerPrecipitacion( char *cadena);
// Inicializamos una nueva instancia de la estructra. Reservamos memoria
// Funciones auxiliares
void clearBuffer();

/*  ____________________________________________
    Inicio main*/

int main(int argc, char *argv[])
{
    printf("________________________________________START\n\n");
    
    // Declaracion de variables
    FILE *fd = fopen(DIRECCION, "r+");
    float valores_precipitaciones[CANTIDAD_MESES] = {0};
    char *cadena;
    float precipitacion_min = 0,
          precipitacion_med = 0,
          precipitacion_max = 0;

    // Comprobamos que el archivo se ha abierto bien
    if(fd == NULL)
    {
        printf("\033[1;31mERROR: No ha sido posible encontrar el fichero\n\033[0m");
        printf("\033[31m\n_________________________________________FAIL\n\n\033[0m");
        return EXIT_FAILURE;
    }
    else
    {
        printf("\033[1;32mArchivo abieto correctamente\n\n\033[0m");
    }

    // Extraer del fichero los valores mensuales de precipitaciones.
    for(int i = 0; i < CANTIDAD_MESES + 1; i++)
    {
        // Vamos guardando uno por uno los valores de las precipitaciones 
        // en nuestro array de flotantes
        if(i >= 1)
        {
            valores_precipitaciones[i - 1] = obtenerPrecipitacion(leeLineaDinamicaFichero(fd));
        }
        else if(i == 0)
        {
            cadena = leeLineaDinamicaFichero(fd); // Condicion para que ignore la primera linea
        }
    }

    // Ordenamos los valores del array de menor a mayor mediante el algorimo de ordenacion BURBUJA
    for(int i = 0; i < CANTIDAD_MESES - 1; i++)
    {
        for(int j = 0; j < CANTIDAD_MESES - 1 - i; j++)
        {
            if(valores_precipitaciones[j] > valores_precipitaciones[j + 1])
            {
                float temp = valores_precipitaciones[j];
                valores_precipitaciones[j] = valores_precipitaciones[j + 1];
                valores_precipitaciones[j + 1] = temp;
            }
        }
    }

    // Calcular el mes de precipitaciones máximas, mínimas y la media de precipitaciones anuales.
    precipitacion_min = valores_precipitaciones[0];
    precipitacion_max = valores_precipitaciones[CANTIDAD_MESES - 1];
    for(int i = 0; i < CANTIDAD_MESES; i++)
    {
        precipitacion_med += valores_precipitaciones[i];
    }
    precipitacion_med /= CANTIDAD_MESES;

    // Presentar por pantalla cada uno de los valores calculados anteriormente
    printf
    (   
        "Mes de máxima precipitación:   \033[1;32m %.2f l/m²\033[0m\n"
        "Mes de mínima precipitación:   \033[1;32m %.2f l/m²\033[0m\n"
        "Media anual de precipitaciones:\033[1;32m %.2f l/m²\033[0m\n" 
        ,precipitacion_max, precipitacion_min, precipitacion_med
    );

    // Agregar al final del fichero las líneas con los datos estadísticos calculados 
    // (Mes con precipitaciones máximas, mínimas y media de precipitaciones).
    fprintf
    (
        fd, 
        "\n"
        "Mes de máxima precipitación:    %.2f l/m²\n"
        "Mes de mínima precipitación:    %.2f l/m²\n"
        "Media anual de precipitaciones: %.2f l/m²\n"
        ,precipitacion_max, precipitacion_min, precipitacion_med
    );

    // Cerrar fd
    fclose(fd);

    printf("\n________________________________________END\n\n");
    return EXIT_SUCCESS;
}

/*  ____________________________________________
    Inicio declaracion de funciones */

// Funciones del programa
/**
 * Función que de una línea que se le pasa como 
 * parámetro se extrae el valor las precipitaciones
 */
float obtenerPrecipitacion(char *cadena)
{
    // Declaracion de variables
    float valor_precipitacion;

    // Cuerpo funcion
    strtok(cadena, ";");
    valor_precipitacion = atof(strtok(NULL, " ("));

    return valor_precipitacion;
}

// Funciones auxiliares
/**
 * Devuelve una línea del fichero que se pasa como 
 * parámetro utilizando la función getc o fgetc y 
 * reservando memoria dinamica 
 */
char *leeLineaDinamicaFichero(FILE *fd)
{
    // Declaracion de variables
    char *destino = (char *)malloc(sizeof(char) * TAM_BLOQUE);
    int memoria_actual = TAM_BLOQUE;
    int i = 0;
    char c;

    // Cuerpo funcion
    while(((c = fgetc(fd)) != EOF) && (c != '\n'))
    {
        if(i == memoria_actual - 1)
        {
            memoria_actual += TAM_BLOQUE;
            destino = (char *)realloc(destino, sizeof(char) * memoria_actual);
        }
        destino[i] = c;
        i++;
    }
    destino[i] = '\0';

    return destino;
}

void clearBuffer() 
{
    while(getchar() != '\n');
}