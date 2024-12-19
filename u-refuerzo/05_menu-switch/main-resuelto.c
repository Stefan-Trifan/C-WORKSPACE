#include <stdio.h>

// Funcion para verificar si un numero es primo
int esPrimo(int num) {
    if (num <= 1) {
        return 0; // Los numeros menores o iguales a 1 no son primos
    }
    
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return 0; // Si tiene un divisor distinto de 1 y el mismo numero, no es primo
        }
    }
    return 1; 
}

int main() {
    int opcion, num, sum = 0;

    do {
        // Menu de opciones
        printf("\nElige un modo:\n");
        printf("1. Verificar si un numero es par o impar (if-else)\n");
        printf("2. Calcular la suma de los numeros hasta un valor dado (for)\n");
        printf("3. Cuenta regresiva (while)\n");
        printf("4. Verificar si un numero es primo (funcion(si quereis))\n");
        printf("5. Salir\n");
        printf("Ingresa el numero de la opcion deseada: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                // Modo 1: Verificar par o impar usando if-else
                printf("Ingresa un numero entero: ");
                scanf("%d", &num);

                if (num % 2 == 0) {
                    printf("El numero es par.\n");
                } else {
                    printf("El numero es impar.\n");
                }
                break;

            case 2:
                // Modo 2: Sumar numeros hasta el valor dado usando for
                printf("Ingresa un numero entero positivo: ");
                scanf("%d", &num);
                sum = 0;

                for (int i = 1; i <= num; i++) {
                    sum += i;
                }
                printf("La suma de los numeros de 1 a %d es: %d\n", num, sum);
                break;

            case 3:
                // Modo 3: Cuenta regresiva usando while
                printf("Ingresa un numero entero positivo para la cuenta regresiva: ");
                scanf("%d", &num);
                
                printf("Cuenta regresiva desde %d:\n", num);
                while (num >= 0) {
                    printf("%d\n", num);
                    num--;
                }
                break;

            case 4:
                // Modo 5: Verificar si un numero es primo usando la funcion esPrimo
                printf("Ingresa un numero entero positivo: ");
                scanf("%d", &num);

                if (esPrimo(num)) {
                    printf("El numero %d es primo.\n", num);
                } else {
                    printf("El numero %d no es primo.\n", num);
                }
                break;
                
            case 5:
                printf("Saliendo");

            default:
                printf("Opcion no valida. Intenta de nuevo.\n");
        }
    } while (opcion != 5 );

    return 0;
}
