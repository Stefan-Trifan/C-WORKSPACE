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
    
    printf("Introduce el primer numero: ");
	scanf("%i", &num1);
	printf("Introduce el segundo numero: ");
	scanf("%i", &num2);
	printf("Introduce el tercer numero: ");
	scanf("%i", &num3);


    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void ordenarNumeros(int num1, int num2, int num3)
{
	int numMax = 0;


}

void clearBuffer()
{
	while (getchar() != '\n');
}