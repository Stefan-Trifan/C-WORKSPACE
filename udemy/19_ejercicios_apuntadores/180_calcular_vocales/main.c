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
#define TAM_STR 30
// Funciones del programa
void contarVocales(char *text);

// Funciones auxiliares
void pedirCadena(char *text);
void clearBuffer();

/* _________________________________________
       Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    char nombre[TAM_STR];
    char *pnombre = nombre;
	printf("Introduce tu nombre -> ");
    pedirCadena(pnombre);
	printf("tu nombre es %s\n", nombre);
	
    contarVocales(nombre);


    printf("\n_________________________________________END\n\n");
    return 0;
}

/* _________________________________________
       Inicio definicion de funciones */

// Funciones del programa
void contarVocales(char *text)
{
	int cont = 0, i = 0;
	while(*text != '\0')
	{
		switch (*text)
		{
			case 'a': cont++; break;
			case 'e': cont++; break;
			case 'i': cont++; break;
			case 'o': cont++; break;
			case 'u': cont++; break;
			case 'A': cont++; break;
			case 'E': cont++; break;
			case 'I': cont++; break;
			case 'O': cont++; break;
			case 'U': cont++; break;
			default: break;
		}
		text++;
	}
	printf("Hay %d vocales\n", cont);
}

// Funciones auxiliares
void pedirCadena(char *text)
{
    int esValido, i;
    char c;

    do
    {
        esValido = 1, i = 0;
        while (i < TAM_STR - 1)
        {
            c = getchar();

            if (c == '\n')
                break;

            text[i] = c;
            i++;
        }
        text[i] = '\0';

        if (i == TAM_STR - 1)
        {
            c = getchar();
            if (c != '\n')
            {
                printf("ERROR. Vuelve a intentarlo\n-> ");
                clearBuffer();
                esValido = 0;
            }
        }
    } while (esValido != 1);
}

void clearBuffer()
{
    while (getchar() != '\n');
}