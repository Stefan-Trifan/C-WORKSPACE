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

	char nombre[100];      // Para almacenar el nombre
	char apellidos[100];   // Para almacenar los apellidos
	int coma_encontrada = 0; // Bandera para detectar la coma
	int index_nombre = 0, index_apellido = 0; // indices para construir cadenas	
    
	// Verificar que al menos hay dos argumentos (apellido y nombre)
	if (argc < 2) {
		printf("Uso: %s <primer apellido> <segundo apellido>, <nombre>\n", argv[0]);
		return 1; // Codigo de error
	}

	// Recorrer los argumentos desde el segundo (argv[1] en adelante)
	for (int i = 1; i < argc; i++) {
		// Recorrer cada caracter del argumento actual
		for (int j = 0; argv[i][j] != '\0'; j++) {
			if (argv[i][j] == ',') {
				coma_encontrada = 1; // Encontramos la coma
				continue; // Saltamos la coma sin copiarla
			}

			if (coma_encontrada) {
				// Copiar caracteres al nombre
				nombre[index_nombre++] = argv[i][j];
			} else {
				// Copiar caracteres al apellido
				apellidos[index_apellido++] = argv[i][j];
			}
		}
		
		// Agregar un espacio entre palabras, excepto despues de la ultima
		if (i < argc - 1) {
			if (coma_encontrada) {
				nombre[index_nombre++] = ' ';
			} else {
				apellidos[index_apellido++] = ' ';
			}
		}
	}

	// Agregar terminador de cadena
	nombre[index_nombre] = '\0';
	apellidos[index_apellido] = '\0';

	// Mostrar el resultado formateado
	printf("%s %s\n", nombre, apellidos);
    
	printf("\n\033[1;32m_________________________________________EXIT_SUCCESS\033[0m\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}