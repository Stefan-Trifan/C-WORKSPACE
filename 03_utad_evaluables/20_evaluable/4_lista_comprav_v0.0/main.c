/*
    *   Autor
        Stefan Trifan

    *   Estado

    *   Enunciado 4 - Lista de la compra
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum 
{
    agregar = 1, atender, mostrar, salir
} 
t_menu;

typedef int t_queue;

// Funciones del programa
void initQueue   (t_queue *q, int capacity);
int  isFull      (t_queue *q); // No sirve
int  isEmpty     (t_queue *q); 
void resizeQueue (t_queue *q);
void enqueue     (t_queue *q, char *name); 
void dequeue     (t_queue *q); 
void displayQueue(t_queue *q);
void freeQueue   (t_queue *q);
void menu        (t_queue *q);

// Funciones auxiliares
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    

    printf("\n_________________________________________EXIT\n\n");
    return EXIT_SUCCESS;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa
/**
 * @brief Inicializa la cola con una capacidad inicial.
 * 
 * @param[out] q Puntero a la estructura de la cola.
 * @param[in] capacity Capacidad inicial de la cola.
 */
void initQueue(t_queue *q, int capacity)
{

}

/**
 * @brief Verifica si la cola está llena.
 * 
 * @return 1 si la cola está llena, 0 en caso contrario.
 */
int isFull(t_queue *q)
{
    return 0;
}

/**
 * @brief Verifica si la cola está vacía.
 * 
 * @return 1 si la cola está vacía, 0 en caso contrario.
 */
int isEmpty(t_queue *q)
{
    return 0;
}

/**
 * @brief Redimensiona la cola cuando está llena.
 */
void resizeQueue(t_queue *q)
{

}

/**
 * @brief Agrega un cliente al final de la cola. 
 *        Verifica si la cola está llena para redimensionar.
 * 
 * @param[out] name: Nombre del cliente.
 */
void enqueue(t_queue *q, char *name)
{

}

/**
 * @brief Atiende al primer cliente de la cola. 
 *        Si está vacía hay que indicar que está vacía. 
 */
void dequeue(t_queue *q)
{

}

/**
 * @brief Muestra todos los clientes en la cola.
 */
void displayQueue(t_queue *q)
{

}

/**
 * @brief Libera la memoria asignada a la cola.
 */
void freeQueue(t_queue *q)
{

}

/**
 * @brief Maneja la interacción con el usuario utilizando enumerados.
 */
void menu(t_queue *q)
{

}

// Funciones auxiliares
void clearBuffer()
{
    while (getchar() != '\n');
}