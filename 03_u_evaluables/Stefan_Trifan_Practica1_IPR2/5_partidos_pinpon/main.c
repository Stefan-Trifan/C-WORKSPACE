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

#define TAM_STR 21
#define N_JUG 4
#define N_PARTIDOS 6
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"

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
void pedirCadena(char text[]);
int pedirEnteroPos();
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main()
{
    printf("\n_________________________________________START\n\n");

    jugador_t lista_jugadores[N_JUG]     = {0};
    fecha_t   fecha_inicio               = {0};
    partido_t lista_partidos[N_PARTIDOS] = {0};
    
    /// Pedimos los datos para cada jugador (4)
    printf("===== DATOS JUGADORES =====\n\n");
    for(int i = 0; i < N_JUG; i++)
    {
        // Nombre
        printf(
            "JUGADOR %d - Ingrese el nombre\n"
            "(max. %d caracteres) -> ", i + 1, TAM_STR - 1);
        pedirCadena((lista_jugadores + i)->nombre);
        printf("\n");    
        // Apellido
        printf(
            "JUGADOR %d - Ingrese apellidos\n"
            "(max. %d caracteres) -> ", i + 1, TAM_STR - 1);
        pedirCadena((lista_jugadores + i)->nombre);
        printf("\n");    
        // Edad
        printf(
            "JUGADOR %d - Ingrese la edad\n"
            "-> ", i + 1);
        (lista_jugadores + i)->edad = pedirEnteroPos();
        printf("\n");  
    }

    printf("===== FECHA DEL TORNEO =====\n\n");

    /// Pedimos dia/mes/año/hora/min del primer partido
    /// Dia
    printf("Ingrese el dia\n-> ");
    do
    {
        fecha_inicio.dia = pedirEnteroPos();
        if(fecha_inicio.dia > 31)
            printf(YELLOW"ALERTA: Dia no puede ser superior a 31\n-> "RESET);
    } 
    while (fecha_inicio.dia > 31);
    printf("\n");  

    /// Mes
    printf("Ingrese el mes\n-> ");
    do
    {
        fecha_inicio.mes = pedirEnteroPos();
        if(fecha_inicio.mes > 12)
            printf(YELLOW"ALERTA: Mes no puede ser superior a 12\n-> "RESET);
    } 
    while (fecha_inicio.mes > 12);
    printf("\n");

    /// Anio
    printf("Ingrese el anio\n-> ");
    do
    {
        fecha_inicio.ano = pedirEnteroPos();
        if(fecha_inicio.ano <= 2025 || fecha_inicio.ano > 2100)
            printf(YELLOW"ALERTA: Anio no puede ser superior a 2100\n-> "RESET);
    } 
    while (fecha_inicio.ano <= 2025 || fecha_inicio.ano > 2100);
    printf("\n");

    /// Hora
    printf("Ingrese la hora de inicio\n-> ");
    do
    {
        fecha_inicio.hora = pedirEnteroPos();
        if(fecha_inicio.hora >= 24)
            printf(YELLOW"ALERTA: Horas no puede ser superior a 23\n-> "RESET);
    } 
    while (fecha_inicio.hora >= 24);
    printf("\n");

    /// Min
    printf("Ingrese el min de inicio\n-> ");
    do
    {
        fecha_inicio.min = pedirEnteroPos();
        if(fecha_inicio.min >= 60)
            printf(YELLOW"ALERTA: Minutos no puede ser superior a 59\n-> "RESET);
    } 
    while (fecha_inicio.min >= 60);
    
    printf("\n\n");
    // DEBUG imprimimos todos
    

    /// Creamos los partidos
        /// 1 - A con B
        /// 2 - A con C
        /// 3 - A con D
        /// 4 - B con C
        /// 5 - B con D
        /// 6 - C con D

    printf("\n_________________________________________END\n\n");
    return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa

// Funciones auxiliares
/*  DEBUG
    entrada:rojo\n
        i: 4
        c: o
  text[i]: o
*/
void pedirCadena(char text[])
{
    int esValido, i;
    char c;
    do
    {
        esValido = 1;
        i = 0;
        while(i < TAM_STR - 1)
        {
            c = getchar();

            if(c == '\n') break;
        
            text[i] = c;
            i++;
        }
        text[i] = '\0';

        if(i == TAM_STR - 1 )
        {
            c = getchar();
            if(c != '\n')
            {
                printf(YELLOW
                    "ALERTA: Has superado el limite de %d caracteres\n"
                    "-> "RESET, TAM_STR - 1);
                clearBuffer();
                esValido = 0;
            }
        }
    } 
    while (esValido != 1);
}

int pedirEnteroPos()
{
    int num = 0, esValido = 0;
    do
    {
        esValido = scanf("%d", &num);
        clearBuffer();
        if(esValido != 1 || num < 0)
        {
            printf(YELLOW
                "ALERTA: El numero debe ser mayor o igual a 0\n"
                "-> "RESET);
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