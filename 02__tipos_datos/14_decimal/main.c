/*
Autor: 
Stefan Trifan

Compilar (dentro de la carpeta)
gcc main.c -o main

Introducir después de scanf
while(getchar() != '\n');

Enunciado: 
Crea un programa que reciba 2 numeros decimales y un caractesr '+' si se desea hacer una suma 0 '-' si se desea realidar una resra entre ellos. Muestra el resultado x pantalla.
*/



#include <stdio.h>

void limpiar(){
	while(getchar() != '\n');
}

int main(){
	
	float num1 = 0;
	float num2 = 0;
	char operacion = ' ';
	float resultado = 0;

	printf("Introdcue el primer número\n");
	scanf("%f", &num1);
	limpiar();

	printf("Introdcue el segundo número\n");
	scanf("%f", &num2);
	limpiar();

	printf("Introdcue el tipo de operación que desees realizar: +, -, *, /\n");
	scanf("%c", &operacion);
	limpiar();

	if(operacion == '+'){
		resultado = num1 + num2;
		printf("El resultado es %f", resultado);
	} else if (operacion == '-') {
		resultado = num1 - num2;
		printf("El resultado es %f", resultado);
	} else if (operacion == '*') {
		resultado = num1 * num2;
		printf("El resultado es %f", resultado);
	} else if (operacion == '/') {
		resultado = num1 / num2;
		printf("El resultado es %f", resultado);
	} else {
		printf("Tenías que haber introducido '+' o '-'");
	}
}