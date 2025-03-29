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
int pedirEntero();
void clearBuffer();

/* _________________________________________
   Inicio main() */


int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");

	int arr1[4][5][2], cont = 0, miPosicion = 0, miNum;
	int *puntero_a_arr1;
	puntero_a_arr1 = &arr1[0][0][0];
	
	for(int i = 0; i < 4; i++)
	{
		printf("Matriz %d: \n", i + 1);
		for(int j = 0; j < 5; j++)
		{
			for(int k = 0; k < 2; k++)
			{
				arr1[i][j][k] = cont;
				printf("%2d ", arr1[i][j][k]);
				cont += 2;
			}
			printf("\n");
		}
		printf("\n");
	}

	miPosicion = pedirEntero();	

	miNum = *(puntero_a_arr1 + miPosicion);

	printf("El valor de tu posicion es %d\n", miNum);

	printf("\n_________________________________________EXIT\n\n");
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