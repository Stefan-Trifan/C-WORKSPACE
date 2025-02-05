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

int fibonacci(int numero);
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");
    
    int numMax = 0, esValido = 1;

	// Pedimos el numero de elementos. Nos aseguramos de que recibimos los datos en formato válido
	printf("Cuantos elementos quieres: ");
	do
	{
		if(esValido != 1)
		{
			printf("\033[1;31mERROR: El tipo de dato introducido no es válido. Por favor, inténtelo de nuevo: \033[0m");
		}
		esValido = scanf("%d", &numMax);
		if(numMax < 0)
		{
			esValido = 0;
		}
		clearBuffer();
	} 
	while (esValido != 1);

	for(int i = 0; i <= numMax; i++)
	{
		printf("%d ", fibonacci(i));
	}
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

/**
 * @brief Calcula el numero Fibonacci en un aposicion dada
 * @param numero Rrepresenta la psoicion del numero a calcular
 * @return El numero Fibonacci correspondiente a la posición indicada
 */
int fibonacci(int numero)
{
	if(numero == 0 || numero == 1)
	{
		return numero;
	}
	
	return fibonacci(numero - 1) + fibonacci(numero - 2);
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