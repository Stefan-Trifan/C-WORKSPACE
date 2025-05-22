/*
    *   Autor
        Stefan Trifan
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIRECCION "datos.txt"
#define TAM_BLOQUE 10
#define ANO_ACTUAL 2025

typedef struct
{
    int i_alumnos;
    char **nombre;
    char **apellido;
    int *edad;
}
container_alumnos_t;

// Funciones del programa

// Funciones auxiliares
char *leerFicheroDinamicoLinea(FILE *fd);
char *pedirCadenaDinamica();
int pedirEntero();
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    // Declaracion de variables
    FILE *fd = fopen(DIRECCION, "w+");
    container_alumnos_t c_alumno;
    int seguir;

    // Inicializamos variables
    c_alumno.i_alumnos = 0;
    c_alumno.nombre    = (char **)malloc(sizeof(char *));
    c_alumno.apellido  = (char **)malloc(sizeof(char *));
    c_alumno.edad      = (int   *)malloc(sizeof(int));
    seguir             = 0;

    // Comprobamos que el archivo se abrio correctamente
    if(fd == NULL)
    {
        printf("\033[31mERROR: No fue posible abrir el archivo\n\033[0m");
        printf("\033[31m\n_________________________________________FAIL\n\n\033[0m");
        return EXIT_FAILURE;
    }

    // Solicita al usuario por teclado el nombre, el primer apellido y la edad de alumnos
    // El usuario puede estar introduciendo alumnos hasta que él lo determine
    do
    {
        // Pedimos el nombre
        printf("Introduce el nombre\n-> ");
        c_alumno.nombre[c_alumno.i_alumnos] = pedirCadenaDinamica();
        // Escribimos la info en el fichero
        fprintf(fd, "%s;", c_alumno.nombre[c_alumno.i_alumnos]);

        // Pedimos el apellido
        printf("Introduce el apellido\n-> ");
        c_alumno.apellido[c_alumno.i_alumnos] = pedirCadenaDinamica();
        // Escribimos la info en el fichero
        fprintf(fd, "%s;", c_alumno.apellido[c_alumno.i_alumnos]);
        
        // Pedimos la edad
        printf("Introduce la edad\n");
        c_alumno.edad[c_alumno.i_alumnos] = pedirEntero();
        // Escribimos la info en el fichero
        fprintf(fd, "%d", c_alumno.edad[c_alumno.i_alumnos]);

        printf("Seguimos? [1] = Si [0] = No\n");
        do
        {
            seguir = pedirEntero();
        } 
        while (seguir != 1 && seguir != 0);

        if(seguir)
        {
            fprintf(fd, "\n");
            c_alumno.i_alumnos++; 
            c_alumno.nombre   = (char **)realloc(c_alumno.nombre,   sizeof(char *) * (c_alumno.i_alumnos + 1));
            c_alumno.apellido = (char **)realloc(c_alumno.apellido, sizeof(char *) * (c_alumno.i_alumnos + 1));
            c_alumno.edad     = (int *)realloc(c_alumno.edad,     sizeof(int)    * (c_alumno.i_alumnos + 1));
        }
    } 
    while (seguir);

    // Para acabar se debe sacar la información del fichero y presentarla por el monitor con el siguiente formato
    rewind(fd);
    while(!feof(fd)) 
    {
        char *linea    = leerFicheroDinamicoLinea(fd);
        char *nombre   = strtok(linea, ";");
        char *apellido = strtok(NULL, ";");
        int  edad      = atoi(strtok(NULL, ";"));

        printf("El alumno %s, %s nació el año %d\n", apellido, nombre, ANO_ACTUAL - edad);
        free(linea);
    }

    // Liberamos memoria y cerramos fd
    fclose(fd);
    for(int i = 0; i < c_alumno.i_alumnos; i++)
    {
        free(c_alumno.nombre[i]);
        free(c_alumno.apellido[i]);
    }
    free(c_alumno.nombre);
    free(c_alumno.apellido);
    free(c_alumno.edad);

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

char *pedirCadenaDinamica()
{
    char *p_texto_destino = malloc(sizeof(char) * TAM_BLOQUE);
    char c;
    int i = 0;
    int memoria_actual = TAM_BLOQUE;

    while ((c = getchar()) != '\n')
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

int pedirEntero()
{
    int num = 0, esValido = 0;
    printf("-> ");
    do
    {
        esValido = scanf("%d", &num);
        clearBuffer();
        if(!esValido || num < 0)
        {
            printf(
                "\033[1;31mERROR: El tipo de dato introducido no es válido.\n"
                "-> \033[0m"
            );
            esValido = 0;
        }
    } 
    while (!esValido);

    return num;
}

void clearBuffer()
{
    while (getchar() != '\n');
}



/* 
    printf("c_alumno.nombre[0]   = %s\n", c_alumno.nombre[0]);
    printf("c_alumno.apellido[0] = %s\n", c_alumno.apellido[0]);
    printf("c_alumno.edad[0]     = %d\n", c_alumno.edad[0]);
    printf("c_alumno.nombre[1]   = %s\n", c_alumno.nombre[1]);
    printf("c_alumno.apellido[1] = %s\n", c_alumno.apellido[1]);
    printf("c_alumno.edad[1]     = %d\n", c_alumno.edad[1]); */