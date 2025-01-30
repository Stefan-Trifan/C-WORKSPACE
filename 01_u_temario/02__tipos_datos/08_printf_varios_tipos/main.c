/*
	Stefan Trifan
*/

/*
	Ejecutar el siguiente comando para compilar;
*/

#include <stdio.h>

void main(){
    // Declaramos primera variable
    float variableFloat;
    variableFloat = 5.5;

    // Declaramos segunda variable
    int variableNum;
    variableNum = 10;

    // Declaramos la tercera variable
    char letraNombre;
    letraNombre = 'S';

    printf("La variable float es: %f  \n la variable int es: %d \n la primera letra es %c", variableFloat, variableNum, letraNombre);
    /* Devuelve:
        La variable float es: 5.5
        la variable int es: 10 
        la primera letra es S
   */
   printf("La variable float es: %d  \n la variable int es: %d \n la primera letra es %c", variableFloat, variableNum, letraNombre);
   /*
        La variable float es: 0  
        la variable int es: 10 
        la primera letra es S
  */
}
