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

void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");
    
    int num1, num2, sum;
	int *pnum1, *pnum2;

	pnum1 = &num1; // pnum1 almacena la direccion de num1
	pnum2 = &num2; // pnum2 almacena la direccion de num2

	printf("Escribe dos numeros enteros: \n");
	scanf("%d %d", pnum1, pnum2);
	
	sum = *pnum1 + *pnum2;
	printf("Suma = %d", sum);
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}