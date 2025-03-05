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

#define TAM_STR 12

// Funciones del programa
typedef union tipo_union
{	
	int tiene_baul;
	int num_puertas;
}
tipo_union;

typedef struct tipo_estructura
{
	char tipo[TAM_STR];
	tipo_union descripcion;
}
tipo_estructura;

// Funciones auxiliares
void pedirCadena(char *text);
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");

	tipo_estructura vehiculo;
    
    printf("Ingresa el tipo de vehiculo (coche o motocicleta)\n-> ");
	pedirCadena(vehiculo.tipo);

	if(
        vehiculo.tipo[0] == 'c' &&
        vehiculo.tipo[1] == 'c' &&
        vehiculo.tipo[2] == 'c' &&
        vehiculo.tipo[3] == 'c' &&
        vehiculo.tipo[4] == 'c')
    {

    }
    else if
    (
        vehiculo.tipo[0]  == 'm' &&
        vehiculo.tipo[1]  == 'o' &&
        vehiculo.tipo[2]  == 't' &&
        vehiculo.tipo[3]  == 'o' &&
        vehiculo.tipo[4]  == 'c' &&
        vehiculo.tipo[5]  == 'i' &&
        vehiculo.tipo[6]  == 'c' &&
        vehiculo.tipo[7]  == 'l' &&
        vehiculo.tipo[8]  == 'e' &&
        vehiculo.tipo[9]  == 't' &&
        vehiculo.tipo[10] == 'a'
    )
    {
        
    }
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa

// Funciones auxiliares
void pedirCadena(char *text)
{
    int i = 0, esValido;
    char c;
    do
    {
        i = 0;
        esValido = 1;
        while (i < TAM_STR - 1)
        {
            c = getchar();

            // printf("DEBUG: i = %d, c = %c (%d)\n", i, c, c);
            if(c == '\n')
				break;
                
            text[i] = c;
            i++; 
        }
        text[i] = '\0'; 

        // printf("DEBUG SALIDA WHILE: i = %d, c = %c (%d)\n", i, c, c);
        
        if(i == TAM_STR - 1)
        {
            c = getchar();
            if(c != '\n')
            {
                printf(
                    "\033[1;33mHas introducido demasiados caracteres\n"
                    "Intentalo de nuevo\n"
                    "-> \033[0m");
                clearBuffer();
                esValido = 0;
            }
        }
    } 
    while (esValido != 1);
}

void clearBuffer()
{
	while (getchar() != '\n');
}