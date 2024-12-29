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

void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(){
	printf("\n_________________________________________START\n\n");

	int numLimite = 0, resultado = 0;
    
    printf("Ingresa el numero limite: ");
	scanf("%i", &numLimite);

	for(int i = 0; i <= numLimite; i++)
		if(i % 2 == 0)
			resultado += i;	
		else
			resultado -= i;

	printf("Resultado final es: %i\n", resultado);

    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer(){
	while (getchar() != '\n');
}