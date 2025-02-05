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
		1 * 2 * 3
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
    
    int numVueltasMax = 0, resultado = 1;

	printf("Introduce un numero: ");
	scanf("%d", &numVueltasMax);

	for(int i = 1; i <= numVueltasMax; i++)
	{
		resultado = resultado * i;
		printf("i = %d: %d\n", i, resultado);
	}

	printf("Resultado Final es: %d", resultado);
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}