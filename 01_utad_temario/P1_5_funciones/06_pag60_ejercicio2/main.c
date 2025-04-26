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
		- La funcion exponencial, xy siendo x e y numeros enteros, puede implementarse de forma recursiva, dado que x^y = x * x^y-1
		- Implementa una funcion recursiva que calcule la funcion exponencial.
*/

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int funcionExponencial(int x, int y);

int main(int argc, char *argv[]){

	int x         = 0;
	int y         = 0;
	int resultado = 0;

	printf("Introduce el primer numero:  ");
	scanf("%d", &x);
	printf("Introduce el segundo numero: ");
	scanf("%d", &y);

	resultado = funcionExponencial(x, y);

	printf("El resultado de %d y %d es : %d\n", x, y, resultado);

}

// Funcion recursiva para calular x^y
int funcionExponencial(int x, int y){

	if( y == 0 ){
		return 1;
	} else {
		return x * funcionExponencial(x, y - 1);
	}

}