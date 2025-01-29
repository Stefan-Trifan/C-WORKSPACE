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
#define MAX_SIZE 20
void leeLinea(char texto[], int tam);
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main()
{
    printf("\n_________________________________________START\n\n");

    char text1[MAX_SIZE], text2[MAX_SIZE];
    char *str1 = text1;  // cadena origen
    char *str2 = text2;  // cadena destino
    int  i     = 0;

    // Entrada de la cadena
    printf("Introduce la cadena:\n");
    leeLinea(str1, MAX_SIZE);

    /* Copy text1 to text2 character by character */
    while (*(str1 + i) != '\0')
    {
        *(str2 + i) = *(str1 + i);
        i++;
    }
	
    printf("Cadena origen  = %s\n", text1);
    printf("Cadena destino = %s\n", text2);

    printf("\n_________________________________________END\n\n");
    return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void leeLinea(char texto[], int tam)
{
    char newChar;
    int i = 0;

    while (((newChar = getchar()) != '\n') && (i < tam))
    {
        texto[i] = newChar; // cada caracter que ha leido se asigna a las
                            // posiciones de la cadena
        i++;
        if (i == tam)
        {
            printf("Has superado el tamanio\nVuelve a introducir la cadena\n");
            clearBuffer(); // limpia Buffer
            i = 0;
        }
    }
    texto[i] = '\0'; // Con esto lo dejamos con un \0 al final
}

void clearBuffer()
{
    while (getchar() != '\n');
}