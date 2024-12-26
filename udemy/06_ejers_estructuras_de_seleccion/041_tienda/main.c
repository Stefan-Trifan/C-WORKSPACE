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

void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(){
	printf("\n______Este es un Simulador de Tienda o Cajero______\n\n");
    
	int opcion;
	float agregar = 0, retirar = 0, saldo = 0, salir = 0;

	do {
		printf(
		"\nSelecciona una Opcion:\n"
		"\n 1) Depositar Dinero"
		"\n 2) Retirar Dinero"
		"\n 3) Salir del Cajero"
		"\n\n Opcion: ");
		scanf("%i", &opcion);

		switch (opcion) {

			case 1: 
				printf("\nCuanto dinero quieres depositar: "); 
				scanf("%f", &agregar);
				saldo = saldo + agregar;
				printf("\nTu saldo es de: %.2f\n", saldo);
				break;

			case 2: 
				printf("\nCuanto dinero quieres retirar: "); 
				scanf("%f", &retirar);
				if(retirar > saldo){
					printf("\nNo puedes retirar tanto dinero.");
				} else {
					saldo = saldo - retirar;
				};
				printf("\nTu saldo es de: %.2f\n", saldo);;
				break;

			case 3:
				printf("\nGracias por utilizar el cajero. Hasta luego\n");
				salir = 1;
				break;

			default: 
				printf("\nGracias por utilizar el cajero. Hasta luego\n");
				salir = 1; 
				break;
		}
	} while (!salir);


	
	
	printf("\n____________________________________________________\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer(){
	while (getchar() != '\n');
}