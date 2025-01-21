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
		0 + 2 + 4 + 6 + 8 + 10 ...
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

	int numMax = 0, resultado = 0, multiplicador = 0;
    
    printf("Cuantos num quieres sumar: ");
	scanf("%i", &numMax);

	for(int i = 1; i <= numMax; i++)
	{
		resultado += multiplicador;
		printf("Calculando:      +%i\n", multiplicador);
		multiplicador += 2;
	}

	printf("Resultado es:     %i", resultado);
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}