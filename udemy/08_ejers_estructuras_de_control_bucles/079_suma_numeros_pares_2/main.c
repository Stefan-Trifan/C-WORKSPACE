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

void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");

	int primerNum = 0, ultimoNum = 0, resultado = 0, contNumero = 0;

	printf("Suma de numeros pares desde que numero: ");
	scanf("%d", &primerNum);
	
	do {
		printf("Suma de numeros pares hasta el numero:  ");
		scanf("%d", &ultimoNum);
	} while (primerNum > ultimoNum);

	for(int i = primerNum; i <= ultimoNum; i++)
	{
		if(i % 2 == 0)
		{
			printf("+%d\n", i);
			resultado += i;
			contNumero++;
		}
	}

	printf("Resultado final es %d y hay %d numeros\n", resultado, contNumero);
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}