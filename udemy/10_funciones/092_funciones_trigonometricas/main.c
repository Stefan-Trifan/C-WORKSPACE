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
		LoremIpsumDummyText
*/

/*
    Funciones Trigonometricas

	(Si requiere la libreria math.h)

	acos(x) -> Calcula el Arco Coseno de x
	asin(x) -> Calcula el Arco Seno de x
	atan(x) -> Calcula el Arco Tangente de x
	cos(x) -> Calcula el Coseno de x
	sin(x) -> Calcula el Seno de x
	tan(x) -> Calcula la Tangente de x
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <math.h>

void funcionTrigonometrica();
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main()
{
	printf("\n_________________________________________START\n\n");
    
    funcionTrigonometrica();
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void funcionTrigonometrica(){

	float x, cambio = 0;

	printf("Escribe un numero: ");
	scanf("%f", &x);

	cambio = asin(x);
	printf("El resultado es %f", cambio);

}

void clearBuffer()
{
	while (getchar() != '\n');
}