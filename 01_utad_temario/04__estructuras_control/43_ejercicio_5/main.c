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

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>

void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");
    
    int numMax = 0;
	int resultado = 0;
	int i = 0;

	// Solicita al usuario que introduzca un numero
	printf("Introduce un numero para ver si es perfecto: ");
	scanf("%d", &numMax);

	// Inicializa el bucle para verificar si el numero es perfecto
	do {
		// Verifica si el numero actual es un divisor de numMax
		if(numMax % i == 0)
		{
			// Suma el divisor al resultado
			resultado = resultado + i;
		}
		i++;
	} while (i < numMax); // Continua el bucle hasta que i sea menor que numMax

	// Verifica si la suma de los divisores es igual al numero en si
	if(resultado == numMax)
	{
		// Si es verdadero, el numero es perfecto
		printf("El numero es perfecto");    
	}
	else
	{
		// Si es falso, el numero no es perfecto
		printf("El numero no es perfecto");
	}
    
	printf("\n\033[1;32m_________________________________________EXIT_SUCCESS\033[0m\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}