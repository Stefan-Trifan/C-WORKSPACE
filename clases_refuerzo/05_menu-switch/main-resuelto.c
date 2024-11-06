#include <stdio.h>

// Función para verificar si un número es primo
int esPrimo(int num) {
    if (num <= 1) {
        return 0; // Los números menores o iguales a 1 no son primos
    }
    
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return 0; // Si tiene un divisor distinto de 1 y el mismo número, no es primo
        }
    }
    return 1; 
}

int main() {
    int opcion, num, sum = 0;

    do {
        // Menú de opciones
        printf("\nElige un modo:\n");
        printf("1. Verificar si un número es par o impar (if-else)\n");
        printf("2. Calcular la suma de los números hasta un valor dado (for)\n");
        printf("3. Cuenta regresiva (while)\n");
        printf("4. Verificar si un número es primo (función(si quereís))\n");
        printf("5. Salir\n");
        printf("Ingresa el número de la opción deseada: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                // Modo 1: Verificar par o impar usando if-else
                printf("Ingresa un número entero: ");
                scanf("%d", &num);

                if (num % 2 == 0) {
                    printf("El número es par.\n");
                } else {
                    printf("El número es impar.\n");
                }
                break;

            case 2:
                // Modo 2: Sumar números hasta el valor dado usando for
                printf("Ingresa un número entero positivo: ");
                scanf("%d", &num);
                sum = 0;

                for (int i = 1; i <= num; i++) {
                    sum += i;
                }
                printf("La suma de los números de 1 a %d es: %d\n", num, sum);
                break;

            case 3:
                // Modo 3: Cuenta regresiva usando while
                printf("Ingresa un número entero positivo para la cuenta regresiva: ");
                scanf("%d", &num);
                
                printf("Cuenta regresiva desde %d:\n", num);
                while (num >= 0) {
                    printf("%d\n", num);
                    num--;
                }
                break;

            case 4:
                // Modo 5: Verificar si un número es primo usando la función esPrimo
                printf("Ingresa un número entero positivo: ");
                scanf("%d", &num);

                if (esPrimo(num)) {
                    printf("El número %d es primo.\n", num);
                } else {
                    printf("El número %d no es primo.\n", num);
                }
                break;
                
            case 5:
                printf("Saliendo");

            default:
                printf("Opción no válida. Intenta de nuevo.\n");
        }
    } while (opcion != 5 );

    return 0;
}
