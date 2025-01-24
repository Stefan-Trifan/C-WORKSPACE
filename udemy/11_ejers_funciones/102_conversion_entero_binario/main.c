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

void convertirDecimalBinario(int numDecimal);

void clearBuffer();

/* _________________________________________
   Inicio main() */

int main()
{
	printf("\n_________________________________________START\n\n");
    
    int numDecimal = 0, esValido = 1, resultado = 0;

	/**
	 * @brief Solicita al usuario un numero entero positivo
	 * Validamos: - Si numDecimal es numero entero 
	 * 			  - Si numDecimal es mayor a 0
	 */
	printf("Introduce un numero decimal positivo: ");
	do
	{
		if(esValido == 0) printf
		(
			"\033[1;31mERROR: El tipo de dato introducido no es válido. Por favor, introduzca un numero. \n\033[0m"
			"\033[1;31m-> \033[0m"
		);
		if(esValido == 2) printf
		(
			"\033[1;33mALERTA: Por favor, introduzca un numero positivo. \n\033[0m"
			"\033[1;33m-> \033[0m"
		);

		esValido = scanf("%i", &numDecimal);
		clearBuffer();
		if(numDecimal < 0) esValido = 2;
	} 
	while (esValido != 1);

	// Mostramos el resultado final
	printf("El numero en binario es: ");
	convertirDecimalBinario(numDecimal);
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

/**
 * @brief convierte un numero de decimal a binario
 */
void convertirDecimalBinario(int numDecimal)
{
	if(numDecimal > 1)
		convertirDecimalBinario(numDecimal / 2);

	printf("%i", numDecimal % 2);
}

void clearBuffer()
{
	while (getchar() != '\n');
}

