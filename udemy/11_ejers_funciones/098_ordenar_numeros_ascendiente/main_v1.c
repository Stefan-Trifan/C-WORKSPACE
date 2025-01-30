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

void ordenarNumeros(int num1, int num2, int num3);
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main()
{
	printf("\n_________________________________________START\n\n");

	int num1 = 0, num2 = 0, num3 = 0;
    
    printf("Introduce el num1: ");
	scanf("%d", &num1);
	printf("Introduce el num2: ");
	scanf("%d", &num2);
	printf("Introduce el num3: ");
	scanf("%d", &num3);

	ordenarNumeros(num1, num2, num3);
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void ordenarNumeros(int num1, int num2, int num3)
{
	int numMin = 0, numMedio = 0, numMax = 0;

	if(num1 <= num2 && num1 <= num3)
		numMin = num1;
	if(num2 <= num1 && num2 <= num3)
		numMin = num2;
	if(num3 <= num1 && num3 <= num2)
		numMin = num3;
	
	if(num1 >= num2 && num1 <= num3)
		numMedio = num1;
	if(num2 >= num1 && num2 <= num3)
		numMedio = num2;
	if(num3 >= num1 && num3 <= num2)
		numMedio = num3;

	if(num1 >= num2 && num1 >= num3)
		numMax = num1;
	if(num2 >= num1 && num2 >= num3)
		numMax = num2;
	if(num3 >= num1 && num3 >= num2)
		numMax = num3;

	printf("Numeros ordenados: %d %d %d\n", numMin, numMedio, numMax);

}

void clearBuffer()
{
	while (getchar() != '\n');
}