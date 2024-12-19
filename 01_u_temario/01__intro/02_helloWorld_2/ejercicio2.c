/*
Program Hello Word avanzado
*/

#include <stdio.h>

void main (){

    char caracter;

        printf("Ingresa un caracter('S') para imprimir 'Hello World'):");
        scanf("%c", &caracter);

        if (caracter == 'S' || caracter == 's'){
            printf("Hello world\n");
        } else {
            printf("Caracter no valido. No se imprime 'Hello world'\n");
        }

}