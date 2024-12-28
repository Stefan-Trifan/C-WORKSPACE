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

int main(){
	printf("\n_________________________________________START\n\n");
    
    int numMax = 0;

	printf("Hasta que numero quieres multiplos de 2, 3, 5 y 7: ");
	scanf("%i", &numMax);

	for(int i = 0; i < numMax; i++)
	{
		if((i % 2 == 0) || (i % 3 == 0) || (i % 5 == 0) || (i % 7 == 0))
		{
			printf("%i\n", i);
		}
	}
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer(){
	while (getchar() != '\n');
}