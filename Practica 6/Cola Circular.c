#include <stdio.h>
#include <stdlib.h>

#define MAX 25  // Capacidad máxima de la cola circular

// Definicion de la estructura Cola Circular
typedef struct {
    int datos[MAX];
    int frente;
    int final;
    int size; // capacidad actual
} ColaCircular;

// Funciones
void inicializarCola(ColaCircular *cola);
int isEmpty(ColaCircular *cola);
int isFull(ColaCircular *cola);
void enqueue(ColaCircular *cola, int valor);
int dequeue(ColaCircular *cola);
int peek(ColaCircular *cola);
void printQueue(ColaCircular *cola);

// Función principal
int main() {
    ColaCircular cola;
    inicializarCola(&cola);

    printf("\n----- COLA CIRCULAR -----\n");

    // Encolar y desencolar elementos para demostrar el funcionamiento
    // Encolar 5, 10, 15
    enqueue(&cola, 5);
    enqueue(&cola, 10);
    enqueue(&cola, 15);
    printQueue(&cola); // Mostrar el estado actual de la cola

    // Desencolar un elemento
    printf("\nDesencolando un elemento\n"); // elemento desencolado
    dequeue(&cola);
    printQueue(&cola); //

    // Encolar 20, 25, 30
    enqueue(&cola, 20);
    enqueue(&cola, 25);
    enqueue(&cola, 30);
    printQueue(&cola); // Mostrar el estado actual de la cola

    // Reciclaje de los espacios al desencolar y encolar más elementos 
    printf("\nReciclar los espacios\n");

    return 0;
}

// Inicializa la cola vacía
void inicializarCola(ColaCircular *cola) {
    cola->frente = 0;
    cola->final = 0;
    cola->size = 0;
    printf("Cola circular inicializada.\n");
}

// Verifica si la cola está vacía
int isEmpty(ColaCircular *cola) {
    return cola->size == 0; // Retorna 1 si está vacía, 0 si no lo está
}

// Verifica si la cola está llena
int isFull(ColaCircular *cola) {
    return cola->size == MAX; 
}

// Inserta un elemento en la cola
void enqueue(ColaCircular *cola, int valor) {

    cola->datos[cola->final] = valor;
    cola->final = (cola->final + 1) % MAX; // Avanza circularmente
    cola->size++;
    printf("Encolado: %d\n", valor);
}

// Elimina un elemento del frente
int dequeue(ColaCircular *cola) {
   
    int valor = cola->datos[cola->frente];
    cola->frente = (cola->frente + 1) % MAX; // Avanza circularmente
    cola->size--;
    printf("Desencolado: %d\n", valor);
    return valor;
}

// Devuelve el primer elemento sin eliminarlo
int peek(ColaCircular *cola) {
    if (isEmpty(cola)) {
        printf("Cola vacia\n");
        return -1;
    }
    return cola->datos[cola->frente];
}

// Imprime el contenido actual de la cola
void printQueue(ColaCircular *cola) {
    if (isEmpty(cola)) {
        printf("Cola vacia\n");
        return;
    }

    printf("--Elementos de la cola--\n");
    int i;
    for (i = 0; i < cola->size; i++) {
        int index = (cola->frente + i) % MAX;
        printf("%d ", cola->datos[index]);
    }
    printf("\nFrente: %d  Final: %d  Capacidad: %d\n",
           cola->frente, cola->final, cola->size);
}

/* Preguntas (A) */
/* 1. Porque al usar la operación (indice + 1) % MAX, los indices se reciclan 
y los espacios liberados al inicio del arreglo pueden volver a usarse 
cuando llega al límite */
/* 2. Vuelve al principio (posición 0) gracias al uso del operador módulo (%) */
/* 3.  No se puede insertar el nuevo elemento, pudiendo
sobrescribir datos válidos */
