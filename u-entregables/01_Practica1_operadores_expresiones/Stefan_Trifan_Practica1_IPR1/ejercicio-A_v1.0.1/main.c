/*
*	Autor
		Stefan Trifan

*	Compilar
		mac     : gcc main.c -o main
				: ./main
		windows : gcc main.c -o main.exe
			    : ./main.exe

*	Introducir despues de scanf
		limpiar()

*	Enunciado

	*	Ejercicio A. Clave de tres caracteres

		El programa debera pedir una clave de 3 caracteres separados por guiones al usuario.  

		La clave debera contener una letra mayuscula, una letra minuscula y un digito, escritos en cualquier orden.

		El programa debera comprobar si la clave es valida o no y mostrar el mensaje correspondiente:  
		“Clave correcta” o “Clave incorrecta”.

	*	Ejemplo de ejecucion:

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
		Facil:		 Se puede hacer con cadena de caracteres
*/

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int main(){

	// Declaramos las variables que utilizaremos en el programa
	char c1, guion1, c2, guion2, c3, c4;
	// Contador de requisitos. Si la clave cumple con los 5 requisitos 
	// que declararemos a continuacion, consideraremos que la clave es correcta
	int contadorClave  = 0; 

	// Pedimos la clave al usuario y la mostramos por pantalla
	printf("La clave debera contener 3 caracteres separados por guines. Ejemplo: 3-a-D\n");
	printf("La clave debera contener al menos una letra mayuscula, una letra minuscula y un digito, escritos en cualquier orden.\n");
	printf("Por favor, Introduce la clave: ");
	c1     = getchar();
	guion1 = getchar();
	c2     = getchar();
	guion2 = getchar();
	c3     = getchar();
	c4     = getchar();
	printf("Tu clave es: %c%c%c%c%c\n", c1, guion1, c2, guion2, c3);

	/*
		La clave debe tener al menos: letra mayuscula, letra minuscula, digito (cualquier orden)
		Comrpobamos si la clave es correcta o no
	*/

	// Comprobamos si 2º y 4º caracter son guiones
	if (guion1 == '-' && guion2 == '-')
		contadorClave++;

	// Comprobamos si algun caracter es letra mayus
	if (((c1 >= 65) && (c1 <= 90)) || ((c2 >= 65) && (c2 <= 90)) || ((c3 >= 65) && (c3 <= 90)))
		contadorClave++;
	
	// Comprobamos si algun caracter es letra minus
	if (((c1 >= 97) && (c1 <= 122)) || ((c2 >= 97) && (c2 <= 122)) || ((c3 >= 97) && (c3 <= 122)))
		contadorClave++;

	// Comprobamos si algun caracter es digito
	if (((c1 >= 48) && (c1 <= 57)) || ((c2 >= 48) && (c2 <= 57)) || ((c3 >= 48) && (c3 <= 57)))
		contadorClave++;

	// Comprobamos si la clave solo tiene 5 caracteres.
	// Si el 6 caracter es un salto de linea, entonces los primeros 5 van a ser la clave.
	// Si el 6 caracter es caracter, la clave es demasiado larga
	if (c4 == '\n')
		contadorClave++;

	// Imprimimos el resultado
	if (contadorClave == 5)
		printf("La clave es correcta.\n");
	else	
		printf("La clave es incorrecta.\n");

	return 0;
}