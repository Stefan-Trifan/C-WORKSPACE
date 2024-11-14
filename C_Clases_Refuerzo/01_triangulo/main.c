/*
*	Autor
		Stefan Trifan

*	Compilar
		mac     : gcc main.c -o main
		windows : gcc main.c -o main.exe
			    : ./main.exe

*	Introducir después de scanf
		limpiar()

*	Enunciado (Ejercicio clases de refuerzo)
		Solicito 3 valores enteros (lados del programa)
		Determinamos si es posible formar el triangulo
		La suma de longitudes de 2 lados cualesquiera tiene que ser mayor que el tercero
*/

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int main(){

	// Declaramos las variables del programa
	int ladoA = 0;
	int ladoB = 0;
	int ladoC = 0;

	// Pedimos los lados del triángulo
	printf("Introduce el primer lado: ");
	scanf("%i", &ladoA);

	printf("Introduce el segundo lado: ");
	scanf("%i", &ladoB);

	printf("Introduce el tercer lado: ");
	scanf("%i", &ladoC);

	// Comprobamos si 2 lados cualesqiera tiene que ser mayor que el tercero
	if ( ((ladoA + ladoB) > ladoC) && ((ladoA + ladoC) > ladoB) && ((ladoB + ladoC) > ladoA) ){
		printf("Es posible\n");
	} else {
		printf("No es posible\n");
	}

}