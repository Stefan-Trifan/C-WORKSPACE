//Sumar, restar, Multiplicar y Dividir

#include <stdio.h>

void Sumar();
void menu();
void Restar();
void Multiplicar();
void Dividir();



int main() {
    menu();
    return 0;
}

void menu(){

    int opcion;
    do
    {
        printf("1) Sumar\n2) Restar\n3) Multiplicar\n4) Dividir\n5) Salir\n");
        printf("Opcion\n");
        scanf("%i",&opcion);

        switch (opcion)
        {
        case 1: Sumar();
        break;
        case 2: Restar();
        break;
        case 3: Multiplicar();
        break;
        case 4: Dividir();
        break;
        
        default: 
            break;
        }
    } while (opcion!=5);
}

void Sumar(){

    int n1,n2,suma=0;
    printf("Escribe 2 Numeros\n");
    scanf("%i %i",&n1,&n2);
    suma = n1+n2;
    printf("La Suma es %i\nQue mas quieres hacer?\n",suma);

}

void Restar(){

    int n1,n2,resta=0;
    printf("Escribe 2 Numeros\n");
    scanf("%i %i",&n1,&n2);
    resta = n1-n2;
    printf("La Resta es %i\nQue mas quieres hacer?\n",resta);

}

void Multiplicar(){

    int n1,n2,multiplicar=0;
    printf("Escribe 2 Numeros\n");
    scanf("%i %i",&n1,&n2);
    multiplicar = n1*n2;
    printf("La Multiplicacion es %i\nQue mas quieres hacer?\n",multiplicar);

}

void Dividir(){

    int n1,n2,dividir=0;
    printf("Escribe 2 Numeros\n");
    scanf("%i %i",&n1,&n2);
    dividir = n1/n2;
    printf("La Division es %i\nQue mas quieres hacer?\n",dividir);

}
