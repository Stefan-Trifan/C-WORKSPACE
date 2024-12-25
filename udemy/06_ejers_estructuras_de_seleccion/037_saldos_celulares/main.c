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

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#define TARIFA1 "Premium"    // De 1000 a 1500
#define TARIFA2 "Intermedia" // De 500 a 999
#define TARIFA3 "Basica"     // De 100 a 499
 
void limpiarBuffer();

/* _________________________________________
   Inicio main() */

int main(){
	printf("\n_________________________________________START\n\n");

	float presupuesto = 0, plan = 0;
    
	do{
		printf("Cuanto estás dispuesto a pagar: ");
		scanf("%f", &presupuesto);

		if(presupuesto >= 1000 && presupuesto <= 1500){
			printf("Has elegido la tarifa %s", TARIFA1);
		}
		if(presupuesto >= 500 && presupuesto <= 999){
			printf("Has elegido la tarifa %s", TARIFA2);
		}
		if(presupuesto >= 100 && presupuesto <= 499){
			printf("Has elegido la tarifa %s", TARIFA3);
		}

		

	} while ( presupuesto < 100 || presupuesto > 1500);

    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void limpiarBuffer(){
	while (getchar() != '\n');
}