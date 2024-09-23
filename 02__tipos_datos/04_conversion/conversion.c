/*Stefan Trifan*/


/* Mostrar utilizando un programa de C la representación interna del carácter ‘A’.
Transformar el carácter ‘A’ (mayúscula) al carácter ‘a’ (minúscula) sin usar funciones
externas.
*/ 

#include <stdio.h>

void main(){
    char letra = 'a';

    char letraMayus;

    letraMayus = letra - 32;
    printf("La letra en mayuscula es; %c", letraMayus);
}