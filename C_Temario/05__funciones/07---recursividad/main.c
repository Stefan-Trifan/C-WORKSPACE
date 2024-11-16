/*
*	Autor
		Stefan Trifan

*	Compilar
		mac     : gcc main.c -o main
		windows : gcc main.c -o main.exe
			    : ./main.exe

*	Introducir despues de scanf
		limpiar()

*	Enunciado 62
		Mediante la estrategia conocida como "divide y venceras" nos podemos ahorrar
		un numero de multiplicaciones considerable para calcular la potencia de un
		numero, xy
		
		Para ello:
			▪ Si y es PAR,   tenemos que x^y = x^y/2 * x^y/2
			▪ Si y es IMPAR, tenemos que x^y = x^y/2 * x^y/2 * x

		Implementa otra funcion recursiva que calcule la exponencial con este metodo y
		añade un contador de llamadas recursivas para comprobar el numero de
		multiplicaciones ahorradas por este metodo.
*/

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int main(){

}