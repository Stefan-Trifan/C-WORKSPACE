/* _________________________________________
   Inicio cabecera */

/*
	*	Autor
		Stefan Trifan

	* 	Compilar
		mac     : comp (compilar)
				  run  (ejecutar)
				  brun (compilar y ejecutar)
		windows : gcc main.c -o main.exe
				: ./main.exe

	*   Estado: todo

	* 	Enunciado 49
		Introducir una unica linea que contenga entre 2 y 10 palabras separadas por coma (,), sin espacios, y presentarlas en orden inverso. Las palabras tendran un maximo de 10 letras. El numero de palabras es desconocido, solo sabemos que seran como minimo 2 y como maximo 10, el programa debe adaptarse a lo que introduzca el usuario.

		Condiciones
		▪ En caso de introducir palabras de mas de 10 letras, el programa mostrara un error y volvera a pedir una linea que contenga las palabras correctas.
		▪ En caso de introducir mas de 10 palabras, o menos de 2, el programa mostrara un error y volvera a pedir la linea.
		▪ Repetir hasta que se tengan todas las palabras introducidas correctamente.
		▪ Mostrar las palabras en orden inverso de introduccion, separadas por comas.

		Ejemplo
		▪ Usuario introduce la linea : perro,gato,oso
		▪ El programa muestra la linea: oso,gato,perro
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
    
    
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}