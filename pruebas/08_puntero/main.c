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
	printf("\n_________________________________________START\n\n");

	char Nombre[3];
	Nombre[0] = 'A';
    Nombre[1] = 'n';
	Nombre[2] = 'a';
	printf("%s\n", Nombre);

	char Nombre2[6];
	Nombre2[0] = 'A';
	Nombre2[1] = 'n';
	Nombre2[2] = 'a';
	Nombre2[3] = 'b';
	Nombre2[4] = 'e';	
	Nombre2[5] = 'l';
	printf("%s\n", Nombre2);

	// char* pNombre;
	// *(pNombre ) = 'J';	
	// *(pNombre + 1) = 'o';
	// *(pNombre + 2) = 's';
	// *(pNombre + 3) = 'e';
	// *(pNombre + 4) = '\0';
	// *(pNombre + 5) = 'L';
	// *(pNombre + 6) = 'u';
	// *(pNombre + 7) = 'i';	
	// *(pNombre + 8) = 's';	

	printf("\n\033[1;32m_________________________________________EXIT_SUCCESS\033[0m\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}