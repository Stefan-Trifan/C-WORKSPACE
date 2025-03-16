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

	* 	Enunciado
		LoremIpsum
*/

/* 
	Array Unidimensional
	Es una secuencia de datos 

	Array o Arreglos Unidimensionales

	Arrays Enteros
	Arrays Flotantes
	Arrays de Caracter
	Arrays de String (Conjunto de Caracteres)

	Empiezan en el cero NUNCA EN UNO  
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#define MAX_TAM 5



void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");
    
    int array[MAX_TAM] = {1,2,3,4,5};
	
	for(int i = 0; i <= MAX_TAM; i++)
	{
		printf("%d ", array[i]);
	}
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}