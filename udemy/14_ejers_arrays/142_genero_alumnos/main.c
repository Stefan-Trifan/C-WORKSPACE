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
		Escriba un programa en C que solicite al usuario ingresar el número total de estudiantes en un curso de Algoritmos. 
		Luego, el programa deberá pedir uno por uno el sexo de cada estudiante, permitiendo las opciones "hombre", "mujer" y cualquier otro valor como "indeterminado". 
		Finalmente, el programa debe mostrar cuántos estudiantes son hombres, cuántos son mujeres y cuántos tienen un sexo no especificado correctamente.
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#define PALABRAS 5
#define LETRAS 6
char pedirCadena();
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");
    
    char alumnos[PALABRAS][LETRAS] = {0};

	// Pedimos el genero de cada alumno
	for(int i = 0; i < PALABRAS; i++)
	{
		printf("Genero alumno[%d]: ", i);
		for(int j = 0; j < LETRAS; j++)
		{
			while(alumnos[i][j] =! '\n')
			{
				alumnos[i][j] = getchar();
				if(alumnos[i][j] =! '\n')
				{
					alumnos[i][j] == '\n';
					break;
				}
			}
		}
	}

    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

char pedirCadena()
{

}

void clearBuffer()
{
	while (getchar() != '\n');
}