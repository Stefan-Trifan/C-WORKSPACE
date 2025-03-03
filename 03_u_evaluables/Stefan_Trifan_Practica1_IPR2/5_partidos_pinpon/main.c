/*
    *   Autor
        Stefan Trifan

    *   Estado
        Done

    *   Enunciado 5 
        Partidos de ping pong

    *   Testing
        
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>

#define TAM_STR 40
#define N_JUG 4
#define N_PARTIDOS 6

typedef struct jugador_t
{
    char nombre[TAM_STR];
    char apellidos[TAM_STR];
    int edad;
}
jugador_t;

typedef struct fecha_t
{
    int dia;
    int mes;
    int ano;
    int hora;
    int min;
}
fecha_t;

typedef struct partido_t
{
    jugador_t jugador1;
    jugador_t jugador2;
    fecha_t fecha_inicio;
}
partido_t;

// Funciones del programa

// Funciones auxiliares
void pedirCadena();
int pedirEnteroPos();
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main()
{
    printf("\n_________________________________________START\n\n");

    jugador_t arr_jugador[N_JUG]      = {0};
    fecha_t   fecha_inicio            = {0};
    partido_t arr_partido[N_PARTIDOS] = {0};

    // TODO pruebas
    char prueba_str[TAM_STR] = {0}; 
    
    int prueba_int = 0;
    prueba_int = pedirEnteroPos();
    printf("prueba: %d\n", prueba_int);

    // Pedimos los datos para cada jugador (4)
        // Nombre
        // Apellido
        // Edad
    
    // Pedimos dia/mes/año/hora/min del primer partido

    // Creamos los partidos
        // 1 - A con B
        // 2 - A con C
        // 3 - A con D
        // 4 - B con C
        // 5 - B con D
        // 6 - C con D

    printf("\n_________________________________________END\n\n");
    return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa

// Funciones auxiliares
void pedirCadena()
{

}

int pedirEnteroPos()
{
    int num = 0;
    return num;
}

void clearBuffer()
{
    while (getchar() != '\n');
}