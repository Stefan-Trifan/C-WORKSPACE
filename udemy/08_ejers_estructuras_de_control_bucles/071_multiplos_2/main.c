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
		LoremIpsumDummyText
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
    
    int numMax = 0, base = 0;

	printf("De que numero quieres sacar múltiplos (base): ");
	scanf("%d", &base);

	printf("Hasta que numero quieres sacar multiplos: ");
	scanf("%d", &numMax);

	for(int i = 0; i <= numMax; i++)
	{
		if(i % base == 0)
		{
			printf("%d\n", i);
		}
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