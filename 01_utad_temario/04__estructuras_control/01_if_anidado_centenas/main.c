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
		Pide un numero entero de tres cifras por teclado. 
		Comprueba si la tercera cifra (centena) del numero es 1, 2 , 3 o 5 escribiendo por pantalla que la centena del numero es 1, 2, 3 o 5. 
		Si no es asi, el programa debera escribir que la centena no es 1, 2, 3 o 5.
*/

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int main(int argc, char *argv[]){

	// Declaramos las variables
	int numero = 0, centena = 0;

	// Pedimos el numero por pantalla
	printf("Introduce un numero de 3 cifras\n");
	scanf("%d", &numero);

	// Extraemos el 3 numero
	centena = numero / 100;

	// Comprobamos con if
	if(centena == 1)
		printf("La centena es el numero %d\n", centena);
	else if(centena == 2)
		printf("La centena es el numero %d\n", centena);
	else if(centena == 3)
		printf("La centena es el numero %d\n", centena);
	else if(centena == 4)
		printf("La centena es el numero %d\n", centena);
	else if(centena == 5)
		printf("La centena es el numero %d\n", centena);
	else 
		printf("La centena no es 1, 2, 3, 4, 5");

}