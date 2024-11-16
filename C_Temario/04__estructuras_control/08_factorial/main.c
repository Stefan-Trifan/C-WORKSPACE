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
		LoremIpsumDummyText
*/

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int main(){

	int num = 0;
	unsigned long long int resultado = 1;

	printf("Introduce un numero del 0 al 65\n");
	scanf("%i", &num);

	for(int i = 1; i <= num; i++){
		resultado = resultado*i;
	}

	printf("El factorial de %i es: %llu", num, resultado);

}