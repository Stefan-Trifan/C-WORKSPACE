
// ¿Preincrementar o postincrementar?

// Recordando un poco, el preincremento

//* int a = 0;
//* int b = ++a;

// hace a=1 y b=1, mientras que el postincremento

//! int a = 0;
//! int b = a++;

// hace a=1 y b=0, esto significa que b obtuvo el valor de a anterior al incremento.

#include <stdio.h>

int main() {

    int a = 0;   // a = 1
    int b = ++a; // b = 1

    printf("El valor de a es de: %d\n",a);
    printf("El valor de b es de: %d\n",b);
    printf("\n\n");

    int c = 0;   // c = 1
    int d = c++; // d = 0

    printf("El valor de c es de: %d\n",c);
    printf("El valor de d es de: %d\n",d);

    return 0;
}