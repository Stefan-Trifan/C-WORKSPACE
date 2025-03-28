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

// Plantillas testing
// ./main OP1=5 OP2=7 OPE=suma
// ./main OP1=5 OP2=7 OPE=resta
// ./main OP1=5 OP2=7 OPE=multiplica

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <stdlib.h>

void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[]){
	printf("\n_________________________________________START\n\n");

	long int op1 = 0, op2 = 0; 
	char *endptr; 
	char operacion[20]; 
	int encontrado_op1 = 0, encontrado_op2 = 0, encontrado_ope = 0; 

	// Verifica que se pasen exactamente 4 argumentos (incluyendo el nombre del programa)
	if (argc != 4) 
	{
		printf("Uso incorrecto. Ejemplo: ./main OP1=5 OP2=7 OPE=suma\n");
		return 1;
	}
	
	// Itera sobre los argumentos para encontrar OP1, OP2 y OPE
	for (int i = 1; i < argc; i++) 
	{
		if (argv[i][0] == 'O' && argv[i][1] == 'P' && argv[i][2] == '1' && argv[i][3] == '=') 
		{
			op1 = strtol(argv[i] + 4, &endptr, 10); // Convierte OP1 a entero
			encontrado_op1 = 1;
		}
		else if (argv[i][0] == 'O' && argv[i][1] == 'P' && argv[i][2] == '2' && argv[i][3] == '=') 
		{
			op2 = strtol(argv[i] + 4, &endptr, 10); 
			printf("DEBUG : %s\n", argv[i] + 4);// Convierte OP2 a entero
			encontrado_op2 = 1;
		}
		else if (argv[i][0] == 'O' && argv[i][1] == 'P' && argv[i][2] == 'E' && argv[i][3] == '=') 
		{
			int j = 4, k = 0;
			while (argv[i][j] != '\0' && k < 19) 
			{
				operacion[k++] = argv[i][j++]; // Copia la operacion a la cadena operacion
			}
			operacion[k] = '\0'; // Termina la cadena con un caracter nulo
			encontrado_ope = 1;
		}
	}

	// Verifica que se hayan encontrado todos los parametros necesarios
	if (!encontrado_op1 || !encontrado_op2 || !encontrado_ope) 
	{
		printf(
			"\033[1;31mERROR: Error en los parametros. Uso correcto: ./main OP1=5 OP2=7 OPE=suma\n\n\n\033[0m"
		);
		return 1;
	}
	
	// Realiza la operacion correspondiente segun el valor de operacion
	if (
		operacion[0] == 's' &&
		operacion[1] == 'u' &&
		operacion[2] == 'm' &&
		operacion[3] == 'a') 
	{
		printf("Resultado: %ld\n", op1 + op2); // Suma
	}
	else if (
		operacion[0] == 'r' &&
		operacion[1] == 'e' &&
		operacion[2] == 's' &&
		operacion[3] == 't' &&
		operacion[4] == 'a') 
	{
		printf("Resultado: %ld\n", op1 - op2); // Resta
	}
	else if (
		operacion[0]  == 'm' &&
		operacion[1]  == 'u' &&
		operacion[2]  == 'l' &&
		operacion[3]  == 't' &&
		operacion[4]  == 'i' &&
		operacion[5]  == 'p' &&
		operacion[6]  == 'l' &&
		operacion[7]  == 'i' &&
		operacion[8]  == 'c' &&
		operacion[9]  == 'a')
	{
        printf("Resultado: %ld\n", op1 * op2);
    }
	else 
	{
        printf(
			"\033[1;31mERROR: Error en los parametros."
			"Uso correcto: ./calculadora OP1=5 OP2=7 OPE=suma\n\n\n\033[0m"
		);
        return 1;
    }

	printf("\n\033[1;32m_________________________________________EXIT_SUCCESS\033[0m\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer(){
	while (getchar() != '\n');
}