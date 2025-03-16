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
#define TAM 20
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");
    
    char arr1[TAM], arr2[TAM], temp = ' '; 

	// Creamos los arrays
	printf("arr1 = ");
	scanf("%s", arr1);
	printf("arr2 = ");
	scanf("%s", arr2);
	printf("\n");

	// Imprimimos los arrays antes
	printf("Antes: \n");
	printf("arr1 = %s\n", arr1);
	printf("arr2 = %s\n", arr2);
	printf("\n");

	// Intercambiamos los arrays
	printf("Cambiando arrays...\n\n");
	for(int i = 0; i < TAM; i++)
	{
		temp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = temp;
	}

	// Imprimimos los arrays despues
	printf("Despues: \n");
	printf("arr1 = %s\n", arr1);
	printf("arr2 = %s\n", arr2);
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}