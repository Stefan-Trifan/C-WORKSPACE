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
		Adivinar un numero de 0 al 10
		- Genera un numero aleatorio entre 0 y 10 utilizando la funcion rand.

		- Pide al usuario que introduzca numero entero por teclado.

		- Comprueba si el numero introducido coincide con el generado.

		- A la salida imprime el numero de intentos para adivinarlo.
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

	// Generamos el numero aleatorio del 0 al 10
	srand(getpid());
	numRandom = rand() % 11;
	
	// Comprueba si el numero introducido coincide con el generado.
	while ( adivinado == 0 ){
		// Pedimos el numero 
		printf("Introduce un numero del 1 al 10\n");
		scanf("%d", &numUser);

		numIntentos++;

		if (numUser == numRandom){
			// Imprime el numero de intentos
			printf("Lo has logrado despues de %d intentos", numIntentos);
			adivinado = 1;
		}

	}
}