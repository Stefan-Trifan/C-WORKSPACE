/*
	*   Autor
		Stefan Trifan

	*   Estado

	*   Enunciado
		./main + 1 2 3 4
		./main + 3.5 2.0 1.5 1.0
		./main + 1 2i 3 4i (significado)
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <stdlib.h>
#define RED "\033[1;31m"
#define RESET "\033[0m"
typedef struct complejos_t
{
	float parte_real;
	float parte_imag;
}complejos_t;
// Funciones del programa

// Funciones auxiliares
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");

	if(argc != 6)
	{
		printf(RED
			"ERROR: Tienes que introducir 6 argumentos\n"
			"USO  : ./main 1 2 3 4\n");
		printf("\n_________________________________________EXIT_FAILURE\n\n"RESET);
		return 0;
	}

	char *endptr2, *endptr3, *endptr4, *endptr5, signo;
	complejos_t complejo[2];

	// Asignamos los parametros a nuestras variables
	signo = *argv[1];

	complejo[0].parte_real = strtof(argv[2], &endptr2);
	complejo[0].parte_imag = strtof(argv[3], &endptr3);

	complejo[1].parte_real = strtof(argv[4], &endptr4);
	complejo[1].parte_imag = strtof(argv[5], &endptr5);

	// VERIFICACIONES
	// Comprobamos el signo
	if(signo != '+' && signo != '-' && signo != 'x' && signo != '/')
	{
		printf(RED
			"ERROR: \n"
			"Signos admitidos: \n"
			"+ : Sumar \n"
			"- : Restar \n"
			"x : Multiplicar \n"
			"/ : Divisor");
		printf("\n_________________________________________EXIT_FAILURE\n\n"RESET);
		return 0;
	}
	
	// Comprobamos los numeros
	if(*endptr2 != '\0' || *endptr3 != '\0' || *endptr4 != '\0' || *endptr5 != '\0')
	{
		printf(RED 
			"ERROR: Alguno de los argumentos que has introducido no es un numero\n"
			"USO  : ./main 1 2 3 4\n");
		printf("\n_________________________________________EXIT_FAILURE\n\n"RESET);
		return 0;
	}

	// Imprimimos los valores del usuario

	printf("Signo         : %c\n", signo);

	printf("Parte real z1 : %.2f\n", complejo[0].parte_real);
	printf("Parte imag z1 : %.2f\n", complejo[0].parte_imag);

	printf("Parte real z2 : %.2f\n", complejo[1].parte_real);
	printf("Parte imag z2 : %.2f\n", complejo[1].parte_imag);

	// Imprimimos los resultados

	if(signo == '+')
	{
		printf(
			"----------------------------\n"
			"Resultado     : %.2f + %.2fi\n", 
			complejo[0].parte_real + complejo[1].parte_real,
			complejo[0].parte_imag + complejo[1].parte_imag);
	}
	else if (signo == '-')
	{
		printf(
			"----------------------------\n"
			"Resultado     : %.2f + %.2fi\n", 
			complejo[0].parte_real - complejo[1].parte_real,
			complejo[0].parte_imag - complejo[1].parte_imag);
	}
	else if (signo == 'x')
	{
		// (a + bi) * (c + di) = (ac − bd) + (ad + bc)i
		// a = complejo[0].parte_real
		// b = complejo[0].parte_imag
		// c = complejo[1].parte_real
		// d = complejo[1].parte_imag
		printf(
			"----------------------------\n"
			"Resultado     : %.2f + %.2fi\n", 
			complejo[0].parte_real * complejo[1].parte_real - complejo[0].parte_imag * complejo[1].parte_imag,
			complejo[0].parte_real * complejo[1].parte_imag + complejo[0].parte_imag * complejo[1].parte_real);
	}
	else if (signo == '/')
	{
		// (a + bi) / (c + di) = (ac + bd) / (cc + dd) + (bc - ad) / (cc + dd)
		printf(
			"----------------------------\n"
			"Resultado     : %.2f + %.2fi\n", 
			(complejo[0].parte_real * complejo[1].parte_real + complejo[0].parte_imag * complejo[1].parte_imag)/
			(complejo[1].parte_real * complejo[1].parte_real + complejo[1].parte_imag * complejo[1].parte_imag),
			(complejo[0].parte_imag * complejo[1].parte_real - complejo[0].parte_real * complejo[1].parte_imag)/
			(complejo[1].parte_real * complejo[1].parte_real + complejo[1].parte_imag * complejo[1].parte_imag));
	}

	printf("\n_________________________________________EXIT\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa

// Funciones auxiliares
void clearBuffer()
{
	while (getchar() != '\n');
}