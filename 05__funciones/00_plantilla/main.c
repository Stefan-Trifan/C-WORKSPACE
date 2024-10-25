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
		LoremIpsumDummyText
 */

#include <stdio.h>

int multiplica(int primerNumero, int segundoNumero);

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int main(){

	int num1 = 0;
	int num2 = 0;
	

	printf("Introduce el primer número: ");
	scanf("%i", &num1);

	printf("Introduce el segundo número: ");
	scanf("%i", &num2);

	int resultado = multiplica(num1, num2);
	printf("El resultado de la multiplicación es: %i\n", resultado);

}

int multiplica(int primerNumero, int segundoNumero){
	int resultado = 0;

	resultado = primerNumero * segundoNumero;
	return resultado;
}