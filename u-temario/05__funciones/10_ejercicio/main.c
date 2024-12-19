/*
*	Autor
		Stefan Trifan

*	Compilar
		mac     : gcc main.c -o main
		windows : gcc main.c -o main.exe
				: ./main.exe

*	Introducir despues de scanf
		limpiar()

*   Estado: doing

*	Enunciado
		Vamos a realizar un programa que le pida al usuario 2 num enteros

		Con estos 2 numeros enteros vamos a llamar a una funcion para que realice tanto la suma como la resta.
		La funcion tiene que devolver al main los valores resultantes de las operaciones. (Solo 1 funcion)
*/

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){
	while (getchar() != '\n');
}

void calculos(int numero1, int numero2, int *resultadoSuma, int *resultadoResta);

int main(){
	printf("\n________________________________________________\n\n");

	// Declaramos variables
	int num1 = 0;
	int num2 = 0;
	int resSuma = 0;
	int resResta = 0;

	// Pedimos nums
	printf("Introduce el primer numero:  ");
	scanf("%i", &num1);

	printf("Introduce el segundo numero: ");
	scanf("%i", &num2);

	calculos(num1, num2, &resSuma, &resResta);

	printf("El resultado de la suma es : %i\n", resSuma);
	printf("El resultado de la resta es: %i", resResta);

	printf("\n________________________________________________\n\n");
}

void calculos(int numero1, int numero2, int *resultadoSuma, int *resultadoResta){

	/*
		Si trabajamos con una variable puntero;

		Para acceder al contenido * -> *resultadoSuma
		Para acceder a la direccion de memoria & -> &resultadoSuma
		Para acceder a la direccion de memoria que guarda (sin nada) -> resultadoSuma


	*/

	*resultadoSuma = numero1 + numero2;
	*resultadoResta = numero1 - numero2;
}
