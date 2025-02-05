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
		18 Implementa una funcion que multiplique dos enteros solicitados desde la
		funcion principal
*/

#include <stdio.h>

int multiplica(int primerNumero, int segundoNumero);

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int main(int argc, char *argv[]){

	int num1 = 0;
	int num2 = 0;
	

	printf("Introduce el primer numero: ");
	scanf("%d", &num1);

	printf("Introduce el segundo numero: ");
	scanf("%d", &num2);

	int resultado = multiplica(num1, num2);
	printf("El resultado de la multiplicacion es: %d\n", resultado);

}

int multiplica(int primerNumero, int segundoNumero){
	int resultado = 0;

	resultado = primerNumero * segundoNumero;
	return resultado;
}