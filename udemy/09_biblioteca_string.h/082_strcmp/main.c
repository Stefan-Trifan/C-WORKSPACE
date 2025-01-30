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
		LoremIpsumDummyText
*/

// strcmp(Cadena1, Cadena2)
// Compara 2 cadenas de texto caracter a caracter, es case-sensitive (sensible a mayúsculas y minúsculas). 
// Cuando se encuentra una diferencia, esta función devuelve un valor entero correspondiente 
// a la diferencia de valor decimal según el código ASCII. 
// El cual corresponde a la siguiente tabla:

//   Si Cadena1 es       :     Entonces devuelve
// Igual que Cadena2     :             0
// Mayor que Cadena2     :           n > 0
// Menor que Cadena2     :           n < 0


/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <string.h> 

void clearBuffer();

/* _________________________________________
   Inicio main() */

int main()
{
	printf("\n_________________________________________START\n\n");
    
	char claveSecreta[]    = "1234";
	char claveUsuario[100] = "";
	int  intentosRestantes = 3;

	do {
		printf("Introduce la clave: ");
		scanf("%s", claveUsuario);

		if(strcmp(claveSecreta, claveUsuario) == 0)
		{
			printf("Has introducido la clave correcta, bienvenido al sistema. \n");	
			break;
		}
		else
		{
			intentosRestantes--;
			if(intentosRestantes == 0)
			{
				printf("Lo siento, te quedaste sin mas intentos");
				break;
			}
			printf("Clave erronea. %d intentos restantes\n", intentosRestantes);
		}

	} while (intentosRestantes > 0);



	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}