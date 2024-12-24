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

void limpiarBuffer();

/* _________________________________________
   Inicio main() */

int main(){
	printf("\n_________________________________________START\n\n");

	int a, b, c;

	printf("Digite el primer numero: ");
	scanf("%i", &a);
	printf("Digite el segundo numero: ");
	scanf("%i", &b);

	printf("Digite la suma de los 2 numeros: ");
	scanf("%i", &c);
    
	if(a + b == c){
		printf("Sabes sumar");
	} 
	if(a + b != c) {
		printf("No sabes sumar");
	}
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void limpiarBuffer(){
	while (getchar() != '\n');
}