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
		Crear una funcion que reciba un numero entero positivo y que devuelva como resultado 
		otro entero que sea la suma de sus digitos. 

		Por ejemplo, si el numero fuera 123 la suma seria 6

		El programa pediria al usuario el numero (que debe der mayor o igual a ceri) y lo pasara
		a la funcion "por valor". La funcion devolvera el resultado de la suma de todos los digitos
*/

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int sumaDigitos(int num);

int main(int argc, char *argv[]){

	// Variables
	int numero = 0;
	int resultado = 0;

	// Pedimos el numero
	printf("Introduce un numero: ");
	scanf("%d", &numero);
	printf("Tu numero es:        %d\n", numero);	

	// Llamamos a la funcion que suma los digitos
	resultado = sumaDigitos(numero);

	// Imprimimos el resultado
	printf("La suma de los digitos es: %d\n", resultado);

}

// Funcion que suma los digitos
int sumaDigitos(int numero){

	int resultado    = 0;
	int ultimoDigito = 0;

	while(numero > 0){

		// Sacamos el ultimo digito
		ultimoDigito = (numero % 10);

		// Sumamos el ultimo digito al resultado
		resultado    = resultado + ultimoDigito;

		// Reducimos el tamaño al numero con cada iteracion
		numero = (numero - ultimoDigito) / 10;

		// ? Debug
		printf("%d", resultado);

	}

	return(resultado);

}