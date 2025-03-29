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

void ordenarDescendiente(float num1, float num2, float num3);
int  solicitarFloat();
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n___________________________START\n\n");
    
    float num1 = 0, num2 = 0, num3 = 0;

	printf("Introduce el primer numero  \n");
	num1 = solicitarFloat();
	printf("Introduce el segundo numero \n");
	num2 = solicitarFloat();
	printf("Introduce el tercer numero  \n");
	num3 = solicitarFloat();

	printf("%f %f %f\n", num1, num2, num3);

	ordenarDescendiente(num1, num2, num3);
    
	printf("\n\033[1;32m___________________________EXIT_SUCCESS\033[0m\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */
int solicitarFloat()
{
	int esValido = 1;
	float num = 0;
	printf("-> ");
	do
	{
		esValido = scanf("%f", &num);
		clearBuffer();
		if(esValido != 1)
		{
			printf(
				"\033[1;31mERROR: El tipo de dato introducido no es valido. Por favor, intentelo de nuevo. \n\033[0m"
				"\033[1;31m-> \033[0m"
			);
		}
	} 
	while (esValido != 1);
	return num;
}

void ordenarDescendiente(float num1, float num2, float num3)
{
	float numMin = 0, numMed = 0, numMax = 0;

	if(num1 >= num2 && num1 >= num3)
	{
		numMax = num1;
		if(num2 >= num3)
		{
			numMed = num2;
			numMin = num3;
		}
		else
		{
			numMed = num3;
			numMin = num2;
		}
	}

	if(num2 >= num1 && num2 >= num3)
	{
		numMax = num2;
		if(num1 >= num3)
		{
			numMed = num1;
			numMin = num3;
		}
		else
		{
			numMin = num1;
			numMed = num3;
		}
	}

	if(num3 >= num1 && num3 >= num2)
	{
		numMax = num3;
		if(num1 >= num2)
		{
			numMed = num1;
			numMin = num2;
		}
		else
		{
			numMed = num2;
			numMin = num1;
		}
	}

	printf("%f %f %f\n", numMax, numMed, numMin);
}

void clearBuffer()
{
	while (getchar() != '\n');
}