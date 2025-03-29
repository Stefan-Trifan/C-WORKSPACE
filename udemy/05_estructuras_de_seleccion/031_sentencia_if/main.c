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
	printf("\n___________________________START\n\n");

	int a, b, c;

	printf("Digite el primer numero: ");
	scanf("%d", &a);
	printf("Digite el segundo numero: ");
	scanf("%d", &b);

	printf("Digite la suma de los 2 numeros: ");
	scanf("%d", &c);
    
	if(a + b == c){
		printf("Sabes sumar");
	} 
	if(a + b != c) {
		printf("No sabes sumar");
	}
    
	printf("\n\033[1;32m___________________________EXIT_SUCCESS\033[0m\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}