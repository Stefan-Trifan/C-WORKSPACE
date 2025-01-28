/*
*	Autor
		Stefan Trifan

*	Compilar
		mac     : gcc main.c -o main
		windows : gcc main.c -o main.exe
			    : ./main.exe

*	Introducir despues de scanf
		limpiar()

*	Enunciado
		En matematicas, la sucesion o serie de Fibonacci hace referencia a la secuencia ordenada de numeros descrita
		por Leonardo de Pisa, matematico italiano del siglo XIII:

		0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144,…

		A cada uno de los elementos de la serie se le conoce con el nombre de numero de Fibonacci.

		1.a) Escribe un programa para calcular el numero de Fibonacci de la posicion “n”. Dicha serie se obtiene segun la
		formula:

		0 si n = 0
		F(n) 1 si n = 1
		F(n − 1) + F(n − 2) si n > 1

		1.b) Escribe otro programa que escriba los “n” primeros numeros de la serie de Fibonacci, siendo n un valor que se lee
		de la entrada estandar. Partiendo de los numeros 0 y 1, los numeros de Fibonacci quedan definidos por la funcion:
			f(n) = f(n-1) + f(n-2)

		Se pide implementar una funcion que sea la que calcule la serie. El programa principal pedira al usuario el numero n,
		calculara la serie llamand
*/

#include <stdio.h>

int fibonacci(int n);

int main(){

	// Declaramos las variables
	long long int n = 0;

	// Pedimos n
	printf("Introduce n: ");
	scanf("%lld", &n);
	printf("n es %lld\n", n);

	if (n < 0){
		printf("Numero no valido");
	} else {
		long long int res = fibonacci(n);
		printf("El numero de fibonacci en %lld es %lld\n", n, res);
	}

	return 0;

}

int fibonacci(int n){

	if (n == 0){
		return 0;
	} else if (n == 1){
		return 1;
	} else {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}