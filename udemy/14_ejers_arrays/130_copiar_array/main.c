/*
	*	Autor
		Stefan Trifan

	* 	Compilar
		mac     : comp (compilar)
				  run  (ejecutar)
				  brun (compilar y ejecutar)
		windows : gcc main.c -o main.exe
				: ./main.exe

	*   Estado: 

	* 	Enunciado X
		LoremIpsum
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#define TAM_ARR 5
void copiarArray(int *arr1,int *arr2);

void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");
    
	int arr1[TAM_ARR] = {1,2,3,4,5},
	    arr2[TAM_ARR] = {0};

	printf("Al principio\n");
	for(int i = 0; i < TAM_ARR; i++)
		printf("arr1[i] = %d\n", arr1[i]);
	printf("\n");
	for(int i = 0; i < TAM_ARR; i++)
		printf("arr2[i] = %d\n", arr2[i]);
	printf("\n");

	// Copiamos
	copiarArray(arr1, arr2);

	for(int i = 0; i < TAM_ARR; i++)
		printf("arr2[i] = %d\n", arr2[i]);
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void copiarArray(int *arr1,int *arr2)
{
	printf("Copiando el array...\n\n");
	for(int i = 0; i < TAM_ARR; i++)
	arr2[i] = arr1[i];
}

void clearBuffer()
{
	while (getchar() != '\n');
}