/*
	*	Autor
		Stefan Trifan

	* 	Compilar
		mac     : comp (compilar)
				  run  (ejecutar)
				  brun (compilar y ejecutar)
		windows : gcc main.c -o main.exe
				: ./main.exe

	*   Estado: todo

	* 	Enunciado X
		Suma de dos numeros mas pequeños de un array
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#define TAM_ARRAY 10

int sumarDosNumPequenos(int Array[], int tam);

void limpiarBuffer();

/* _________________________________________
   Inicio main() */

int main(){
	printf("\n_________________________________________START\n\n");
    
	int Array[TAM_ARRAY] = {1,2,3,4,5,6,7,3,9,10}; 
	int tam = TAM_ARRAY;
	int resultado = 0;

	resultado = sumarDosNumPequenos(Array, tam);
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

int sumarDosNumPequenos(int Array[], int tam){

	int min1 = 0;
	int min2 = 0;

	for(int i = 1; i < tam; i++){

		min1 = Array[0];

		if(Array[i] < min1){

			min1 = Array[i];

		}

	}

	printf("%d", min1);

	return 0;
}


void limpiarBuffer(){
	while (getchar() != '\n');
}