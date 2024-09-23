/* Stefan Trifan */


/* 

Codificar un programa que calcule el área de un la base de un cilindro y su volumen, pidiéndole al usuario el radio y la
altura y utilizando un float para el radio y un double para la altura

*/ 

#include <stdio.h>
#define PI 3.14 // Eliminar el punto y coma
float radio            = 0.0;
float area_base        = 0.0;
double altura          = 0.0;
double volumen_cilindro = 0.0;


void main(){

    
    printf("Ingrese el radio del círculo: ");
    scanf("%f", &radio);

    printf("Ingrese la altura del cilindro: ");
    scanf("%lf", &altura);


    // Calculamos el área de la base
    area_base = PI * radio * radio;
    printf("El área de la base del cilindro es %f\n", area_base);

    // Calculamos el volumen del cilindro
    volumen_cilindro = area_base * altura;
    printf("El volumen del cilindro es %lf\n", volumen_cilindro);

}