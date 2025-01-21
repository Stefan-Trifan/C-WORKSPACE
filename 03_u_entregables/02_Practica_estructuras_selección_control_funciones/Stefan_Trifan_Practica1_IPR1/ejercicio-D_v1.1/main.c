/*  
	*	Autor
		Stefan Trifan

	* 	Compilar
		mac     : comp (compilar)
				  run  (ejecutar)
				  brun (compilar y ejecutar)
		windows : gcc main.c -o main.exe
				: ./main.exe

	* 	Enunciado - Suma recursiva de los digitos impares
		Realiza un programa que utilice una funcion recursiva para sumar los digitos de posicion impar
		(contando como posicion 1 el digito menos significativo) de un numero entero.
		El programa debe funcionar tanto para numeros positivos como negativos.

		Se tiene que implementar la siguiente funcion:
			int sumaDigitosImpares(int num){
				Funcion que de manera recursiva calcula la suma
				Como condicion base si el numero es igual a 0 la suma es 0
				La llamada recursiva se debe hacer descartando los digitos pares
			}	

	*   Ejemplo de ejecucion
		
		Numero positivo
		Introduce un numero: 12345
		La suma es 9

		Numero negativo
		Introduce un numero: 12345
		La suma es 9
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <stdlib.h> // Nos permite trabajar con valor absoluto

int sumaDigitosImpares(int num);
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main()
{
	printf("\n_________________________________________START\n\n");

	int num = 0;    
	int resultadoSuma = 0;

	// Pedimos el numero al usuario
	printf("Introduce un numero: ");
	scanf("%i", &num);

	resultadoSuma = sumaDigitosImpares(num);

	printf("La suma es %i", resultadoSuma);
    
	printf("\n_________________________________________END\n\n");
	return 0;
}



/* _________________________________________
   Inicio definicion de funciones */

// Calculamos la suma de manera recursiva 
int sumaDigitosImpares(int num){
	

	// Nos aseguramos que el num esta siempre en positivo
	num = abs(num);

	if(num == 0){ // Si el numero es 0
		return 0;
	} 

	// Extraemos el ultimo digito
	int ultimoDigito = num % 10;

	if(ultimoDigito % 2 == 1){ // Si el ultimo digito es impar

		return ultimoDigito + sumaDigitosImpares(num / 10);

	} else { // La llamada recursiva se debe hacer descartando los digitos pares
		
		return sumaDigitosImpares(num / 10);

	}
	

}	



void clearBuffer()
{
	while (getchar() != '\n');
}

