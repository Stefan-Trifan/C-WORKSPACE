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

	int numMax = 0, resultado = 0;
    
    printf("Hasta que numero quieres operar: ");
	scanf("%d", &numMax);

	for(int i = 0; i <= numMax; i++){
		
		if( i % 2 == 0){
			resultado -= i; // Pares
		}
		else {
			resultado += i; // Impares
		};
	};

	printf("%d", resultado);
    
	printf("\n_________________________________________EXIT\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}