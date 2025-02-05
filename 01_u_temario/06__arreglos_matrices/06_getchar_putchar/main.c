/*
	*	Autor
		Stefan Trifan

	* 	Compilar
		mac     : comp (compilar)
				  run  (ejecutar)
				  brun (compilar y ejecutar)
		windows : gcc main.c -o main.exe
				: ./main.exe

	* 	Enunciado 26 - Ejemplo getchar() y putchar()
		Solicita al usuario su nombre y apellido utilizando getchar(). 
		Almacénalo en una cadena de caracteres de 40 elementos. 
		Imprime ambas la cadena por pantalla con putchar().

	!	Importante
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#define MAX 40

void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");

    char nombre[MAX];
	int  posicionNombre = 0;
	char caracter = '\0';

	// Leer caracteres con getchar() hasta que se presione Enter
	while(caracter != '\n'){

		caracter = getchar();

		if(caracter != '\n'){
			nombre[posicionNombre]=caracter;
			posicionNombre++;
		}

	}
	nombre[posicionNombre] = '\0'; // Añadir el terminador nulo al final de la cadena

	// Imprimir la cadena con putchar()
    printf("Nombre es: ");
    for (int i = 0; nombre[i] != '\0'; i++) {
        putchar(nombre[i]);
    }
    printf("\n");
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}