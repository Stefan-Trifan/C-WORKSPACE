/*
	*	Autor
		Stefan Trifan

	* 	Compilar
		mac     : comp (compilar)
				  run  (ejecutar)
				  brun (compilar y ejecutar)
		windows : gcc main.c -o main.exe
				: ./main.exe

	* 	Enunciado X
		Rellenar un array de 10 posiciones con numeros introducidos por el usuario
		Una vez tengais el array con los datos del usuario imprimir el mayor, el menor y la media y la suma total
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#define TAM_ARRAY 3

void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(){
	printf("\n_________________________________________START\n\n");
    
	// Declaramos variables
    int array[TAM_ARRAY];
	int max=0,min=0,suma=0;
	
	// Pedimos los 5 numeros
	for(int i = 0; i < TAM_ARRAY; i++){

		printf("Introduce un numero: ");
		scanf("%i", &array[i]);

	}
	
	for(int i = 0; i < TAM_ARRAY; i++){

		if(i==0){
			max=array[i];
			min=array[i];
		}

		if(array[i] < min){
			min = array[i];
		}

		if(array[i] > min){
			max = array[i];
		}

		suma += array[i];

	}

	printf("Min es: %i\n", min);
	printf("Max es: %i\n", max);
	printf("Suma es: %i\n", suma);
	

	// Imprimimos los resultados

    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer(){
	while (getchar() != '\n');
}