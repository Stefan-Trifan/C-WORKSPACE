/* Stefan Trifan */


/* 

Mostrar utilizando un programa de C la representación en hexadecimal de dos números enteros tanto positivos como negativos. 
(%x es el especificador del printf que permite presentar los 1 y 0 de una posición de memoria en
hexadecimal).

*/ 

#include <stdio.h>

void main(){

    int num_positivo = 12;
    int num_negativo = -12;

    printf("El número hexadecimal positivo de 12 es: %x\n", num_positivo);

    printf("El número hexadecimal negativo de 12 es: %x\n", num_negativo);

}