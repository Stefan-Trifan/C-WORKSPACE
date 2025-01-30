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

	* 	Enunciado Password Numérica
		Crea un programa en el que el usuario generará o cambiará una password numérica con unas condiciones determinadas y una vez generada introducirá una password y comprobará que sea correcta.

		Para ello el programa debe:

		Presentar un menú que se repetirá hasta que no se le indique que se desea salir. Las opciones del menú dependerán de si el usuario ha generado una password correcta o no

		Si no ha generado una clave correcta el menú será:
		1.Generar password
		2.Introducir password
		3.Salir
		Si se ha generado una clave correcta el menú será:
		1.⁠ ⁠Cambia password
		2.⁠ ⁠Introducir passwork
		3.⁠ ⁠Salir

		Las condiciones de password correcta son:
		Ser un número entero de 7 cifras y
		Al menos 3 cifras deben ser pares.

		Cuando se selecciona las opciones genera o cambia password se debe comprobar que se cumplen las condiciones y si no se cumplen indicárselo al usuario y volver a pedir que ingrese una password que cumpla las condiciones (7 cifras y al menos 3 pares).

		Cuando se introduce una password se debe comprobar que esta coincida con la generada. Tanto si coincide como si no se deber informar al usuario y volver a presentar el menú.

		Se deben utilizar las siguientes funciones:

		/// Función que no se le pasa ningún parámetro y devuelve un entero con una passwod correcta
		int generaPassword();

		/// Función que se le pasa como parámetro un entero y devuelve verdadero si tiene 7 cifras y falso si no
		int esNumero7cifras (int numero);

		/// Función que se le pasa como parámetro un entero y devuelve verdadero si tiene al menos 3 cifras son pares y falso si no
		int esNumero3pares (int numero);

		/// Función que se le pasa como parámetros dos enteros y devuelve verdadero si son iguales y falso si no lo son
		int sonNumerosIguales (int numero1, int numero2);

		Un ejemplo de ejecución puede ser:

		./password_menu_red.exe

		Menú:
		1.⁠ ⁠Genera password
		2.⁠ ⁠Introducir password
		3.⁠ ⁠Salir
		Seleccione una opción: 1
		Genera una password de 7 cifras con al menos 3 pares: 1112222
		Password generada correctamente.

		Menú:
		1.⁠ ⁠Cambia password
		2.⁠ ⁠Introducir password
		3.⁠ ⁠Salir

		Seleccione una opción: 2
		Introduce la password: 1112222
		La password es correcta.

		Menú:
		1.⁠ ⁠Cambia password
		2.⁠ ⁠Introducir password
		3.⁠ ⁠Salir
		Seleccione una opción: 3
		Saliendo del programa.
		*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>

int generaPassword();
int esNumero7cifras (int numero);
int esNumero3pares (int numero);
int sonNumerosIguales (int numero1, int numero2);

int pedirEntero();
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main()
{
	printf("\n_________________________________________START\n\n");

	int opcion = 0;
	
	do
	{
		printf("MENU\n"
			   "1. Generar password\n"
		       "2. Introducir password\n"
		       "3. Salir\n"
			   "Introduce un numero entero (si te equivocas no pasa nada) \n");
		opcion = pedirEntero();
	} 
	while (opcion != 3);
    
	
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Función que no se le pasa ningún parámetro y devuelve un entero con una passwod correcta
int generaPassword()
{

	return 0;
}

// Función que se le pasa como parámetro un entero y devuelve verdadero si tiene 7 cifras y falso si no
int esNumero7cifras (int numero)
{
	return 0;
}

// Función que se le pasa como parámetro un entero y devuelve verdadero si tiene al menos 3 cifras son pares y falso si no
int esNumero3pares (int numero)
{
	return 0;
}

// Función que se le pasa como parámetros dos enteros y devuelve verdadero si son iguales y falso si no lo son
int sonNumerosIguales (int numero1, int numero2)
{
	return 0;
}

void clearBuffer()
{
	while (getchar() != '\n');
}

int pedirEntero()
{
	int num = 0, esValido = 1;
	printf("-> ");
	do
	{
		esValido = scanf("%i", &num);
		clearBuffer();
		if (esValido == 0 || num < 1 || num > 3)
		{
			printf(
				"\033[1;31mERROR: No pasa nada, todos nos equivocamos \n\033[0m"
				"\033[1;31m-> \033[0m"
			);
			esValido = 0;
		}
	}
	while (esValido != 1);
	return num;
}