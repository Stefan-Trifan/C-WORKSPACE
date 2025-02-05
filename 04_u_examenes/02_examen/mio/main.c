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

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");

	int opcion = 0, userPassword = 0, tempPassword = 0, sonIguales = 0;
	
	do
	{
		if(userPassword == 0)
		{
			printf("MENU\n"
				"1. Generar password\n"
				"3. Salir\n\n"
				"Introduce un numero entero \n");

			do
			{
				opcion = pedirEntero();
			} 
			while (opcion < 1 || opcion > 3);
			

			switch (opcion)
			{
				case 1: 
					userPassword = generaPassword();
					break;
				case 3: 
					printf("\n\nGracias por utilizar el programa");;
					break;
			}
			printf("\n");
		}
		else
		{
			printf("MENU\n"
				"1. Cambiar password\n"
				"2. Comprobar password\n"
				"3. Salir\n"
				"Introduce un numero entero (si te equivocas no pasa nada) \n");
			
			do
			{
				opcion = pedirEntero();
			} 
			while (opcion < 1 || opcion > 3);

			switch (opcion)
			{
				case 1: 
					userPassword = generaPassword();
					break;
				case 2: 
					printf("Introduce la paswword ");
					tempPassword = pedirEntero();
					sonIguales = sonNumerosIguales(tempPassword, userPassword);
					if(sonIguales)
					{
						printf("La password es correcta\n");
					}
					else
					{
						printf("La password no es correcta\n");
					}
					break;
				case 3: 
					printf("\n\nGracias por utilizar el programa");;
					break;
			}
			printf("\n");
		}


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
	int pass = 0;
	printf("Genera una password de 7 cifras con al menos 3 pares: ");
	pass = pedirEntero();
	return pass;
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
	if(numero1 == numero2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
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
		esValido = scanf("%d", &num);
		clearBuffer();
		if (esValido == 0)
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