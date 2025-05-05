/*
    *   Autor
        Stefan Trifan
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_BLOQUE 5

// Funciones del programa
char* pedirLineaDinamica();
int cadenasIguales(char* cadena1, char* cadena2);
int tamCadena (char* cadena);

// Funciones auxiliares
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    // Declaracion de variables
    char **mi_lista = (char **)malloc(sizeof(char *));

    int num_animales = 0;

    // Pedimos el primer ave
    printf("Introduce el primer elemento: ");
    mi_lista[num_animales] = pedirLineaDinamica();
    num_animales++;

    // Pedimos el segundo ave
    printf("Introduce el segundo elemento: ");
    mi_lista = (char **)realloc(mi_lista, (num_animales + 1) * sizeof(char *));
    mi_lista[num_animales] = pedirLineaDinamica();

    // Imrpimimos el primer ave
    printf("Ave: %s", mi_lista[0]);
    printf("Ave: %s", mi_lista[1]);

    printf("\n_________________________________________EXIT\n\n");
    return EXIT_SUCCESS;
}

/* _________________________________________
   Inicio definicion de funciones */

//Funciones del programa

//Función que devuelve una cadena de caracteres leída del
//buffer I/O y que realiza la reserva de memoria dinámica por
//bloques para la cadena
char *pedirLineaDinamica()
{
    char *texto_destino;
    char c;
    int i = 0;
    int memoria_actual = TAM_BLOQUE;

    // Reservamos memoria para el primer bloque
    texto_destino = (char *)malloc(memoria_actual * sizeof(char));

    while((c = getchar()) != '\n')
    {
        if(i == memoria_actual)
        {
            memoria_actual += TAM_BLOQUE;
            texto_destino = (char *)realloc(texto_destino, memoria_actual * sizeof(char));
        }
        texto_destino[i] = c;
        i++;
    }
    texto_destino[i] = '\0';

    return texto_destino;
}

// Función que se le pasa como parámetros dos cadenas y devuelve
// verdadero si son iguales y falso si no lo son
int cadenasIguales(char* cadena1, char* cadena2)
{
    int son_iguales = 1;
    int i = 0;

    while(cadena1[i] != '\0' && cadena2[i] != '\0')
    {
        if(cadena1[i] != cadena2[i])
        {
            son_iguales = 0;
            break;
        }
        i++;
    }

    if(cadena1[i] != '\0' || cadena2[i] != '\0')
    {
        son_iguales = 0;
    }

    return son_iguales;
}

// Función que se le pasa como parámetro una cadena y devuelve
//el número de caracteres que tiene
int tamCadena (char* cadena)
{
    int i = 0;
    int tam_cadena = 0;

    while(cadena[i] != '\0')
    {
        tam_cadena++;
        i++;
    }
    if(cadena[i] == '\0')
    {
        tam_cadena++;
    }

    printf("El tam es %d", tam_cadena);
    return 0;
}

// Función que se le pasa como parámetros dos cadenas y devuelve
// la cadena concatenación de las dos que se pasan

// Funciones auxiliares
void clearBuffer()
{
    while (getchar() != '\n');
}