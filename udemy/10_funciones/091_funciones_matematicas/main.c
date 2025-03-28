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

	* 	Enunciado
		LoremIpsum
*/


/*      
	Funciones Matematicas:
		ceil(x)   -> Redondea al entero mayor mas cercano 
		floor(x)  -> Redondea al entero menor mas cercano
		fabs(x)   -> Devuelve el valor absoluto de x
		sqrt(x)   -> Saca la raiz cuadrada de x
		fmod(x,y) -> Calcula el resto de la division de x/y
		pow(x,y)  -> Calcula x elevado a la potencia y 
 */

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <math.h>

void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");

	// ceil(x)

	float numMayorRedondeado = 0;
    printf("Escribe un numero decimal para redondear hacia arriba: ");
	scanf("%f", &numMayorRedondeado);
	printf("Resultado: %.0f\n", ceil(numMayorRedondeado));

	// floor(x)

	float numMenorRedondeado = 0;
	printf("Escribe un numero decimal para redondear hacia abajo: ");
	scanf("%f", &numMenorRedondeado);
	printf("Resultado: %.0f\n", floor(numMenorRedondeado));

	// fabs(x)

	float numValorAbsoluto = 0;
	printf("Introduce un numero negativo para sacar el valor absoluto: ");
	scanf("%f", &numValorAbsoluto);
	printf("Resultado: %.0f\n", fabs(numValorAbsoluto));

	// sqrt(x)

	float numRaizCuadrada = 0;
	printf("Introduce un numero para calcular la raiz cuadrada: ");
	scanf("%f", &numRaizCuadrada);
	printf("Resultado: %f\n", sqrt(numRaizCuadrada));

	// fmod(x,y)

	float numNumerador   = 0;
	float numDenominador = 0;
	printf("Introduce un numerador: ");
	scanf("%f", &numNumerador);
	printf("Introduce un denominador para calcular el resto: ");
	scanf("%f", &numDenominador);
	printf("Resultado: %f\n", fmod(numNumerador, numDenominador));

	// pow(x,y)

	float numBase = 0;
	float numExponente = 0;
	printf("Introduce una base: ");
	scanf("%f", &numBase);
	printf("Introduce un exponente: ");
	scanf("%f", &numExponente);
	printf("Resultado: %f\n", pow(numBase, numExponente));
    
	printf("\n\033[1;32m_________________________________________EXIT_SUCCESS\033[0m\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}