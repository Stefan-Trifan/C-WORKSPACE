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
		 4  8 12 16 ..
		 6 12 18 24 ..
		 7 14 21 28 ..
		 5 10 15 20 ..
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
int pedirEntero();
void clearBuffer();

/* _________________________________________
   Inicio main() */


int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");

	int arr1[4][5][2] = {0},
	    cont          = 0,
		
	*puntero_a_arr1;
	puntero_a_arr1 = &arr1[0][0][0];
	
	for(int i = 0; i < 40; i++)
	{
		if(i < 10)
		{	
			if(i == 0) cont = 4;
			*(puntero_a_arr1 + i) = cont;
			cont += 4;
		}
		if(i >= 10 && i < 20)
		{
			if(i == 10) cont = 6;
			*(puntero_a_arr1 + i) = cont;
			cont += 6;
		}
		if(i >= 20 && i < 30)
		{
			if(i == 20) cont = 7;
			*(puntero_a_arr1 + i) = cont;
			cont += 7;
		}
		if(i >= 30)
		{
			if(i == 30) cont = 5;
			*(puntero_a_arr1 + i) = cont;
			cont += 5;
		}
	}
	
	printf("\n\n");
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			for(int k = 0; k < 2; k++)
			{
				printf("[ %2d ]  ", arr1[i][j][k]);
			}
			printf("\n");
		}
		printf("\n\n");
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

int pedirEntero()
{
	int num = 0, esValido = 1;
	printf("El valor de la posicion que deseas concer \n");
	printf("-> ");
	do
	{
		esValido = scanf("%d", &num);
		clearBuffer();
		if (esValido == 0)
		{
			printf(
				"\033[1;31mERROR: El tipo de dato introducido no es valido. Por favor, intentelo de nuevo. \n\033[0m"
				"\033[1;31m-> \033[0m"
			);
			esValido = 0;
		}
	}
	while (esValido != 1);
	return num;
}