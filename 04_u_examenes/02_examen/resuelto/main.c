#include <stdio.h>

// Prototipos de las funciones
int generaPassword();
int esNumero7cifras(int numero);
int esNumero3pares(int numero);
int sonIguales(int numero1, int numero2);

int main(int argc, char *argv[]) {
    int opcion;
    int passwordAlmacenada = 0;  // 0 indica que no se ha generado una contraseÃ±a valida
    int passwordIngresada;
	int salir = 0;

    do {
        // Mostrar menÃº dependiendo si la password estÃ¡ generada o no
        if (passwordAlmacenada == 0) {
            printf("\nMenu:\n");
            printf("1. Genera password\n");
            printf("2. Introducir password\n");
            printf("3. Salir\n");
        } else {
            printf("\nMenu:\n");
            printf("1. Cambia password\n");
            printf("2. Introducir password\n");
            printf("3. Salir\n");
        }

        printf("Seleccione una Opcion: ");
        scanf("%d", &opcion);
		

        switch (opcion) {
            case 1:
				// Opcion para generar o cambiar la password
				printf ("la pss es %d\n",passwordAlmacenada);
                if (passwordAlmacenada == 0) {
					passwordAlmacenada = generaPassword();
                    printf("Password generada correctamente.\n");
                } else {
                    // Cambiar la password existente
					passwordAlmacenada = generaPassword();
                    printf("Password cambiada correctamente.\n");
                }
			break;

            case 2:
                // Opcion para introducir la password y verificarla
                printf("Introduce la password: ");
                scanf("%d", &passwordIngresada);
                if (sonIguales(passwordAlmacenada, passwordIngresada)) {
                    printf("La password es correcta.\n");
                } else {
                    printf("La password es incorrecta.\n");
                }
			break;

            case 3:
                // Opcion para salir
				salir = 1;
                printf("Saliendo del programa.\n");
              
            break;
			default:
                printf("Opcion no valida. Intente de nuevo.\n");
        }
    }while (!salir);
}

// Funcion para generar una nueva password
int generaPassword() {
    int nuevaPassword;
    do {
        printf("Genera una password de 7 cifras con al menos 3 pares: ");
        scanf("%d", &nuevaPassword);
		while (getchar() != '\n'){}

        if (!esNumero7cifras(nuevaPassword)) {
            printf("La password no tiene 7 cifras.\n");
        } else if (!esNumero3pares(nuevaPassword)) {
            printf("La password no tiene al menos 3 cifras pares.\n");
        }
    } while (!esNumero7cifras(nuevaPassword) || !esNumero3pares(nuevaPassword));
    return nuevaPassword;
}

// Funcion que verifica si un nÃºmero tiene 7 cifras
int esNumero7cifras(int numero) {
    return numero >= 1000000 && numero <= 9999999;
}

// Funcion que verifica si un nÃºmero tiene al menos 3 cifras pares
int esNumero3pares(int numero) {
    int Resultado = 0;
	int pares = 0;
    while (numero > 0) {
        int digito = numero % 10;
        if (digito % 2 == 0) {
            pares++;
        }
        numero /= 10;
    }
	if (pares >= 3)
		Resultado = 1;
    return Resultado;
}

// Funcion que compara si dos nÃºmeros son iguales
int sonIguales(int numero1, int numero2) {
    return numero1 == numero2;
}