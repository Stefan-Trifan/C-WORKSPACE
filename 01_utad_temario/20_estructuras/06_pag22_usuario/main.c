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

#define MAX_USUARIOS 10
#define TAM_NOMBRE 11
#define TAM_APELLIDO 11
#define TAM_DNI 11

typedef struct usuarios_t
{
	char nombre[TAM_NOMBRE];
	char apellido[TAM_APELLIDO];
	char dni[TAM_DNI];
	int edad;
	float peso;
	int tel;
}usuarios_t;

// Funciones del programa
void introduceUsuario(struct usuarios_t* users, int *contUsuarios);
void imprimeUsuario(struct usuarios_t users[], int *contUsuarios);
// Funciones auxiliares
void pedirCadenaTexto(char texto[], int tam);
void pedirCadena(char texto[], int tam);
float pedirFloat();
int pedirEntero();
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n___________________________START\n\n");
    
	int opcion = 0, contUsuarios = 0;

    // struct usuarios_t users[MAX_USUARIOS];
	usuarios_t users[MAX_USUARIOS];

	do
	{
		// Menu
		printf(
			"\n********** MENu PRINCIPAL **********\n"
			"Por favor, introduce la opcion que deseas realizar \n"
			"1. Introducir usuario\n"
			"2. Imprimir usuario\n"
			"3. Salir\n");
		opcion = pedirEntero();

		switch (opcion)
		{
			case 1: 
				introduceUsuario(users, &contUsuarios);
				break;
			case 2: 
				imprimeUsuario(users, &contUsuarios);
				break;
			default: 
				break;
		}
	} 
	while (opcion != 3);
    
	printf("\n\033[1;32m___________________________EXIT_SUCCESS\033[0m\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa
void introduceUsuario(struct usuarios_t* users, int *contUsuarios)
{

	printf("Introduce el nombre del usuario: \n");
	pedirCadenaTexto((users + *contUsuarios)->nombre, TAM_NOMBRE);
	
	printf("Introduce el apellido del usuario: \n");
	pedirCadenaTexto((users + *contUsuarios)->apellido, TAM_APELLIDO);

	printf("Introduce la edad del usuario: \n");
	(users + *contUsuarios)->edad = pedirEntero();

	printf("Introduce el DNI del usuario: \n");
	pedirCadena((users + *contUsuarios)->dni, TAM_DNI);

	printf("Introduce el peso del usuario: \n");
	(users + *contUsuarios)->peso = pedirFloat();

	printf("Introduce el telefono del usuario: \n");
	(users + *contUsuarios)->tel = pedirEntero();

	(*contUsuarios)++;
	printf("\n\n\n");
}

void imprimeUsuario(struct usuarios_t users[], int *contUsuarios)
{
	for(int i = 0; i < *contUsuarios; i++)
	{
		printf("_________________________________________ \n\n");
		printf("USUARIO %d:\n", i + 1);
        printf("Nombre: %s\n", users[i].nombre);
		printf("Nombre: %s\n", users[i].apellido);
        printf("Edad: %d\n", users[i].edad);
        printf("DNI: %s\n", users[i].dni);
        printf("Peso: %.2f kg\n", users[i].peso);
        printf("Telefono: %d\n", users[i].tel);
		printf("_________________________________________ \n\n");
	}
	printf("\n\n\n");
}

// Funciones auxiliares
void pedirCadenaTexto(char texto[], int tam)
{	
    int i, esValido;
    char newChar;

    do
    {
        printf("(Max %d caracteres, solo letras y espacios)\n-> ", tam - 1);
        i = 0;
        esValido = 1;

        while ((newChar = getchar()) != '\n' && i < tam - 1)
        {
            if (!((newChar >= 'A' && newChar <= 'Z') || 
                  (newChar >= 'a' && newChar <= 'z') || 
                   newChar == ' '))  // Solo permite letras y espacios
                esValido = 0;

            texto[i++] = newChar;
        }
        texto[i] = '\0';  // Finalizar la cadena

        if (!esValido || i == 0)
            printf("\033[1;31mERROR: Solo se permiten letras y espacios. Intente de nuevo.\033[0m\n");

    } while (!esValido || i == 0);
}

void pedirCadena(char texto[], int tam)
{
	int esValido = 1, i = 0;
	char newChar;

	printf("(max %d caracteres):\n", tam - 1);
	printf("-> ");

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
float pedirFloat()
{
	float num = 0;
	int esValido = 1;
	printf("-> ");
	do
	{
		esValido = scanf("%f", &num);
		clearBuffer();
		if (esValido == 0)
		{
			printf(
				"\033[1;31mERROR: El tipo de dato introducido no es valido. "
				"Por favor, intentelo de nuevo. \n\033[0m" 
				"\033[1;31m-> \033[0m"
			);
			esValido = 0;
		}
	}
	while (esValido != 1);
	return num;
}
int pedirEntero()
{
	int num = 0, esValido = 1;
	printf("-> ");
	do
	{
		esValido = scanf("%d", &num);
		clearBuffer();
		if (esValido == 0)
		{
			printf(
				"\033[1;31mERROR: El tipo de dato introducido no es valido. "
				"Por favor, intentelo de nuevo. \n\033[0m" 
				"\033[1;31m-> \033[0m"
			);
			esValido = 0;
		}
	}
	while (esValido != 1);
	return num;
}
void clearBuffer()
{
	while (getchar() != '\n');
}