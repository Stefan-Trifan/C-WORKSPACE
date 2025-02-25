/*
    *   Autor
        Stefan Trifan

    *   Estado
        Done

    *   Enunciado 1
        Contador de caracteres

    *   Testing
        ./main a B c
        ./main 1 b c
        ./main 1 b palabra
        ./main 1 [ !
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>

#define TAM 51
#define RED_BOLD "\033[1;31m"
#define GREEN_BOLD "\033[1;32m"
#define YELLOW_BOLD "\033[1;33m"
#define RESET "\033[0m"

// Funciones del programa
int leerCadena(char* cadena, int tam);
int cuentaCaracter(char* cadena, char caracter, int numCaracteres);

// Funciones auxiliares
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    // Comprobamos si el usuario introduce 4 argumentos
    if(argc != 4)
    {
        printf(RED_BOLD
            "ERROR: Debes introducir 4 argumentos\n"
            "USO  : ./main a b c"
            "\n_________________________________________FAIL\n\n"RESET);
            return 1;
    }
        
    // Declaracion de variables
    char c1, c2, c3, texto[TAM];
    int numCaracteresTexto, cont_c1, cont_c2, cont_c3;

    // Asignamos los valores de argv a nuestras variables
    c1 = argv[1][0];
    c2 = argv[2][0];
    c3 = argv[3][0];

    // Comprobamos que los caracteres introducidos por el usuario son validos
    // Comprobar si los argumentos realmente son letras
    if(
        ((c1 < 'A' || c1 > 'Z') && (c1 < 'a' || c1 > 'z')) || 
        ((c2 < 'A' || c2 > 'Z') && (c2 < 'a' || c2 > 'z')) || 
        ((c3 < 'A' || c3 > 'Z') && (c3 < 'a' || c3 > 'z')))
    {
        printf(RED_BOLD
            "ERROR: Los argumentos deben ser letras\n"
            "USO  : ./main a b c"
            "\n_________________________________________FAIL\n\n"RESET);
            return 1;
    }
    // Comprobar si los argumentos son distintos entre ellos
    else if((c1 == c2) || (c1 == c3) || (c2 == c3))
    {
        printf(RED_BOLD
            "ERROR: Los argumentos deben ser distintos\n"
            "USO  : ./main a b c"
            "\n_________________________________________FAIL\n\n"RESET);
            return 1;
    }
    // Comprobar si los argumentos son de una sola letra
    else if((argv[1][1] != '\0') || (argv[2][1] != '\0') || (argv[3][1] != '\0'))
    {
        printf(RED_BOLD
            "ERROR: Los argumentos deben ocupar un solo caracter\n"
            "USO  : ./main a b c"
            "\n_________________________________________FAIL\n\n"RESET);
            return 1;
    }

    // Pedimos el texto al usuario
    numCaracteresTexto = leerCadena(texto, TAM);
    printf("\nTu texto de %d caracteres es: \n%s\n\n", numCaracteresTexto, texto);

    // Contamos las veces que se repite cada una de las letras
    cont_c1 = cuentaCaracter(texto, c1, numCaracteresTexto);
    cont_c2 = cuentaCaracter(texto, c2, numCaracteresTexto);
    cont_c3 = cuentaCaracter(texto, c3, numCaracteresTexto);

    // Imprimimos los resultados
    printf(
        "El caracter %c se repite %d veces\n"
        "El caracter %c se repite %d veces\n"
        "El caracter %c se repite %d veces\n",
        c1, cont_c1, 
        c2, cont_c2, 
        c3, cont_c3);

    printf("\n_________________________________________END\n\n");
    return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa
/**
 * Función que lee del buffer de entrada y salida una cadena de
 * como máximo tam caracteres y devuelve el numero de caracteres
 * 
 * 
 * @param[out] cadena: Puntero donde se almacena el nombre del usuario 
 * @param[in] tam: Maximo de caracteres que puede tener la cadena
 * @return Numero de caracteres introducidos por el usuario
 */
int leerCadena(char* cadena, int tam)
{
    int i = 0, esValido = 1;
    char c;
    printf("Introduce el texto (max. %d caracteres)\n-> ", TAM - 1);
    do
    {
        i = 0;
        while(i < TAM - 1)
        {
            c = getchar();
    
            if(c == '\n')
            {
                break;
            }
    
            cadena[i] = c;
            i++;
        }
        cadena[i] = '\0';
    
        if(i == TAM - 1)
        {
            c = getchar();
            if(c != '\n')
            {
                printf(YELLOW_BOLD
                    "ALERTA: Has superado el limite de caracteres\n"
                    "Por favor, intentelo de nuevo (max. %d caracteres)\n"
                    "-> "RESET, TAM - 1);
                clearBuffer();
                esValido = 0;
            }
            else
            {
                esValido = 1;
            }
        }
    } 
    while(esValido != 1);
    return i;
}

/**
 * Función devuelve el número de veces que se encuentra 
 * el carácter en la cadena que se pasan como parámetros
 * 
 * @param[in] cadena: 
 *      Texto donde buscamos el numero de veces que se repite cada letra
 * @param[in] caracter: 
 *      Caracter que buscamos dentro de la cadena
 * @param[in] numCaracteres: 
 *      Numero de veces que tiene que iterar el bucle. 
 *      Coincide con el tamanio de la cadena
 * @return Numero de veces que se repite la letra en la cadena
 */
int cuentaCaracter(char* cadena, char caracter, int numCaracteres)
{
    int contadorCoincidencias = 0;
    
    for(int i = 0; i < numCaracteres; i++)
        if(cadena[i] == caracter)
            contadorCoincidencias++;
    return contadorCoincidencias;
}

// Funciones auxiliares
void clearBuffer()
{
    while(getchar() != '\n');
}