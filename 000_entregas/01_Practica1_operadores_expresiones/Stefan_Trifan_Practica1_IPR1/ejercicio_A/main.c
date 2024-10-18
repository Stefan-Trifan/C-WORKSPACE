/*
*	Autor
		Stefan Trifan

*	Compilar
		mac     : gcc main.c -o main
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

		```bash
		$ ./clave.exe
		Introduce la clave: u-6-F
		La clave es correcta.

		$ ./clave.exe
		Introduce la clave: 7-6-F
		La clave es incorrecta.

		$ ./clave.exe
		Introduce la clave: u6F
		La clave es incorrecta.
		```
 */

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int main(){

}