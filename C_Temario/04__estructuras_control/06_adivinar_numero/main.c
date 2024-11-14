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
		Adivinar un número de 0 al 10
		- Genera un numero aleatorio entre 0 y 10 utilizando la función rand.

		- Pide al usuario que introduzca número entero por teclado.

		- Comprueba si el número introducido coincide con el generado.

		- A la salida imprime el número de intentos para adivinarlo.
*/

#include <stdio.h>
#include <stdlib.h>  // Para rand() y srand()
#include <unistd.h>  // Para getpid()


// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int main(){

	int numRandom   = 0;
	int numUser     = 0;
	int numIntentos = 0;
	int adivinado   = 0;

	// Generamos el número aleatorio del 0 al 10
	srand(getpid());
	numRandom = rand() % 11;
	
	// Comprueba si el número introducido coincide con el generado.
	while ( adivinado == 0 ){
		// Pedimos el número 
		printf("Introduce un número del 1 al 10\n");
		scanf("%i", &numUser);

		numIntentos++;

		if (numUser == numRandom){
			// Imprime el número de intentos
			printf("Lo has logrado después de %i intentos", numIntentos);
			adivinado = 1;
		}

	}
}