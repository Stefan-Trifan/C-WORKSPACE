/*
	*	Autor
		Stefan Trifan

	*   Estado

	* 	Enunciado X
		LoremIpsum
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
struct direccion_t
{
	char calle[30];
	short numero;
	char colonia;
	int codigo_postal;
};
struct alumno_t
{
	int num_cuenta;
	char nombre[30];
	char apellido[30];
	float promedio;
	struct direccion_t direccion_alumno;
};
// Funciones del programa

// Funciones auxiliares
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");
    
    struct alumno_t alumno;

	// Leemos
	printf("Introduce el nombre: ");
	fgets(alumno.nombre, sizeof(alumno.nombre), stdin);
	int tam = strlen(alumno.nombre);
    if (tam > 0 && alumno.nombre[tam - 1] == '\n') {
        alumno.nombre[tam - 1] = '\0';
    }

	// Imprimimos
	printf("Nombre: %s\n", alumno.nombre);
    
	printf("\n_________________________________________END\n\n");
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