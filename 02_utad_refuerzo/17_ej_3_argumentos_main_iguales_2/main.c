/*
    *   Autor
        Stefan Trifan

    *   Estado

    *   Enunciado
        Escribe un programa en lenguaje C al que se le pase por argumentos del main 
        dos cadenas (tamaño maximo 20 caracteres) y que compruebe que son iguales.
        El programa mostrara imprimira por pantalla si son iguales o no despues de comprobarlo
*/

/* _________________________________________
   Inicio cabecera */
#include <stdio.h>
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define RESET "\033[0m"
#define TAM 8
// Funciones del programa
int cadenasIguales(char* cadena1, char* cadena2);
int tamCadena(char* cadena);

// Funciones auxiliares
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[]) 
{
    printf("\n_________________________________________START\n\n");

    char cadena1[TAM] = {0}, cadena2[TAM] = {0};
    int i1 = 0, i2 = 0, son_iguales = 0;

    if(argc != 3)
    {
        printf(RED"Tienes que introducir 2 argumentos\n");
        printf("\n_________________________________________FAIL\n\n"RESET);
        return 0;
    }

    // Primer argumento
    while(argv[1][i1] != '\0')
    {
        cadena1[i1] = argv[1][i1];
        i1++;
        if(i1 >= TAM)
        {
            printf(RED"Has introducido demasiados caracteres\n");
            printf("\n_________________________________________FAIL\n\n"RESET);
            return 0;
        }
    }
    cadena1[i1] = '\0';

    while(argv[2][i2] != '\0')
    {
        cadena2[i2] = argv[2][i2];
        i2++;
        if(i2 >= TAM)
        {
            printf(RED"Has introducido demasiados caracteres\n");
            printf("\n_________________________________________FAIL\n\n"RESET);
            return 0;
        }
    }
    cadena2[i2] = '\0';

    son_iguales = cadenasIguales(cadena1, cadena2);

    if(son_iguales)
    {
        printf(GREEN"Las cadenas son iguales"RESET);
    }
    else
    {
        printf(RED"Las cadenas no son iguales"RESET);
    }

    printf("\n_________________________________________END\n\n");
    return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa
/**
 * Funcion que se le pasa como parametros dos cadenas y 
 * devuelve verdadero si son iguales y falso si no lo son
 */
int cadenasIguales(char* cadena1, char* cadena2)
{
    int tam1 = 0, tam2 = 0;

    tam1 = tamCadena(cadena1);
    tam2 = tamCadena(cadena2);

    if(tam1 == tam2)
    {
        for(int i = 0; i < tam1; i++)
        {
            if(cadena1[i] != cadena2[i])
            {
                return 0;
            }
        }
        return 1;
    }
    else
    {
        return 0;
    }
}

/**
 * Funcion que se le pasa como parametro una cadena y 
 * devuelve el numero de caracteres que tiene
 */
int tamCadena(char* cadena)
{
    int i = 0;
    while(cadena[i] != '\0')
    {
        i++;
    }
    return i;
}

// Funciones auxiliares
void clearBuffer() {
    while (getchar() != '\n');
}
