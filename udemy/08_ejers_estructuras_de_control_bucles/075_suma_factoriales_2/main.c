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

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");

	int                      
	limiteFactoriales   = 0, // Almacena el limite hasta el cual se calcularan los factoriales,
	j                   = 1, // Contador utilizado para ayudar a calcular el factorial de cada numero,
	acumuladorFactorial = 1, // Guarda el valor del factorial en cada iteracion, y lo va sumando a resultadoFinal,
    resultadoFinal      = 0; // Almacena el resultado final de la suma de los factoriales.    

    printf("Cuantos factoriales quieres sumar: ");
	scanf("%d", &limiteFactoriales);

	for(int i = 0; i <= limiteFactoriales; i++)
	{
		while(j <= i)
		{
			acumuladorFactorial *= j;
			j++;
		}

		resultadoFinal += acumuladorFactorial;
	}
    
	printf("Resultado Final es: %d", resultadoFinal);

	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}