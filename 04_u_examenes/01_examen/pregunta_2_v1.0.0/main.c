/*
    * Nombre
        Stefan Trifan

    * Enunciado
        Problema: 
            Calculo de la duracion de un desplazamiento

        Descripcion:
            Se desea implementar una aplicacion que calcule la duracion de un desplazamiento. 
            Para ello se dispone de un reloj que marca el tiempo en el formato HH:MM:SS donde:

            HH señala las horas desde 0 hasta 23
            MM los minutos desde 0 hasta 59
            SS los segundos desde 0 hasta 59

            Las actividades que se deben realizar son:
            Se realiza una toma el instante en el que se comienza el desplazamiento y una toma de tiempo en el que se finaliza el desplazamiento.

            Se comprueba que los valores introducidos cumplen con los rangos antes definidos
            Si los datos introducidos son correctos, a partir de esos instantes recogidos, se calcula el tiempo empleado en el desplazamiento. 
            Para ello se deben indicar los segundos, los minutos y las horas de este.
            Si algun dato de los introducidos no es correcto debe informar al usuario

            Ejemplo de Ejecucion:
                Ingrese el instante de comienzo del desplazamiento: 09:10:20
                Ingrese el instante de finalizacion del desplazamiento: 10:30:25
                El tiempo empleado en el desplazamiento es: 1 hora, 20 minutos y 5 segundos.
*/

#include <stdio.h>

int main() {

    // Declaramos las variables

    // Mediciones inicio desplazamiento
    int horInicio = 0;
    int minInicio = 0;
    int segInicio = 0;

    // Mediciones inicio desplazamiento
    int horFinal = 0;
    int minFinal = 0;
    int segFinal = 0;

    // Tiempo total desplazamiento
    int horTotal = 0;
    int minTotal = 0;
    int segTotal = 0;

    // Contadores
    int contHor = 0;
    int contMin = 0;
    int contSeg = 0;

    // Pedimos por pantalla los datos del inicio del desplazamiento en formato HH:MM:SS
    printf("Ingrese el instante de comienzo del desplazamiento en formato (HH:MM:SS): ");
    scanf("%d:%d:%d", &horInicio, &minInicio, &segInicio);
    printf("Iniciaste el desplazamiento en %d:%d:%d\n", horInicio, minInicio, segInicio);

    // Pedimos por pantalla los datos del inicio del final en formato HH:MM:SS
    printf("Ingrese el instante de finalizacion del desplazamiento en formato (HH:MM:SS): ");
    scanf("%d:%d:%d", &horFinal, &minFinal, &segFinal);
    printf("Finalizaste el desplazamiento en %d:%d:%d\n", horFinal, minFinal, segFinal);

    // Comprobamos que los datos introducidos estan en el formato correcto.
    if(( horInicio >= 0 && horInicio <= 23 ) && ( minInicio >= 0 && minInicio <= 59 ) && ( segInicio >= 0 && segInicio <= 59 )
    && ( horFinal  >= 0 && horFinal <= 23  ) && ( minFinal  >= 0 && minFinal  <= 59 ) && ( segFinal  >= 0 && segFinal <= 59  )){

        // Calculamos la duracion del desplazamiento.
        horTotal = horFinal - horInicio;
        minTotal = minFinal - minInicio;
        segTotal = segFinal - segInicio;

        printf("El tiempo empleado en el desplazamiento es: %d hora(s), %d minuto(s) y %d segundo(s).", horTotal, minTotal, segTotal);

    } else {
        printf("No has introducido los datos correctamente.");
    } 

}



 
