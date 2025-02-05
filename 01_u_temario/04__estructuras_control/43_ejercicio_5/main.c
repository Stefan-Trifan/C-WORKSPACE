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

int main()
{
	printf("\n_________________________________________START\n\n");
    
    int numMax = 0;
	int resultado = 0;
	int i = 0;

	// Solicita al usuario que introduzca un número
	printf("Introduce un número para ver si es perfecto: ");
	scanf("%d", &numMax);

	// Inicializa el bucle para verificar si el número es perfecto
	do {
		// Verifica si el número actual es un divisor de numMax
		if(numMax % i == 0)
		{
			// Suma el divisor al resultado
			resultado = resultado + i;
		}
		i++;
	} while (i < numMax); // Continúa el bucle hasta que i sea menor que numMax

	// Verifica si la suma de los divisores es igual al número en sí
	if(resultado == numMax)
	{
		// Si es verdadero, el número es perfecto
		printf("El número es perfecto");    
	}
	else
	{
		// Si es falso, el número no es perfecto
		printf("El número no es perfecto");
	}
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}