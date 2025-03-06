/*
    *   Autor
        Stefan Trifan

    *   Testing
        $ ./jugadores_baloncesto_v0.exe
        Uso incorrecto. Debe ingresar los datos de 5 jugadores con el formato:
        <Apellido> <Posición (base/ala/pivot)> <Estatura>

        $ ./main Ruiz base 1.92 Alonso ala 1.99 Serrano ala 2.01 Belmonte ala 2.02 Alcazar pivot 2.15

        Jugador 0: Ruiz - 0 - 1.920000
        Jugador 1: Alonso - 1 - 1.990000
        Jugador 2: Serrano - 1 - 2.010000
        Jugador 3: Belmonte - 1 - 2.020000
        Jugador 4: Alcazar - 2 - 2.150000

        Jugadores en posición 'ala' con estatura superior a 2 metros:
        - Serrano (2.01 m)
        - Belmonte (2.02 m)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximo 15 caracteres. Sumamos uno para incluir el caracter nulo
#define TAM_STR 16 
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"
#define N_JUGADORES 5

typedef enum posicion_t
{
    base, ala, pivot
}
posicion_t;

typedef struct jugador_t
{
    char apellido[TAM_STR];
    posicion_t posicion;
    float altura;
}
jugador_t;

// Funciones del programa
int comparaCadenas(char* str1, char* str2);
int tamCadena (char* str);
posicion_t obtenerPosicion(char *str);
void mostrarJugadoresAlaAltos(jugador_t jugadores[], int total);

// Funciones auxiliares
void pedirCadena(char *text, int tam);
float pedirFloat();
void clearBuffer();

/*  ________________________________________
    Inicio main */

int main(int argc, char *argv[])
{
    printf("________________________________________START\n\n");
    if(argc != 16)
    {
        printf(RED
            "USO 2: ./main Ruiz base 1.92 Alonso ala 1.99 Serrano ala 2.01 Belmonte ala 2.02 Alcazar pivot 2.15\n"RESET
            "\n________________________________________FAIL\n\n");
        return 1;
    }

    // Declaramos las variables generales del programa
    jugador_t jugador[N_JUGADORES] = {0};
    int num_caracteres_jug_1 = 0,
        num_caracteres_jug_2 = 0,
        num_caracteres_jug_3 = 0,
        num_caracteres_jug_4 = 0,
        num_caracteres_jug_5 = 0;

    // Comprobamos que ningun apellido supera el limite de caracteres 
    // antes de guardarlo en nuestra estructura;
    num_caracteres_jug_1 = tamCadena(argv[1]);
    num_caracteres_jug_2 = tamCadena(argv[4]);
    num_caracteres_jug_3 = tamCadena(argv[7]);
    num_caracteres_jug_4 = tamCadena(argv[10]);
    num_caracteres_jug_5 = tamCadena(argv[13]);

    // Si algun apellido supera el limite de caracterees, imprimimos un error
    // y detenemos la ejecucion del resto del programa
    if(
        num_caracteres_jug_1 >= TAM_STR ||
        num_caracteres_jug_2 >= TAM_STR ||
        num_caracteres_jug_3 >= TAM_STR ||
        num_caracteres_jug_4 >= TAM_STR ||
        num_caracteres_jug_5 >= TAM_STR
    )
    {
        printf(RED
            "ERROR: El apellido no puede tener mas de %d caracteres\n"
            "\n________________________________________FAIL\n\n"RESET, 
            TAM_STR - 14);
        // Detenemos la ejecucion del resto del programa si un apellido 
        // supera el limite de caracteres
        return 1; 
    }

    // Guardamos el Jugador 1
    strcpy(jugador[0].apellido, argv[1]);
    jugador[0].posicion = obtenerPosicion(argv[2]);
    jugador[0].altura = strtof(argv[3], NULL);

    // Guardamos el Jugador 2
    strcpy(jugador[1].apellido, argv[4]);
    jugador[1].posicion = obtenerPosicion(argv[5]);
    jugador[1].altura = strtof(argv[6], NULL);

    // Guardamos el Jugador 3
    strcpy(jugador[2].apellido, argv[7]);
    jugador[2].posicion = obtenerPosicion(argv[8]);
    jugador[2].altura = strtof(argv[9], NULL);

    // Guardamos el Jugador 4
    strcpy(jugador[3].apellido, argv[10]);
    jugador[3].posicion = obtenerPosicion(argv[11]);
    jugador[3].altura = strtof(argv[12], NULL);

    // Guardamos el Jugador 5
    strcpy(jugador[4].apellido, argv[13]);
    jugador[4].posicion = obtenerPosicion(argv[14]);
    jugador[4].altura = strtof(argv[15], NULL);

    // Mostramos la informacion de cada jugador
    for(int i = 0; i < N_JUGADORES; i++)
    {
        printf(
            "Jugador %d: %-16s - %d - %.2f\n",
            i, 
            jugador[i].apellido, 
            jugador[i].posicion,
            jugador[i].altura);
    }
    printf("\n\n");

    // Mostramos los jugadores posicion ala con mas de 2 metros
    mostrarJugadoresAlaAltos(jugador, N_JUGADORES);


    printf("\n________________________________________END\n\n");
    return 0;
}

/*  ________________________________________
    Inicio definicion de funciones */

// Funciones del programa
/**
 * Funcion que devuelve la longitud de la cadena
 * 
 * @return num_caracteres: Numero de caracteres que tiene un string
 */
int tamCadena (char* str)
{
    int num_caracteres = 0,
        i              = 0;

    // Mientras no nos encontremos el caracter nulo aumentamos
    // el numero de caracteres
    while(str[i] != '\0')
    {
        num_caracteres++;
        i++;
    }

    return num_caracteres;
}

/**
 * Función para convertir una cadena a la posición correspondiente
 */
posicion_t obtenerPosicion(char *str)
{
    posicion_t posicion;

    if(
        str[0] == 'b' && 
        str[1] == 'a' && 
        str[2] == 's' && 
        str[3] == 'e' && 
        str[4] == '\0')
    {
        posicion = base;
    }
    else if(
        str[0] == 'a' && 
        str[1] == 'l' && 
        str[2] == 'a' && 
        str[3] == '\0')
    {
        posicion = ala;
    }
    else if(
        str[0] == 'p' && 
        str[1] == 'i' && 
        str[2] == 'v' && 
        str[3] == 'o' &&
        str[4] == 't' && 
        str[5] == '\0')
    {
        posicion = pivot;
    }
    else
    {
        printf(RED
            "ERROR: El tipo de posicion que has introducido no es valido.\n"
            "Debe ser base, ala o pivot\n" RESET);
    }
    return posicion;
}

/**
 * Función para mostrar los jugadores que cumplen la condición
 */
void mostrarJugadoresAlaAltos(jugador_t jugadores[], int total)
{
    printf("Jugadores en posición 'ala' con estatura superior a 2\n");
    for(int i = 0; i < N_JUGADORES; i++)
    {
        // Filtramos los jugadores de mas de 2 metros con posicionala
        if(jugadores[i].altura > 2 && jugadores[i].posicion == ala)
        {
            printf(
                "%s (%.2f m)\n",
                jugadores[i].apellido, jugadores[i].altura);
        }
        
    }
}

/**
 * Funcion que compara dos cadenas devolvieldo 1 si son iguales y 0 sino.
 */
int comparaCadenas(char* str1, char* str2)
{
    int i = 0;
    while(str1[i] != '\0' || str2[i] != '\0')
    {
        
    }
    return 0;
}

// Funciones auxiliares
void clearBuffer()
{
    while(getchar() != '\n');
}