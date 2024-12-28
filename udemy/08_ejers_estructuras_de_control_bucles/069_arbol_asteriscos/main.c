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
		*
		**
		***
		****
		*****
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>

void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(){
	printf("\n_________________________________________START\n\n");

	int numMax = 0, stars = 0;
    
    printf("Cuantas filas de asteriscos quieres: ");
	scanf("%i", &numMax);

	for(int i = 0; i <= numMax; i++)
	{
		while(stars < i)
		{
			printf("*");
			stars++;
		}
		stars = 0;
		printf("\n");
	}
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer(){
	while (getchar() != '\n');
}