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

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>

void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n___________________________START\n\n");

	int num1     = 0,
	    num2     = 0,
	    numMayor = 0,
	    numMenor = 0,
	    resto    = 0,
	    m_c_d    = 0,
	    esEntero = 0;
    
	do {
		printf("Primer numero  : ");
		esEntero = scanf("%d", &num1);
		clearBuffer();
	} while (esEntero == 0);

	do {
		printf("Segundo numero : ");
		esEntero = scanf("%d", &num2);
		clearBuffer();
	} while (esEntero == 0);

	if(num1 == num2)
	{
		m_c_d = num1;; // Los numeros son iguales, m.c.d es cualquiera de los 2
	}
	else // (num1 != num2)
	{
		// Buscamos el mayor de los dos numeros
		if(num1 > num2)
		{
			numMayor = num1;
			numMenor = num2;
		}
		else if (num2 > num1)
		{
			numMayor = num2;
			numMenor = num1;

		}

		/* 
			Dividimos el mayor entre el menor
			Si la division no es exacta, dividimos el divisor entre el resto obtenido y continuamos de esta forma hasta obtener una division exacta.
			El m.c.d. es el ultimo divisor. 
		*/
		if(numMayor % numMenor == 0) // Division exacta
		{
			m_c_d = numMenor;
		}
		else // Division no exacta
		{
			while(numMayor % numMenor != 0)
			{
				resto    = numMayor % numMenor;
				numMayor = numMenor;
				numMenor = resto;
			}

			m_c_d = numMenor;
		}
	}

	printf("m.c.d es       : %d\n", m_c_d);
    
	printf("\n\033[1;32m___________________________EXIT_SUCCESS\033[0m\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}

/* _________________________________________
   Herramientas de depuracion */

// printf("DEBUG nombreVariable: %d\n", variable);