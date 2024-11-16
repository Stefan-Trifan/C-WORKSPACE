/*  
	*	Autor
		Stefan Trifan

	* 	Compilar
		mac     : comp
				  run
		windows : gcc main.c -o main.exe
				: ./main.exe

	* 	Enunciado - Suma recursiva de los dígitos impares
		Realiza un programa que utilice una función recursiva para sumar los dígitos de posición impar
		(contando como posición 1 el dígito menos significativo) de un número entero.
		El programa debe funcionar tanto para números positivos como negativos.

		Se tiene que implementar la siguiente función:
			int sumaDigitosImpares(int num){
				Función que de manera recursiva calcula la suma
				Como condición base si el número es igual a 0 la suma es 0
				La llamada recursiva se debe hacer descartando los dígitos pares
			}	

	*   Ejemplo de ejecución
		
		Número positivo
		Introduce un numero: 12345
		La suma es 9

		Número negativo
		Introduce un numero: 12345
		La suma es 9
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <stdlib.h> // Nos permite trabajar con valor absoluto

int sumaDigitosImpares(int num);
void limpiarBuffer();

/* _________________________________________
   Inicio main() */

int main(){
	printf("\n_________________________________________START\n\n");

	int num = 0;    
	int resultadoSuma = 0;

	// Pedimos el número al usuario
	printf("Introduce un numero: ");
	scanf("%i", &num);

	resultadoSuma = sumaDigitosImpares(num);

	printf("La suma es %i", resultadoSuma);
    
	printf("\n_________________________________________END\n\n");
	return 0;
}



/* _________________________________________
   Inicio definición de funciones */

// Calculamos la suma de manera recursiva 
int sumaDigitosImpares(int num){
	
	int resultadoSuma;

	// Nos aseguramos que el num está siempre en positivo
	num = abs(num);
	printf("---DEBUG: El numero es: %i\n", num);

	if(num == 0){ // Si el numero es 0
		return resultadoSuma;
	} 

	// Extraemos el ultimo digito
	int ultimoDigito = num % 10;

	if(ultimoDigito % 2 == 1){ // Si el ultimo digito es impar

		resultadoSuma += ultimoDigito; // Sumamos ultimo digito
		sumaDigitosImpares(num / 10);

	}
	// La llamada recursiva se debe hacer descartando los dígitos pares
	if(ultimoDigito % 2 == 0){
		
		sumaDigitosImpares(num / 10);

	}

	return resultadoSuma;
}	



void limpiarBuffer(){
	while (getchar() != '\n');
}

