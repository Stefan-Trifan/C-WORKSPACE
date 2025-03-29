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

void  menu        ();
float sumar       ();
float restar      ();
float multiplicar ();
float dividir     ();
void  clearBuffer ();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");

    menu();
    
	printf("\n_________________________________________EXIT\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void menu()
{
    int   opcion    = 0;
	float resultado = 0;

	do {
		printf(
			"Introduce el tipo de operacion: \n"
			"1. Sumar\n"
			"2. Restar\n"
			"3. Multiplicar\n"
			"4. Dividir\n"
            "5. Salir\n"
			"-> ");
		scanf("%d", &opcion);
		printf("\n");

        switch (opcion)
        {
            case 1: 
                resultado = sumar();
                break;
            case 2: 
                resultado = restar();
                break;
            case 3: 
                resultado = multiplicar();
                break;
            case 4: 
                resultado = dividir();
                break;
        }
        
        if(opcion != 5)
        {
            printf("El resultado es: %f\n\n", resultado);
        }

	} while (opcion != 5);

}

float sumar()
{
    float num1 = 0, num2 = 0;
    printf("Introduce el numero 1: ");
	scanf("%f", &num1);
	printf("Introduce el numero 2: ");
	scanf("%f", &num2);
	return num1 + num2;
}

float restar()
{
    float num1 = 0, num2 = 0;
    printf("Introduce el numero 1: ");
	scanf("%f", &num1);
	printf("Introduce el numero 2: ");
	scanf("%f", &num2);
	return num1 - num2;
}

float multiplicar()
{
    float num1 = 0, num2 = 0;
    printf("Introduce el numero 1: ");
	scanf("%f", &num1);
	printf("Introduce el numero 2: ");
	scanf("%f", &num2);
	return num1 * num2;
}

float dividir()
{
    float num1 = 0, num2 = 0;
    printf("Introduce el numero 1: ");
	scanf("%f", &num1);
	printf("Introduce el numero 2: ");
	scanf("%f", &num2);
	return num1 / num2;
}


void clearBuffer()
{
	while (getchar() != '\n');
}