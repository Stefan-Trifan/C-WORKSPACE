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
    
    float op1 = 0.0, op2 = 0.0;

	int posicon_igual = 0;
	int letra = 0;

	char ope[14] = "";
	char temp = ' ';

	for(int argumento = 1; argumento < argc; argumento++)
	{

		do
		{
			printf("%c", argv[argumento][letra]);
			letra++;
		} 
		while (argv[argumento][letra] != '\0');

		letra = 0;
		printf(" ");
	}


















	// TODO Hacer validacion para comprobar que el usuario ha introducido 4 parametros

	// TODO Leer Operando (valido 1 y 2)
		// TODO Comprobar Inicio
		// TODO Si Correcto -> Asignar Operando

	// TODO Leer Operación
		// TODO Comprobar Inicio
		// TODO Si Correcto -> Asignar Operacion

	// TODO Realizar Operaciónote
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}