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
		0 1 1 2 3 5 7
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>

void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");

	int totalNumbers = 0;
	int num2 = 0, num1 = 1, numActual;
    
    printf("Cuantos numeros de la sucesion de fibonacci quieres calcular: ");
	scanf("%d", &totalNumbers);

	printf("0\n"); // Caso Base
	printf("1\n"); // Caso Base
	
	for(int i = 0; i < totalNumbers; i++)
	{
		numActual = num1 + num2;   // numActual = 1, numActual = 2, numActual = 3, numActual = 5 ...
		printf("%d\n", numActual); 
		num2 = num1;               //      num1 = 1,      num1 = 1,      num1 = 2,      num1 = 3 ...
		num1 = numActual;          //      num2 = 1,      num2 = 2,      num2 = 3,      num2 = 5 ...
	}
	
	printf("\n_________________________________________EXIT\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}
