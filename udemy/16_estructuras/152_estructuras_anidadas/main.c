/*
	*	Autor
		Stefan Trifan

	*   Estado

	* 	Enunciado
		LoremIpsum
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#define TAM 1
struct infoDireccion_t
{
	char direccion[5];
	char ciudad[5];
	char provincia[5];
};
struct empleados_t
{
	char nombre[5];
	struct infoDireccion_t dirEmpleado;
	int salario;
};
// Funciones del programa

// Funciones auxiliares
void pedirCadena(char *text, int tam);
int pedirEntero();
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");
    
    struct empleados_t empleado[10];

	for(int i = 0; i < TAM; i++)
	{
		printf("Introduce el nombre\n");
		pedirCadena(empleado[i].nombre, 5);

		printf("Introduce la direccion\n");
		pedirCadena(empleado[i].dirEmpleado.direccion, 5);

		printf("Introduce la ciudad\n");
		pedirCadena(empleado[i].dirEmpleado.ciudad, 5);

		printf("Introduce la provincia\n");
		pedirCadena(empleado[i].dirEmpleado.provincia, 5);

		printf("Introduce el salario\n-> ");
		empleado[i].salario = pedirEntero();

	}

	for(int i = 0; i < TAM; i++)
	{
		printf("El nombre es:    %s\n", empleado[i].nombre);
		printf("La direccion es: %s\n", empleado[i].dirEmpleado.direccion);
		printf("La ciudad es:    %s\n", empleado[i].dirEmpleado.ciudad);
		printf("La provincia es: %s\n", empleado[i].dirEmpleado.provincia);
		printf("El salario es:   %d\n", empleado[i].salario);
	}
    
	printf("\n_________________________________________EXIT\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa

// Funciones auxiliares
int pedirEntero()
{
	int num = 0, esValido = 0;
	do
	{
		esValido = scanf("%d", &num);
		clearBuffer();
		if (esValido == 0)
		{
			printf(
				"\033[1;31mERROR: El tipo de dato introducido no es valido.\n"
				"Por favor, intentelo de nuevo.\n"
				"-> \033[0m"
			);
			esValido = 0;
		}
	}
	while (esValido != 1);
	return num;
}
void pedirCadena(char texto[], int tam)
{
	int esValido = 1, i = 0;
	char newChar;

	printf("(Max. %d caracteres) -> ", tam - 1);

	do
	{
		esValido = 1;
		i = 0;
		// Leer la entrada hasta '\n' o hasta que se llene el array (dejando espacio para '\0')
		while (((newChar = getchar()) != '\n') && (i < tam - 1))
		{
			texto[i] = newChar;
			i++;
		}
		texto[i] = '\0'; // Finalizar la cadena

		if (i == tam - 1 && newChar != '\n')
		{
			printf("\033[1;31mERROR: Has superado el tamaño. Por favor, intentelo de nuevo. \n\033[0m"
				   "\033[1;31m-> \033[0m");
			clearBuffer();
			esValido = 0;
		}
	} while (!esValido);
}

void clearBuffer()
{
	while (getchar() != '\n');
}