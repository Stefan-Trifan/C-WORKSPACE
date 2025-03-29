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

//Recursividad Capacidad de llamarse a si misma
/*
Ejemplo de Factorial de Un Numero
5! = 5*4*3*2*1 o 5*4! = 120
4! = 4*3*2*1 o 4*3! = 24
3! = 3*2*1 o 3*2! = 6
2! = 2*1 o 2*1! = 2
1! = 1 
0! = 1  
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

	for(int i = 1; i <= num; i++)
	{
		printf("Vuelta %d: %li\n", i, factorial(i));
	}
    
	printf("\n_________________________________________EXIT\n\n");
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