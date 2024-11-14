/*
*	Autor
	Stefan Trifan

*	Compilar
	mac     : gcc main.c -o main
	windows : gcc main.c -o main.exe
			: ./main.exe

*	Introducir después de scanf
	limpiar()

*	Enunciado X
	LoremIpsumDummyText
 */

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int main(){
	/*  
		Los datos compuestos: arreglos
		- Coleccion de elemntos del mismo tipo que se almacenan en una unica variable
		- Existen arreglos de caracteres, de enteros, etc
		- Podemos utilizar tipsod e datos primitivos

		* Tamaño:
		Ejemplo: si un int ocupa 4 bytes y almacenamos 10 enteros en una array
			4bytes x 10 = 40 bytes

	*/

	// Declaramos un arreglo
	char a[30];
	printf("Escribe tu nombre sin espacios: ");
	scanf("%s", a);
	printf("Tu nombre es: %s\n", a);

	return 0;
}