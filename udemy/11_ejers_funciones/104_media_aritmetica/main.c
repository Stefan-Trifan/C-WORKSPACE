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

float solicitarNumero();
float mediaAritmetica(float num1, float num2);
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");

	float num1 = 0, num2 = 0, resultado = 0;

	printf("Introduce el primer numero: \n");
	num1 = solicitarNumero();
	printf("Introduce el segundo numero: \n");
    num2 = solicitarNumero();

	resultado = mediaAritmetica(num1, num2);

	printf("El resultado es: %.3f", resultado);
    
	printf("\n_________________________________________EXIT\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

/**
 * @brief Solicita un numero al usuario.
 * 		  Valida que el caracter sea numero
 */
float solicitarNumero()
{
	float num = 0, esValido = 1;
	printf("-> ");
	do
	{
		if(esValido != 1)
		{
			printf(
				"\033[1;31mERROR: El tipo de dato introducido no es valido. Por favor, intentelo de nuevo. \n\033[0m"
				"\033[1;31m-> \033[0m"
			);
		}
		esValido = scanf("%f", &num);
		clearBuffer();
	} 
	while (esValido != 1);
	return num;
}

float mediaAritmetica(float num1, float num2)
{
	return (num1 + num2) / 2;
}

void clearBuffer()
{
	while (getchar() != '\n');
}