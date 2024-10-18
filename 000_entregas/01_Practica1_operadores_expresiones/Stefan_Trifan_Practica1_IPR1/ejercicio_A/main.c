/*
*	Autor
		Stefan Trifan

*	Compilar
		mac     : gcc main.c -o main
				: ./main
		windows : gcc main.c -o main.exe
			    : ./main.exe

*	Introducir después de scanf
		limpiar()

*	Enunciado
	*	# Ejercicio A. Clave de tres caracteres

		El programa deberá pedir una clave de 3 caracteres separados por guiones al usuario.  

		La clave deberá contener una letra mayúscula, una letra minúscula y un dígito, escritos en cualquier orden.

		El programa deberá comprobar si la clave es válida o no y mostrar el mensaje correspondiente:  
		“Clave correcta” o “Clave incorrecta”.

	*	### Ejemplo de ejecución:

		$ ./clave.exe
		Introduce la clave: u-6-F
		La clave es correcta.

		$ ./clave.exe
		Introduce la clave: 7-6-F
		La clave es incorrecta.

		$ ./clave.exe
		Introduce la clave: u6F
		La clave es incorrecta.

		TRUCO: 
		Redomendado: Se puede hacer con getchar
		Fácil:		 Se puede hacer con cadena de caracteres
 */

#include <stdio.h>
#include <stdbool.h> // Introducimos una nueva librería que nos permite trabajar con variables booleanas

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int main(){

	// Declaramos las variables que utilizaremos en el programa
	char clave[6];
	bool claveCorrecta = false;

	// Pedimos la clave al usuario
	printf(
	"- Por favor, introduce una clave de 3 caracteres separados por guiones. \n"
	"- La clave debe contener una letra mayúscula, una letra minúscula y un dígito (escritos en cualquier orden): \n");

	scanf("%5s", clave);
	limpiar();
	printf("Tu clave es: %s.\n", clave);

	// Comrpobamos si la clave es correcta o no


	// Imprimimos el resultado
	if (claveCorrecta == true)
		printf("La clave es correcta.\n");
	else	
		printf("La clave es incorrecta.\n");

	return 0;
}