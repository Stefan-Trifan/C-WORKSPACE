/*
    *   Autor
        Stefan Trifan

    *   Estado

    *   Enunciado 3 - Autopista
        Se debe desarrollar un programa que simule el funcionamiento de una autopista. 
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
    MOTO, COCHE, CAMION
}
tipo_vehiculo_t;

typedef struct
{
    char matricula[7];
    tipo_vehiculo_t tipo_vehiculo; // (0=Moto, 1=Coche, 2=Camión)
    char nombre[50];
    int carril;   // (1-3)
    int posicion; // [0, 300]
    int velocidad; 
}
coche_t;

// Funciones del programa
void mostrarMenu();

// Funciones auxiliares
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    

    printf("\n_________________________________________EXIT\n\n");
    return EXIT_SUCCESS;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa
void crearVehiculo()
{

}

void actualizarPosiciones()
{
    
}

void finalizarPrograma()
{
    
}

void mostrarMenu()
{
    printf(
        "--- Menú de la Autopista ---\n"
        "1. Crear vehículo\n"
        "2. Actualizar posiciones\n"
        "3. Finalizar programa\n"
        "Seleccione una opción: ");
}

// Funciones auxiliares
void clearBuffer()
{
    while (getchar() != '\n');
}

// TODO comvertir memoria estatica a memoria dinamica