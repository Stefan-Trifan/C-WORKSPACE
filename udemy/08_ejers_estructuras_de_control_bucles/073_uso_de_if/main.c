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

	int num = 0;
	long long resultado = 0;
    
    printf("Introduce un numero: ");
	scanf("%i", &num);

	if(num > 10)
	{
		resultado = 1;
		for(int i = 1; i <= 10; i++)
		{
			resultado *= i;
		}
	}
	else
	{
		for(int i = 0; i <= num; i++)
		{
			resultado += i;
		}
	}

	printf("Resultado: %lld", resultado);
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer(){
	while (getchar() != '\n');
}