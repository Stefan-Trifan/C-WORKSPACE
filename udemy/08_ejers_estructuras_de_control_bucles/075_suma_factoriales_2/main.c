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
		1! + 2! + 3! + 4! + 5! + 6!
		1 + 1*2 + 1*2*3 + 1*2*3*4 + 1*2*3*4*5
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

	int                      
	limiteFactoriales   = 0, // Almacena el límite hasta el cual se calcularán los factoriales,
	j                   = 1, // Contador utilizado para ayudar a calcular el factorial de cada número,
	acumuladorFactorial = 1, // Guarda el valor del factorial en cada iteración, y lo va sumando a resultadoFinal,
    resultadoFinal      = 0; // Almacena el resultado final de la suma de los factoriales.    

    printf("Cuantos factoriales quieres sumar: ");
	scanf("%i", &limiteFactoriales);

	for(int i = 0; i <= limiteFactoriales; i++)
	{
		while(j <= i)
		{
			acumuladorFactorial *= j;
			j++;
		}

		resultadoFinal += acumuladorFactorial;
	}
    
	printf("Resultado Final es: %i", resultadoFinal);

	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}