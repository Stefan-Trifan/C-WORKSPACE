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
#include <string.h>
struct direccion_t
{
	char calle[30];
	short numero;
};
struct alumno_t
{
	int promedio;
	char nombre[30];
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
	alumno.promedio = 10;
	strcpy(alumno.nombre, "Steve");
	strcpy(alumno.direccion_alumno.calle, "La calle Solana");
	alumno.direccion_alumno.numero = 23;

	printf("ANTES\n");
	printf("promedio: %d\n", alumno.promedio);
	printf("nombre: %s\n", alumno.nombre);
	printf("calle: %s\n", alumno.direccion_alumno.calle);
	printf("numero: %d\n", alumno.direccion_alumno.numero);
	printf("\n");

	struct alumno_t *palumno;
	palumno = &alumno;
	palumno->promedio = 4;
	strcpy(palumno->nombre, "Pepe");
	strcpy(palumno->nombre, "Pepe");
	palumno->direccion_alumno.numero = 5;

	printf("DESPUES\n");
	printf("promedio: %d\n", alumno.promedio);
	printf("nombre: %s\n", alumno.nombre);
	printf("calle: %s\n", alumno.direccion_alumno.calle);
	printf("numero: %d\n", alumno.direccion_alumno.numero);
	printf("\n");

	struct direccion_t *pdireccion;
	pdireccion = &alumno.direccion_alumno;
	pdireccion->numero = 66;

	printf("DESPUES\n");
	printf("promedio: %d\n", alumno.promedio);
	printf("nombre: %s\n", alumno.nombre);
	printf("calle: %s\n", alumno.direccion_alumno.calle);
	printf("numero: %d\n", alumno.direccion_alumno.numero);
    
	printf("\n\033[1;32m_________________________________________EXIT_SUCCESS\033[0m\n\n");
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