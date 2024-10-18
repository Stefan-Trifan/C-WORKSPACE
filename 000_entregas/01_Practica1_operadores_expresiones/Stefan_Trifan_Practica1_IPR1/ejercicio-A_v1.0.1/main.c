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
	*	Ejercicio A. Clave de tres caracteres

		El programa deberá pedir una clave de 3 caracteres separados por guiones al usuario.  

		La clave deberá contener una letra mayúscula, una letra minúscula y un dígito, escritos en cualquier orden.

		El programa deberá comprobar si la clave es válida o no y mostrar el mensaje correspondiente:  
		“Clave correcta” o “Clave incorrecta”.

	*	Ejemplo de ejecución:

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

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int main(){

	// Declaramos las variables que utilizaremos en el programa
	char c1, guion1, c2, guion2, c3, c4;
	int  contadorClave  = 0;

	// Pedimos la clave al usuario y la mostramos por pantalla
	printf("La clave deberá contener 3 caracteres separados por guines. Ejemplo: 3-a-D\n");
	printf("La clave deberá contener al menos una letra mayúscula, una letra minúscula y un dígito, escritos en cualquier orden.\n");
	printf("Por favor, Introduce la clave: ");
	c1     = getchar();
	guion1 = getchar();
	c2     = getchar();
	guion2 = getchar();
	c3     = getchar();
	c4     = getchar();
	printf("Tu clave es: %c%c%c%c%c\n", c1, guion1, c2, guion2, c3);

	/*
		Clave debe tener al menos: letra mayúscula, letra minúscula, dígito (cualquier orden)
		Comrpobamos si la clave es correcta o no
	*/

	// Comprobamos si 2º y 4º caracter son guiones
	if (guion1 == '-' && guion2 == '-')
		contadorClave++;

	// Comprobamos si algun caracter es letra mayús
	if ((c1 >= 65) && (c1 <= 90) || (c2 >= 65) && (c2 <= 90) || (c3 >= 65) && (c3 <= 90))
		contadorClave++;
	
	// Comprobamos si algun caracter es letra minus
	if ((c1 >= 97) && (c1 <= 122) || (c2 >= 97) && (c2 <= 122) || (c3 >= 97) && (c3 <= 122))
		contadorClave++;

	// Comprobamos si algun caracter es dígito
	if ((c1 >= 48) && (c1 <= 57) || (c2 >= 48) && (c2 <= 57) || (c3 >= 48) && (c3 <= 57))
		contadorClave++;

	// Comprobamos si la clave solo tiene 5 caracteres.
	// Si el 6 carácter es un salto de línea, entonces los primeros 5 van a ser la clave.
	// Si el 6 carácter es caracter, la clave es demasiado larga
	if (c4 == '\n')
		contadorClave++;

	// Imprimimos el resultado
	if (contadorClave == 5)
		printf("La clave es correcta.\n");
	else	
		printf("La clave es incorrecta.\n");

	return 0;
}