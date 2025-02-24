/*
    *  Autor
        Stefan Trifan

    *  Estado

    *  Enunciado X
        Lorem Ipsum
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <string.h>
#define RED_BOLD "\033[1;31m"
#define GREEN_BOLD "\033[1;32m"
#define YELLOW_BOLD "\033[1;33m"
#define RESET "\033[0m"
typedef struct zapato_t
{
    int   referencia;
    char  color[50];
    char  tipo[50];
    int   talla;
    float precio;
    int   stock;
}zapato_t;
// Funciones del programa
void introducirZapato(struct zapato_t *zapato, int *contZapatos);
void imprimirZapato(struct zapato_t zapato);
void venderZapato(struct zapato_t *zapato, int *contZapatos);
void imprimirMenu();
// Funciones auxiliares
int pedirEnteroPositivo();
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[]) 
{
    printf("\n_________________________________________START\n\n");

    zapato_t zapato[9];
    int opcion = 0, contZapatos = 0;
    
    do
    {
        printf(
            "+---------------------------------+\n"
            "|              MENÚ               |\n"
            "|---------------------------------|\n"
            "| [1] Introducir Zapato           |\n"
            "| [2] Imprimir Zapatos por talla  |\n"
            "| [3] Vender zapato               |\n"
            "| [4] Salir                       |\n"
            "+---------------------------------+\n"
            "-> ");
        
        opcion = pedirEnteroPositivo();
        
        switch (opcion)
        {
            case 1: 
                introducirZapato(zapato, &contZapatos);
                break;
            case 2: 
                imprimirZapato(zapato[contZapatos]);
                break;
            case 3: 
                venderZapato(zapato, &contZapatos);
                break;
            case 4: 
                printf("Gracias por utilizar el programa! \n");;
                break;
        }
        
    } 
    while (opcion != 4);

    printf("\n_________________________________________END\n\n");
    return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa
void introducirZapato(struct zapato_t *zapato, int *contZapatos)
{

}

void imprimirZapato(struct zapato_t zapato)
{

}

void venderZapato(struct zapato_t *zapato, int *contZapatos)
{

}

// Funciones auxiliares
int pedirEnteroPositivo()
{
    int num = 0, esValido = 0;
    do
    {
        esValido = scanf("%d", &num);
        clearBuffer();
        if(esValido != 1)
        {
            printf(
                "\033[1;31mERROR: El tipo de dato introducido no es válido.\n"
                "-> \033[0m"
            );
        }
        if(num < 0 && esValido == 1)
        {
            printf(
                "\033[1;31mERROR: El numero debe ser positivo\n"
                "-> \033[0m"
            );
            esValido = 0;
        }
    } 
    while (esValido != 1);
    return num;
}

void clearBuffer() {
    while (getchar() != '\n');
}