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
#define TAM_STRING 5
typedef struct zapato_t
{
    int   referencia;
    char  color[TAM_STRING];
    char  tipo[TAM_STRING];
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
int pedirOpcionMenu();
void pedirCadena(char *miembro, int tam);
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[]) 
{
    printf("\n_________________________________________START\n\n");

    zapato_t zapato[9]; // Maximo 10 zapatos
    int opcion = 0, contZapatos = 0;
    
    do
    {
        printf(
            // "+---------------------------------+\n"
            "|              MENÚ               |\n"
            // "|---------------------------------|\n"
            // "|      Seleccione una opcion      |\n"
            // "|                                 |\n"
            "| [1] Introducir Zapato           |\n"
            "| [2] Imprimir Zapatos por talla  |\n"
            "| [3] Vender zapato               |\n"
            "| [4] Salir                       |\n"
            // "+---------------------------------+\n"
            "-> ");
        
        opcion = pedirOpcionMenu();
        
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
                printf("Gracias por utilizar el programa! \n");
                break;
        }
        
    } 
    while (opcion != 4);

    printf("\n_________________________________________END\n\n");
    return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// typedef struct zapato_t
// {
//     int   referencia;
//     char  color[TAM_STRING];
//     char  tipo[TAM_STRING];
//     int   talla;
//     float precio;
//     int   stock;
// }zapato_t;

// Funciones del programa
void introducirZapato(struct zapato_t *zapato, int *contZapatos)
{
    printf("\nIntroduce los detalles de la nueva zapatilla \n\n");

    // todo descomentar
 /*    printf("1. Referencia\n-> ");
    zapato->referencia = pedirEnteroPositivo();
    printf("DEBUG Has introducido referencia: %d\n", zapato->referencia); */

    printf("2. Color (máx %d caracteres)\n-> ", TAM_STRING - 1);
    pedirCadena(zapato->color, TAM_STRING);
    printf("DEBUG Has introducido color: %s\n", zapato->color);

    printf("\n\n\n\n\n\n");
    // todo descomentar
/*     printf("3. Tipo\n-> ");
    printf("\n");

    printf("4. Talla\n-> ");
    printf("\n");

    printf("5. Precio\n-> ");
    printf("\n");

    printf("6. Stock\n-> ");
    printf("\n");

    (*contZapatos)++;
    printf(GREEN_BOLD
        "Nuevo zapato introducido \n"RESET
        "Numero de zapatos: %d\n"); */
    printf("\n");
}

void imprimirZapato(struct zapato_t zapato)
{

}

void venderZapato(struct zapato_t *zapato, int *contZapatos)
{

}


/**
 * 
 * rojo\n
 * 
 */

// Funciones auxiliares
void pedirCadena(char *miembro, int tam)
{
    int i = 0, esValido = 0;
    char c;
    do
    {
        i = 0;
        while (i < tam - 1)
        {
            c = getchar();
            
            // printf("DEBUG: i = %d, c = %c (%d)\n", i, c, c);
            if(c == '\n')
                break;

            miembro[i] = c;
            i++; 
        }
        miembro[i] = '\0'; 

        if(i == tam - 1)
            c = getchar();
        // printf("DEBUG SALIDA WHILE: i = %d, c = %c (%d)\n", i, c, c);
        
        if(i == tam - 1 && c != '\n')
        {
            printf(YELLOW_BOLD
                "Has introducido demasiados caracteres\n"
                "Intentalo de nuevo\n"
                "-> "RESET);
            clearBuffer();
            esValido = 0;
        }
        else
            esValido = 1;
    } 
    while (esValido != 1);
}



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
                "\033[1;31mERROR: Selecciona un una opcion el 1 al 4\n"
                "-> \033[0m"
            );
            esValido = 0;
        }
    } 
    while (esValido != 1);
    return num;
}
int pedirOpcionMenu()
{
    int num = 0, esValido = 0;
    do
    {
        num = pedirEnteroPositivo();
        if((num < 1 || num > 4))
        {
            printf(
                "\033[1;31mERROR: Selecciona un una opcion el 1 al 4\n"
                "-> \033[0m"
            );
            esValido = 0;
        }
        else
            esValido = 1;
    } 
    while (esValido != 1);
    return num;
}
// void pedirCadena(char *miembro, int tam)
// {
//     fgets(miembro, tam, stdin);
//     miembro[strcspn(miembro, "\n")] = '\0'; // Eliminar el salto de línea
// }
void clearBuffer() {
    while (getchar() != '\n');
}