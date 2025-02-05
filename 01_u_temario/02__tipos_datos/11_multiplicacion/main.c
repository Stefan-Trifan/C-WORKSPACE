/*
	Autor: Stefan Trifan

	Compilar (dentro de la carpeta): gcc main.c -o main

	Enunciado: Que pida 2 numeros y que los multiplique
	Vamos a comprobar si la multiplicacione s mayor que 50, igual a 0, menor que -50
	Si es 0, me dices el resultado
*/



#include <stdio.h>

int main(int argc, char *argv[]){

	// Declaramos 3 numeros
	int num1=0, num2=0, resultado=0;

	// Introduce el primer numero
	printf("Primer numero\n");
	scanf("%d", &num1);

	// Introce el segundo numero
	printf("Segundo numero\n");
	scanf("%d", &num2);

	// Multiplicamos
	resultado = num1 * num2;

	// aqui no entiendo por que las siguientes 2 lineas
	if( resultado == 0 ){
		printf("Tu resultado es %d \n", resultado);
	} else if ( resultado > 50 ) {
		printf("Tu resultado es mayor o igual que 50");
	} else if ( resultado <= -50 ){
		printf("Tu resultado es menor que -50");
	}else {
		printf("Tu resultado no es 0. Esta entre 50 y -50");
	}
}