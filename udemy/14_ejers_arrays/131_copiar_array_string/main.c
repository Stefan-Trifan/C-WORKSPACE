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

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#define TAM_ARR 5
void copiarArray(char *arr1,char *arr2);

void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");
    
	char arr1[TAM_ARR] = {'h','o','l','a','\0'},
	     arr2[TAM_ARR] = {' '};

	printf("Al principio\n");
	printf("arr1: %s\n", arr1);
	printf("arr2: %s\n\n", arr2);

	// Copiamos
	copiarArray(arr1, arr2);

	printf("arr2: %s\n", arr2);
    
	printf("\n_________________________________________EXIT\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void copiarArray(char *arr1,char *arr2)
{
	printf("Copiando el array...\n\n");
	for(int i = 0; i < TAM_ARR; i++)
		arr2[i] = arr1[i];
}

void clearBuffer()
{
	while (getchar() != '\n');
}