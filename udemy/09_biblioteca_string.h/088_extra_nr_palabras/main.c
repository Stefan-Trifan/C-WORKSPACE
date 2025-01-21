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
#include <string.h>

void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(){
	printf("\n_________________________________________START\n\n");
    
	FILE* archivo = fopen("Prueba.txt","r"); // Declaramos un apuntador a archivo
    int apariciones = 0; // Es el contador


    if (archivo == NULL)
	{
		printf("\nError al intentar acceder al archivo");
	}
    else
	{
        char TextoRecibido[1000];
        char palabraBuscada[] = "a"; // Se sustituye por las palabras que elegiste

        while (fscanf(archivo,"%s",TextoRecibido) != EOF)
		{
			if (strcmp(TextoRecibido,palabraBuscada) == 0)
			{
				apariciones++;
			}
            
    	}
    }

    fclose(archivo);
    printf("\nApariciones de la palabra: %d",apariciones);
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer(){
	while (getchar() != '\n');
}