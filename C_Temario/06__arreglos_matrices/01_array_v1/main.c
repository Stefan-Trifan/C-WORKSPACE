/*
	*	Autor
		Stefan Trifan

	* 	Compilar
		mac     : comp
				  run
		windows : gcc main.c -o main.exe
				: ./main.exe

	* 	Introducir despues de scanf
		limpiar()

	* 	Enunciado 8
		LoremIpsumDummyText
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define TAM_ARRAY 10

// Llamamos con limpiar()
void limpiar(){
	while (getchar() != '\n');
}

int generaNumero0a30();

int main(){
	printf("\n________________________________________________\n\n");

	srand(getpid());

	int array[TAM_ARRAY];
	int numUser  = 0;

	// Generamos el array con numeros aleatorios
	for(int i = 0; i < TAM_ARRAY; i++){
		array[i] = generaNumero0a30();
	}

	// Imprimimos el array
	for(int i = 0; i < TAM_ARRAY; i++){
		printf("%i\n", array[i]);
	}

	// Pedimos un numero entre 0 al 30
	printf("Introduce un numero del 0 al 30: ");
	scanf("%i", &numUser);

	// Comprobamos si esta en el array
	for(int i = 0; i < TAM_ARRAY; i++){

		if(array[i] == numUser){
			printf("El numero esta en el array\n");
		}

	}

	printf("\n________________________________________________\n\n");
	return 0;
}

int generaNumero0a30(){
	return((int)rand() % 31);
}