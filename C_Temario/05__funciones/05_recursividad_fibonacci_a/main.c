/*
*	Autor
		Stefan Trifan

*	Compilar
		mac     : gcc main.c -o main
		windows : gcc main.c -o main.exe
			    : ./main.exe

*	Introducir después de scanf
		limpiar()

*	Enunciado
		En matemáticas, la sucesión o serie de Fibonacci hace referencia a la secuencia ordenada de números descrita
		por Leonardo de Pisa, matemático italiano del siglo XIII:

		0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144,…

		A cada uno de los elementos de la serie se le conoce con el nombre de número de Fibonacci.

		1.a) Escribe un programa para calcular el número de Fibonacci de la posición “n”. Dicha serie se obtiene según la
		fórmula:

		0 si n = 0
		F(n) 1 si n = 1
		F(n − 1) + F(n − 2) si n > 1

		1.b) Escribe otro programa que escriba los “n” primeros números de la serie de Fibonacci, siendo n un valor que se lee
		de la entrada estándar. Partiendo de los números 0 y 1, los números de Fibonacci quedan definidos por la función:
			f(n) = f(n-1) + f(n-2)

		Se pide implementar una función que sea la que calcule la serie. El programa principal pedirá al usuario el número n,
		calculará la serie llamand
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
		printf("Numero no válido");
	} else {
		long long int res = fibonacci(n);
		printf("El número de fibonacci en %lld es %lld\n", n, res);
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