/* Stefan Trifan */


/* 

Mostrar utilizando un programa de C la representacion en hexadecimal de dos numeros enteros tanto positivos como negativos. 
(%x es el especificador del printf que permite presentar los 1 y 0 de una posicion de memoria en
hexadecimal).

*/ 

#include <stdio.h>

void main(){

    int num_positivo = 12;
    int num_negativo = -12;

    printf("El numero hexadecimal positivo de 12 es: %x\n", num_positivo);

    printf("El numero hexadecimal negativo de 12 es: %x\n", num_negativo);

}