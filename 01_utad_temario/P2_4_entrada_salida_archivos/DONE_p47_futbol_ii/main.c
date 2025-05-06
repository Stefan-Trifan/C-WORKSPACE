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
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"
#define DIRECCION "datosjugadores.txt"

typedef enum
{
    AGREGAR = 1, MOSTRAR, GUARDAR, SALIR
}
opcion_t;

typedef struct
{
    char *nombre_completo;
    int num_camiseta;
    int num_goles;
} 
datos_jugador_t;

// Funciones del programa
void agregarJugador(datos_jugador_t **jugador, int *num_jugadores);
void mostrarGoleadores(datos_jugador_t *jugador, int num_jugadores);
void guardarJugadores(datos_jugador_t *jugador, int num_jugadores);
void liberarMemoria(datos_jugador_t *jugador, int num_jugadores);
void menu();

// Funciones auxiliares
char *pedirCadenaDinamica();
int pedirEnteroPos();
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    // Declaracion de variables
    datos_jugador_t *jugador;
    int opcion = 0;
    int num_jugadores = 0;

    // Introducimos jugadores
    do
    {
        menu();
        opcion = pedirEnteroPos();

        switch (opcion)
        {
            case AGREGAR: 
                agregarJugador(&jugador, &num_jugadores);

                // INICIO DEBUG
                printf(YELLOW"\n");
                printf("num_jugadores = %d\n\n", num_jugadores);
                for(int i = 0; i < num_jugadores; i++)
                {
                    printf("JUGADOR[%d]\n", i);
                    printf("nombre_completo: %s\n", (jugador + i)->nombre_completo);
                    printf("num_camiseta:    %d\n", (jugador + i)->num_camiseta);
                    printf("num_goles:       %d\n", (jugador + i)->num_goles);
                    printf("\n");
                }
                printf(RESET); 
                // FIN DEBUG

                break;
            case MOSTRAR: 
                mostrarGoleadores(jugador, num_jugadores);
                break;
            case GUARDAR: 
                guardarJugadores(jugador, num_jugadores);
                num_jugadores = 0;
                break;
            case SALIR: 
                guardarJugadores(jugador, num_jugadores);
                liberarMemoria(jugador, num_jugadores);
                printf("Saliendo del programa...\n");
                break;
        }
        printf("\n\n");
    } 
    while (opcion != 4);

    printf("\n_________________________________________EXIT\n\n");
    return EXIT_SUCCESS;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa

/**
 * 
 * Al introducir un jugador, se deberá pedir los datos (nombre/apellidos y goles) al usuario, 
 * y se deberá almacenar enuna lista reservada de forma dinámica.
 */
void agregarJugador(datos_jugador_t **jugador, int *num_jugadores)
{
    // Incrementamos el numero de jugadores
    (*num_jugadores)++;

    // Reservamos espacio para el nuevo jugador
    if(*num_jugadores == 1)
    {
        *jugador = malloc(sizeof(datos_jugador_t));
    }
    else if(*num_jugadores >= 2)
    {
        *jugador = realloc(*jugador, *num_jugadores * sizeof(datos_jugador_t));
    }

    // Configuramos el jugador
    printf("Introduce el nombre completo del jugador\n-> ");
    (*jugador + (*num_jugadores - 1))->nombre_completo = pedirCadenaDinamica();

    (*jugador + (*num_jugadores - 1))->num_camiseta = *num_jugadores;

    printf("Introduce el numero de goles\n-> ");
    (*jugador + (*num_jugadores - 1))->num_goles = pedirEnteroPos();
}

/**
 * Al elegir esta opción se guardarán en un fichero (datosjugadores.txt) 
 * los datos de los jugadores que se hayan introducido y no se hayan guardado previamente
 */
void guardarJugadores(datos_jugador_t *jugador, int num_jugadores)
{
    FILE *fd;

    fd = fopen(DIRECCION, "a");

    // Guardamos los nuevos jugadores
    if(num_jugadores >= 1)
    {
        for(int i = 0; i < num_jugadores; i++)
        {
            fprintf(
                fd,
                "%s,%d,%d\n", 
                (jugador + i)->nombre_completo, 
                (jugador + i)->num_camiseta, 
                (jugador + i)->num_goles);
        }
        printf(GREEN"Se han guardados los nuevos jugadores\n"RESET);
    }
    else
    {
        printf(GREEN"No hay mas jugadores que agregar\n"RESET);
    }
    
    // Reseteamos la estructura
    for(int i = 0; i < num_jugadores; i++)
    {
        (jugador + i)->nombre_completo = NULL;
        (jugador + i)->num_camiseta = 0;
        (jugador + i)->num_goles = 0;
    }
    
    fclose(fd);
}

/**
 * Al elegir esta opción, se pedirá un número de goles mínimo al usuario, y se deberán 
 * mostrar todos los jugadores almacenados anteriormente con un número de goles superior al introducido.
 */
void mostrarGoleadores(datos_jugador_t *jugador, int num_jugadores)
{
    int num_goles_minimo;

    printf("Cual es el minimo de goles?\n-> ");
    num_goles_minimo = pedirEnteroPos();
    for(int i = 0; i < num_jugadores; i++)
    {
        if((jugador + i)->num_goles >= num_goles_minimo)
        {
            printf("\n");
            printf("nombre_completo: %s\n", (jugador + i)->nombre_completo);
            printf("num_camiseta:    %d\n", (jugador + i)->num_camiseta);
            printf("num_goles:       %d\n", (jugador + i)->num_goles);
            printf("\n");
        }
    }
}

void liberarMemoria(datos_jugador_t *jugador, int num_jugadores)
{
    for(int i = 0; i < num_jugadores; i++)
    {
        free(jugador[i].nombre_completo);
    }
}

void menu()
{
    printf(
        "============== Selecciona una opcion ==============\n"
        "[1] Introducir Jugador\n"
        "[2] Mostrar Goleadores\n"
        "[3] Guardar\n"
        "[4] Salir\n"
        "-> ");
}

// Funciones auxiliares
char *pedirCadenaDinamica()
{
    char *p_texto_destino = malloc(sizeof(char) * TAM_BLOQUE);
    char c;
    int i = 0;
    int memoria_actual = TAM_BLOQUE;

    while ((c = getchar()) != '\n')
    {
        if (i == memoria_actual)
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

int pedirEnteroPos()
{
    int num = 0, esValido = 0;
    do
    {
        esValido = scanf("%d", &num);
        clearBuffer();
        if (esValido == 0 || num < 0)
        {
            printf("\033[1;31mERROR: El tipo de dato introducido no es válido.\n"
                   "-> \033[0m");
            esValido = 0;
        }
    } while (esValido != 1);
    return num;
}

void clearBuffer()
{
    while (getchar() != '\n')
        ;
}