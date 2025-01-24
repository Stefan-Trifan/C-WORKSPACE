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
		
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>

int fibonacci(int numElementos);
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main()
{
	printf("\n_________________________________________START\n\n");
    
    int numElementos = 0, esValido = 1;

	printf("Cuantos elementos quieres: ");
	do
	{
		if(esValido != 1)
		{
			printf("\033[1;31mERROR: El tipo de dato introducido no es válido. Por favor, inténtelo de nuevo: \033[0m");
		}
		esValido = scanf("%i", &numElementos);
		clearBuffer();
	} 
	while (esValido != 1);

	for(int i = 0; i <= numElementos; i++)
	{
		printf("%i ", fibonacci(i));
	}
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */



int fibonacci(int numElementos)
{
	if(numElementos == 0 || numElementos == 1)
	{
		return numElementos;
	}
	
	return fibonacci(numElementos - 1) + fibonacci(numElementos - 2);
}


void clearBuffer()
{
	while (getchar() != '\n');
}

/* 
	0 1 1 2 3 4 8
	a_n = a_{n - 1} + a_{n - 2}
	fibona(n) = fibona(n - 1) + fibona(n - 2)
*/

/*  
	fib(0): 
		-> 0  // Caso base

	fib(1): 
		-> 1  // Caso base

	fib(2): 
		-> fib(1) + fib(0) 

		-> 1 + 0 -> 1  

	fib(3): 
		-> fib(2) + fib(1) 
		-> fib(1) + fib(0) + fib(1) 

		-> 1 + 0 + 1 -> 2  

	fib(4): 
		-> fib(3) + fib(2)  
	    -> (fib(2) + fib(1)) + (fib(1) + fib(0))  
	    -> ((fib(1) + fib(0)) + fib(1)) + (fib(1) + fib(0))  
	
	    -> ((1 + 0) + 1) + (1 + 0) -> 2 + 1 -> 3

	fib(5): 
		-> fib(4) + fib(3)  
		-> (fib(3) + fib(2)) + (fib(2) + fib(1))  
		-> ((fib(2) + fib(1)) + (fib(1) + fib(0))) + ((fib(1) + fib(0)) + fib(1))  
		-> (((fib(1) + fib(0)) + fib(1)) + (fib(1) + fib(0))) + ((fib(1) + fib(0)) + fib(1))

		-> (((1 + 0) + 1) + (1 + 0)) + ((1 + 0) + 1) -> (2 + 1) + (1 + 1) -> 3 + 2 -> 5

	fib(6): 
		-> fib(5) + fib(4)   
		-> (fib(4) + fib(3)) + (fib(3) + fib(2))  
		-> ((fib(3) + fib(2)) + (fib(2) + fib(1))) + ((fib(2) + fib(1)) + (fib(1) + fib(0)))  
		-> (((fib(2) + fib(1)) + (fib(1) + fib(0))) + ((fib(1) + fib(0)) + fib(1)))  

		-> (((1 + 0) + 1) + (1 + 0)) + ((1 + 0) + 1) -> 5 + 3 -> 8
*/