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

	printf("Hasta que numero quieres multiplos de 2, 3, 5 y 7: ");
	scanf("%d", &numMax);

	for(int i = 0; i < numMax; i++)
	{
		if((i % 2 == 0) || (i % 3 == 0) || (i % 5 == 0) || (i % 7 == 0))
		{
			printf("%d\n", i);
		}
	}
    
	printf("\n_________________________________________EXIT\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}