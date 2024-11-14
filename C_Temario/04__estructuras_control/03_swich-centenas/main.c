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
		Pide un número entero por teclado de tres cifras. Comprueba si la cifra de sus centenas es 1, 2 , 3 o 5 escribiendo por pantalla que la centena del número es 1, 2, 3 o 5. 
		Si no es así, el programa deberá escribir que la centena no es 1, 2, 3 o 5. 
		Realizar el ejemplo mediante un switch-case.
*/

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int main(){

	// Declaramos las variables
	int numero = 0, centena = 0;

	// Pedimos el número por pantalla
	printf("Introduce un número de 3 cifras\n");
	scanf("%i", &numero);

	// Extraemos el 3 número
	centena = numero / 100;

	// Comprobamos con un swich
	switch (centena){
		case 1: printf("La centena es %i", centena);
				break;
		case 2: printf("La centena es %i", centena);
				break;
		case 3: printf("La centena es %i", centena);
				break;
		case 4: printf("La centena es %i", centena);
				break;
		case 5: printf("La centena es %i", centena);
				break;
	}

}