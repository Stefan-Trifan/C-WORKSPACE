/*Stefan Trifan*/


/* Mostrar utilizando un programa de C la representacion interna del caracter ‘A’.
Transformar el caracter ‘A’ (mayuscula) al caracter ‘a’ (minuscula) sin usar funciones
externas.
*/ 

#include <stdio.h>

void main(){
    char letra = 'a';

    char letraMayus;

    letraMayus = letra - 32;
    printf("La letra en mayuscula es; %c", letraMayus);
}