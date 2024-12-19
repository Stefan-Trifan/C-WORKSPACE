#include <stdio.h>
int cuenta; /* Cuenta es una variable global */ 

void Func1 (void);
void Func2 (void);

/* Hemos declarado 2 funciones */

int main(void){
    cuenta = 10; /* Cuenta es variable global */
    printf ("A la entrada del main cuenta es %d\n", cuenta); /* Muestra el valor de cuenta */
    Func1 ();
    printf ("A la salida del main cuenta es %d\n", cuenta); /* Muestra ek valor de cuenta */
    return 0;
}

void Func1 (void){
    int temp=0; 
    temp = cuenta;
    Func2 ();
    printf ("A la salida de Func1 temp es %d y cuenta es %d\n", temp,cuenta); /*muestra el valor de temp*/
}

void Func2 (void){
    int cuenta=0; /* Declaramos variable formal */
    cuenta = 15;
    printf ("A la salida de Func2 cuenta es %d\n", cuenta); /*muestra el valor de cuenta*/
}
