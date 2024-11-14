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
		- La función exponencial, xy siendo x e y números enteros, puede implementarse de forma recursiva, dado que x^y = x * x^y-1
		- Implementa una función recursiva que calcule la función exponencial.
*/

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int funcionExponencial(int x, int y);

int main(){

	int x         = 0;
	int y         = 0;
	int resultado = 0;

	printf("Introduce el primer número:  ");
	scanf("%i", &x);
	printf("Introduce el segundo número: ");
	scanf("%i", &y);

	resultado = funcionExponencial(x, y);

	printf("El resultado de %i y %i es : %i\n", x, y, resultado);

}

// Función recursiva para calular x^y
int funcionExponencial(int x, int y){

	if( y == 0 ){
		return 1;
	} else {
		return x * funcionExponencial(x, y - 1);
	}

}