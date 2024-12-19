/*
*	Autor
		Stefan Trifan

*	Compilar
		mac    : gcc main.c -o main
		windows: gcc main.c -o main.exe
			   : ./main.exe

*	Introducir despues de scanf
		limpiar()

*	Enunciado
		* Crear un programa que calcule el resultado de multiplicar un numero 2 elevado a un exponente, y que lo devuelva como resultado. 
		* El numero y el exponente deberan pedirse al usuario mediante scanf. 
		* El exponente debe ser mayor que cero. 
		* No se puede usar el operador "*" (multiplicar).
*/

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int main(){
	
	int base      = 0;
	int exponente = 0;
	int resultado = 0;
	
	// Pedimos base al usuario
	printf("Introduce la base\n");
	scanf("%d", &base);
	limpiar();

	// Pedimos el exponente al usuario
	printf("Introduce el exponente\n");
	scanf("%d", &exponente);
	limpiar();

	// Calculamos lo que pide
	resultado = base << exponente;
	printf("El resultado es %d", resultado);

	return 0;
}