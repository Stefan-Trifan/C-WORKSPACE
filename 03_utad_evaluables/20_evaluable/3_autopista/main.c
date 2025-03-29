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
void crearVehiculo();
void actualizarPosiciones();
void finalizarPrograma();
void mostrarMenu();

// Funciones auxiliares
int pedirEntero();
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    // Declaracion de variables
    coche_t coche[100];
    int num_coches = 0;

    printf("Ingrese matrícula: ");

    printf("Tipo de vehículo (0=Moto, 1=Coche, 2=Camión): ");

    printf("Nombre del conductor: ");

    printf("Carril (1-3):");

    printf("Velocidad (km/iteración): ");
    

    // Imrpimmos los coches que están registrados hasta ahora
    for(int i = 0; i < num_coches; i++)
    {
        
    }

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

// TODO comvertir coche_t.nombre y coche_t a memoria dinamica
// TODO eliminar mensajes de DEBUG