/*
*	Autor
		Stefan Trifan

*	Compilar
		mac     : gcc main.c -o main
		windows : gcc main.c -o main.exe
			    : ./main.exe

*	Introducir después de scanf
		limpiar()

*	Enunciado 62
		Mediante la estrategia conocida como "divide y vencerás" nos podemos ahorrar
		un número de multiplicaciones considerable para calcular la potencia de un
		número, xy
		
		Para ello:
			▪ Si y es PAR,   tenemos que x^y = x^y/2 * x^y/2
			▪ Si y es IMPAR, tenemos que x^y = x^y/2 * x^y/2 * x

		Implementa otra función recursiva que calcule la exponencial con este método y
		añade un contador de llamadas recursivas para comprobar el número de
		multiplicaciones ahorradas por este método.
 */

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int main(){

}