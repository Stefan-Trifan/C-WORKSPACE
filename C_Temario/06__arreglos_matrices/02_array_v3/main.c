/*
	*	Autor
		Stefan Trifan

	* 	Compilar
		mac     : gcc main.c -o main
		windows : gcc main.c -o main.exe
				: ./main.exe

	* 	Introducir después de scanf
		limpiar()

	* 	Enunciado 8
		LoremIpsumDummyText
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define TAM_ARRAY 3

// Llamamos con limpiar()
void limpiar(){
	while (getchar() != '\n');
}

int generaNumero0a30();

int main(){
	printf("\n_________________________________________\n\n");

	// srand(unsigned int seed): Inicializa la semilla para el generador de números pseudoaleatorios.
	// getpid(): Obtiene el identificador de proceso único del programa que se está ejecutando.
	srand(getpid());

	int array[TAM_ARRAY];
	int numUser  = 0;
	int encontrado = 0;

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
			printf("El número está en el array\n");
			encontrado = 1;
			break;
		}

	}

	if(encontrado == 0){
		printf("El número no está en el array");
	}

	printf("\n_________________________________________\n\n");
	return 0;
}

int generaNumero0a30(){
	// rand(): Genera números pseudoaleatorios.
	return((int)rand() % 31);
}