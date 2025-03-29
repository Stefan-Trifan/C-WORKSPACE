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

	int numLimite = 0, resultado = 0, contNumero = 0;
    
    printf("Suma de numeros pares hasta el numero: ");
	scanf("%d", &numLimite);

	for(int i = 0; i <= numLimite; i++)
	{
		if(i % 2 == 0)
		{
			printf("+%d\n", i);
			resultado += i;
			contNumero++;
		}
	}

	printf("Resultado final es %d y hay %d numeros\n", resultado, contNumero);
    
	printf("\n_________________________________________EXIT\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}