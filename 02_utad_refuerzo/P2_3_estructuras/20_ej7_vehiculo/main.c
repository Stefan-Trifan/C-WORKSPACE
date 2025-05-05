/*
    *   Autor
        Stefan Trifan
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>

#define TAM_STR 12
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"

// Funciones del programa
typedef union
{	
	int tiene_baul;
	int num_puertas;
}
descripcion_t;

typedef struct
{
	char tipo[TAM_STR];
	descripcion_t descripcion;
}
vehiculo_t;

// Funciones auxiliares
void pedirCadena(char *text);
int pedirEntero();
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");

	vehiculo_t vehiculo;
    
    printf("Ingresa el tipo de vehiculo (coche o motocicleta)\n-> ");
	pedirCadena(vehiculo.tipo);

	if( 
        vehiculo.tipo[0] == 'c' &&
        vehiculo.tipo[1] == 'o' &&
        vehiculo.tipo[2] == 'c' &&
        vehiculo.tipo[3] == 'h' &&
        vehiculo.tipo[4] == 'e' &&
        vehiculo.tipo[5] == '\0')
    {
        printf("Has introducido coche\n");
        printf("Introduce el num de puertas-> \n");
        vehiculo.descripcion.num_puertas = pedirEntero();
        printf("Tienes un %s con %d puertas\n", vehiculo.tipo, vehiculo.descripcion.num_puertas);
    }
    else if(
        vehiculo.tipo[0]  == 'm' &&
        vehiculo.tipo[1]  == 'o' &&
        vehiculo.tipo[2]  == 't' &&
        vehiculo.tipo[3]  == 'o' &&
        vehiculo.tipo[4]  == 'c' &&
        vehiculo.tipo[5]  == 'i' &&
        vehiculo.tipo[6]  == 'c' &&
        vehiculo.tipo[7]  == 'l' &&
        vehiculo.tipo[8]  == 'e' &&
        vehiculo.tipo[9]  == 't' &&
        vehiculo.tipo[10] == 'a' &&
        vehiculo.tipo[11] == '\0')
    {
        printf("Has introducido motocicleta\n");
        printf("Introduce 1 si tiene baul y 0 si no tiene\n-> \n");
        do
        {
            vehiculo.descripcion.tiene_baul = pedirEntero();
            if(vehiculo.descripcion.tiene_baul != 0 && vehiculo.descripcion.tiene_baul != 1)
            {
                printf(YELLOW"Tienes que introducir 0 o 1\n-> "RESET);
            }
        } 
        while (vehiculo.descripcion.tiene_baul != 0 && vehiculo.descripcion.tiene_baul != 1);
        if(vehiculo.descripcion.tiene_baul)
        {
            printf("Tienes una %s con baul\n", vehiculo.tipo);
        }
        else
        {
            printf("Tienes una %s con sin baul\n", vehiculo.tipo);
        }
    }
    else
    {
        printf("Vehiculo debe ser coche o motocicleta\n");
        printf(RED"\n_________________________________________EXIT_FAILURE\n\n"RESET);
        return 1;
    }
    
	printf("\n_________________________________________EXIT\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa

// Funciones auxiliares
void pedirCadena(char *text)
{
    int i = 0, esValido;
    char c;
    do
    {
        i = 0;
        esValido = 1;
        while (i < TAM_STR - 1)
        {
            c = getchar();

            // printf("DEBUG: i = %d, c = %c (%d)\n", i, c, c);
            if(c == '\n')
				break;
                
            text[i] = c;
            i++; 
        }
        text[i] = '\0'; 

        // printf("DEBUG SALIDA WHILE: i = %d, c = %c (%d)\n", i, c, c);
        
        if(i == TAM_STR - 1)
        {
            c = getchar();
            if(c != '\n')
            {
                printf(
                    "\033[1;33mHas introducido demasiados caracteres\n"
                    "Intentalo de nuevo\n"
                    "-> \033[0m");
                clearBuffer();
                esValido = 0;
            }
        }
    } 
    while (esValido != 1);
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