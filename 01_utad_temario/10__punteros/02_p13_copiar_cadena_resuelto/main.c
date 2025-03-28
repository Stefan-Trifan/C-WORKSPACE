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
#define MAX_SIZE 20
void pedirCadena(char texto[], int tam);
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    char cadena1[MAX_SIZE], cadena2[MAX_SIZE];
    char *pcadena1 = cadena1;  
    char *pcadena2 = cadena2; 
    int  i         = 0;

    // Pedimos la cadena 
    pedirCadena(pcadena1, MAX_SIZE);

   // Copiamos cadena1 a cadena2
    for(int i = 0; i <= MAX_SIZE - 1; i++)
    {
        *(pcadena2 + i) = *(pcadena1 + i);
    }
	
    printf("cadena1: %s\n", cadena1);
    printf("cadena2: %s\n", cadena2);

    printf("\n\033[1;32m_________________________________________EXIT_SUCCESS\033[0m\n\n");
    return 0;
}

/* _________________________________________
   Inicio definicion de funciones */


void pedirCadena(char texto[], int tam)
{
    int esValido = 1, i = 0;
    char newChar;

    printf("Introduce la cadena (maximo %d caracteres):\n", tam - 1);
    printf("-> ");

    do
    {
        esValido = 1;
        i = 0;
       
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
