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
		Comprobar si un numero entero es primo, teniendo en cuenta que un primo solo tiene 2 divisores.
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
    
    int num = 0;
	int contador = 0;

	printf("Introduce un numero: ");
	scanf("%d", &num);

	for(int i = 1; i <= num; i++)
	{
		if(num % i == 0)
		{
			contador++;
		}
	}

	if(contador == 2 || num == 1)
	{
		printf("El numero es primo\n");
	} 
	else
	{
		printf("El numero no es primo");
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