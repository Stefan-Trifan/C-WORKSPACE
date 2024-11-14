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
		Crear una funcion que reciba un número entero positivo y que devuelva como resultado 
		otro entero que sea la suma de sus dígitos. 

		Por ejemplo, si el número fuera 123 la suma seria 6

		El programa pediria al usuario el numero (que debe der mayor o igual a ceri) y lo pasará
		a la función "por valor". La función devolverá el resultado de la suma de todos los dígitos
*/

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int sumaDigitos(int num);

int main(){

	// Variables
	int numero = 0;
	int resultado = 0;

	// Pedimos el numero
	printf("Introduce un número: ");
	scanf("%i", &numero);
	printf("Tu numero es:        %i\n", numero);	

	// Llamamos a la funcion que suma los digitos
	resultado = sumaDigitos(numero);

	// Imprimimos el resultado
	printf("La suma de los digitos es: %i\n", resultado);

}

// Funcion que suma los digitos
int sumaDigitos(int numero){

	int resultado    = 0;
	int ultimoDigito = 0;

	while(numero > 0){

		// Sacamos el ultimo digito
		ultimoDigito = (numero % 10);

		// Sumamos el último dígito al resultado
		resultado    = resultado + ultimoDigito;

		// Reducimos el tamaño al número con cada iteración
		numero = (numero - ultimoDigito) / 10;

		// ? Debug
		printf("%i", resultado);

	}

	return(resultado);

}