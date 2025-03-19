/*
    *   Autor
        Stefan Trifan

    *  Estado

    *   Enunciado
        Lorem Ipsum
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <string.h>

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"
#define TAM_STRUCT 9
#define TAM_STRING 4

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
void imprimirZapatos(struct zapato_t *zapato, int contZapatos);
void venderZapato(struct zapato_t *zapato, int *contZapatos);
void imprimirMenu();

// Funciones auxiliares
int pedirEnteroPositivo();
int pedirOpcionMenu();
void pedirCadena(char *miembro, int tam);
float pedirFloatPositivo();
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[]) 
{
    printf("\n_________________________________________START\n\n");

    // Maximo 10 zapatos. Simulamos un stock inicial
    zapato_t mi_zapato[TAM_STRUCT];
    // = {
    //     {1, "Verde", "Bota", 43, 79, 20},
    //     {2, "Rojo", "Tacon", 42, 150, 10},
    //     {3, "Amarillo", "Zapato", 43, 200, 5}
    // }; 
    int opcion = 0, mi_cont_zapatos = 0;
    
    do
    {
        printf(
            "+---------------------------------+\n"
            "|              MENU               |\n"
            "|---------------------------------|\n"
            "|      Seleccione una opcion      |\n"
            "|                                 |\n"
            "| [1] Introducir Zapato           |\n"
            "| [2] Imprimir Zapatos por talla  |\n"
            "| [3] Vender zapato               |\n"
            "| [4] Salir                       |\n"
            "+---------------------------------+\n"
            "-> ");
        
        opcion = pedirOpcionMenu();
        
        switch (opcion)
        {
            case 1: 
                introducirZapato(mi_zapato, &mi_cont_zapatos);
                break;
            case 2: 
                imprimirZapatos(mi_zapato, mi_cont_zapatos);
                break;
            case 3: 
                venderZapato(mi_zapato, &mi_cont_zapatos);
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

// Funciones del programa
void introducirZapato(struct zapato_t *zapato, int *contZapatos)
{
    printf("\nMENU / Introducir Zapato \n");
    printf("Introduce los detalles de la nueva zapatilla \n\n");

    printf("1. Referencia \n-> ");
    (zapato + *contZapatos)->referencia = pedirEnteroPositivo();
    printf("DEBUG Has introducido referencia: %d\n\n", (zapato + *contZapatos)->referencia);

    printf("2. Color (max %d caracteres)\n-> ", TAM_STRING - 1);
    pedirCadena((zapato + *contZapatos)->color, TAM_STRING);
    printf("DEBUG Has introducido color: %s\n\n", (zapato + *contZapatos)->color);

    printf("3. Tipo (max %d caracteres)\n-> ", TAM_STRING - 1);
    pedirCadena((zapato + *contZapatos)->tipo, TAM_STRING - 1);
    printf("DEBUG Has introducido tipo: %s\n\n", (zapato + *contZapatos)->tipo);

    printf("4. Talla\n-> ");
    (zapato + *contZapatos)->talla = pedirEnteroPositivo();
    printf("DEBUG Has introducido talla: %d\n\n", (zapato + *contZapatos)->talla);

    printf("5. Precio\n-> ");
    (zapato + *contZapatos)->precio = pedirFloatPositivo();
    printf("DEBUG Has introducido precio: %.2f\n\n", (zapato + *contZapatos)->precio);

    printf("6. Stock\n-> ");
    (zapato + *contZapatos)->stock = pedirEnteroPositivo();
    printf("DEBUG Has introducido stock: %d\n\n", (zapato + *contZapatos)->stock);

    (*contZapatos)++;
    printf(GREEN
        "Nuevo zapato introducido \n"RESET
        "Numero de zapatos: %d\n", *contZapatos);
    printf("\n\n");
}

void imprimirZapatos(struct zapato_t *zapato, int contZapatos)
{
    int talla_seleccionada = 0, contadorCoincidencias = 0;
    printf("\nMENU / Imprimir Zapatos por talla \n");

    printf("Que talla deseas buscar?\n-> ");
    talla_seleccionada = pedirEnteroPositivo();

    for(int i = 0; i < contZapatos; i++)
    {
        if(zapato[i].talla == talla_seleccionada)
        {
            printf(GREEN
                "\n"
                "Ref    : %d\n"
                "Color  : %s\n"
                "Tipo   : %s\n"
                "Talla  : %d\n"
                "Precio : %.2f\n"
                "Stock  : %d\n"
                "\n"RESET, 
                zapato[i].referencia, 
                zapato[i].color, 
                zapato[i].tipo, 
                zapato[i].talla, 
                zapato[i].precio, 
                zapato[i].stock
            );
            contadorCoincidencias++;
        }
    }
    if(contadorCoincidencias == 0)
    {
        printf(YELLOW"\nNo se han zapato con la talla %d\n"RESET, talla_seleccionada);
    }
    else
    {
        printf(GREEN"Se han encontrado %d zapato(s) con talla %d\n"RESET, contadorCoincidencias, talla_seleccionada);
    }
    printf("\n\n");
}

void venderZapato(struct zapato_t *zapato, int *contZapatos)
{
    int refZapatoVendido, numZapatosVendidos = 0;
    printf("\nMENU / Vender zapato \n");
    for(int i = 0; i < *contZapatos; i++)
    {
        printf(GREEN
            "\n"
            "Ref    : %d\n"
            "Color  : %s\n"
            "Tipo   : %s\n"
            "Talla  : %d\n"
            "Precio : %.2f\n"
            "Stock  : %d\n"
            "\n"RESET, 
            zapato[i].referencia, 
            zapato[i].color, 
            zapato[i].tipo, 
            zapato[i].talla, 
            zapato[i].precio, 
            zapato[i].stock
        );
    }

    printf("Selecciona la referencia del zapato que desea vender\n-> ");
    refZapatoVendido = pedirEnteroPositivo();

    for(int i = 0; i < *contZapatos; i++)
    {
        if((zapato + i)->referencia == refZapatoVendido && (zapato + i)->stock > 0)
        {
            (zapato + i)->stock--;
            numZapatosVendidos++;
        }
    }

    if(numZapatosVendidos == 0)
    {
        printf("No se han encontrado zapatos\n");
    }

    printf("\n\n");
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
                "\033[1;31mERROR: El tipo de dato introducido no es valido.\n"
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
        {
            c = getchar();
        }
        // printf("DEBUG SALIDA WHILE: i = %d, c = %c (%d)\n", i, c, c);
        
        if(i == tam - 1 && c != '\n')
        {
            printf(YELLOW
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
float pedirFloatPositivo()
{
    float num = 0;
    int esValido = 0;
    do
    {
        esValido = scanf("%f", &num);
        clearBuffer();
        if(esValido != 1)
        {
            printf(
                "\033[1;31mERROR: El tipo de dato introducido no es valido.\n"
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
void clearBuffer() {
    while (getchar() != '\n');
}