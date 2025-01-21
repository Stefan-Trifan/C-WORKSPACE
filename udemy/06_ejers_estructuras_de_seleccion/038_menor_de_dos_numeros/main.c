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
		LoremIpsumDummyText
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>

void clearBuffer();

/* _________________________________________
   Inicio main() */

int main()
{
	printf("\n_________________________________________START\n\n");

	float numero1, numero2;
    
	printf("Introduce el primer numero: ");
	scanf("%f", &numero1);

	printf("Introduce el segundo numero: ");
	scanf("%f", &numero2);
	
	(numero1 > numero2) ? printf("El primer numero (%f) es mayor", numero1) : printf("El segundo numero (%f) es mayor", numero2);
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}