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
#define NOMBRE_ARCHIVO "emails.txt"

typedef struct
{
    char *nombre;
    char *apellidos;
    char *email;
}
datos_t;

// Funciones del programa

// Funciones auxiliares
char *pedirCadenaDinamica();
int pedirEntero();
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    // Declaracion de variables
    FILE *fd;
    datos_t datos;
    int opcion = 0;
    int num_users = 0;
    
    // Abrimos el archivo
    fd = fopen(NOMBRE_ARCHIVO, "a+");
    if(fd == NULL)
    {
        printf("Error.\n");
        printf("\033[31m\n_________________________________________FAIL\n\n\033[0m");
        return EXIT_FAILURE;
    }

    // Empezamos a escribir datos
    do
    {
        printf("Introduce tu nombre\n-> ");
        datos.nombre = pedirCadenaDinamica();
        printf("Introduce tu apellido\n-> ");
        datos.apellidos = pedirCadenaDinamica();
        printf("Introduce tu email\n-> ");
        datos.email = pedirCadenaDinamica();

        fprintf(fd, "%s,%s,%s\n", datos.nombre, datos.apellidos, datos.email);
        
        // Guardamos los cambios inmediatamente
        fclose(fd);
        fd = fopen(NOMBRE_ARCHIVO, "a+");

        printf("Deseas continuar?\n[1] Si\n[0] No\n-> ");
        opcion = pedirEntero();
    } 
    while (opcion != 0);

    fclose(fd);

    printf("\n_________________________________________EXIT\n\n");
    return EXIT_SUCCESS;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa

// Funciones auxiliares
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
    do
    {
        esValido = scanf("%d", &num);
        clearBuffer();
        if (esValido == 0)
        {
            printf(
                "\033[1;31mERROR: El tipo de dato introducido no es válido.\n"
                "-> \033[0m"
            );
            esValido = 0;
        }
    }
    while (esValido != 1);
    return num;
}

void clearBuffer()
{
    while (getchar() != '\n');
}