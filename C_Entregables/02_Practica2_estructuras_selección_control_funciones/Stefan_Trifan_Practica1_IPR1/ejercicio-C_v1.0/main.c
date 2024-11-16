/*
	*	Autor
		Stefan Trifan

	* 	Compilar
		mac     : gcc main.c -o main
		windows : gcc main.c -o main.exe
				: ./main.exe

	* 	Enunciado - Calculadora de Potencia con Validación de Exponente
		El objetivo de este ejercicio es crear un programa que calcule la potencia de un número entero elevado a un exponente entero positivo. 
		El programa debe solicitar al usuario un número base y un exponente, 
		y mostrar el resultado solo si el exponente es positivo.
		
		Normas:
			1. La función calcular_potencia debe realizar la validación del exponente para asegurarse de que sea positivo.
			2. Si el exponente es positivo, calcular_potencia realiza el cálculo de la potencia y retornar 1 para indicar que la operación fue exitosa. 
				El resultado debe almacenarse en el puntero *resultado.
			3. Si el exponente no es positivo, calcular_potencia debe retornar 0.
			4. La función principal deberá mostrar el resultado o un mensaje de error en función del valor retornado por calcular_potencia.

		Condiciones:
			1. Si el cálculo se realiza correctamente, el programa debe mostrar el resultado de la potencia.
			2. Si el exponente es menor o igual a 0, el programa debe mostrar un mensaje de error: "Error: el exponente debe ser positivo”.

		Se tiene que implementar la siguiente función:
			int calcular_potencia(int base, int exponente, int *resultado){
				1. Calcula la potencia de la base elevada al exponente usando un bucle y asigna el resultado a la variable resultado.
				2. Valida si el exponente es positivo. Devuelve un 1 si el cálculo se realiza correctamente o un 0 si el exponente no es positivo
			}
*/
/* 
	# Ejemplo de ejecución

	Caso correcto:
		Ingrese la base: 3
		Ingrese el exponente: 4
		Resultado: 81

	Caso incorrecto:
		Ingrese la base: 3
		Ingrese el exponente: -2
		Error: el exponente debe debe ser positivo
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>

int calcular_potencia(int base, int exponente, int *resultado);

void limpiarBuffer();

/* _________________________________________
   Inicio main() */

int main(){
	printf("\n_________________________________________START\n\n");

	// Declaración de variables
	int      base = 0;
	int exponente = 0;
	int resultado = 0;
	int operacionCorrecta = 0;

	// Pedimos la base y el exponente al usuario
	printf("Ingrese la base:      ");
	scanf("%d", &base);
	printf("Ingrese el exponente: ");
	scanf("%d", &exponente);
    
	// Calculamos la potencia
	resultado = base;
	operacionCorrecta = calcular_potencia(base, exponente, &resultado);

	if(operacionCorrecta){
		printf("Resultado:            %i\n", resultado);
	} else {
		printf("Error: el exponente debe ser positivo\n");
	}

	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definición de funciones */

// Calcula la potencia de la base elevada al exponente usando un bucle y asigna el resultado a la variable resultado.
int calcular_potencia(int base, int exponente, int *resultado){
	// Valida si el exponente es positivo. Devuelve un 1 si el cálculo se realiza correctamente o un 0 si el exponente no es positivo
	if(exponente >= 0){
		for(; exponente > 1; exponente--){
			*resultado = *resultado * base;
		}
	} else {
		return 0;
	}

	return 1;
}
   
void limpiarBuffer(){
	while (getchar() != '\n');
}