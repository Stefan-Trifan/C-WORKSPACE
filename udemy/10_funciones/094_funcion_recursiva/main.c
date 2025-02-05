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

long factorial(int n);
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");

	int num = 0;

	printf("Introduce un numero: ");
	scanf("%d", &num);
    
	printf("El factorial es: %ld", factorial(num)); 

	
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

long factorial(int num)
{
	if(num <= 1)
	{
		return 1;
	}
	else
	{
		return num * factorial(num - 1);
	}
}

/*  factorial(4)
	return 4 * factorial(3)
		3 * factorial(2)
			2 * factorial(1)
				    1            1

 */

void clearBuffer()
{
	while (getchar() != '\n');
}