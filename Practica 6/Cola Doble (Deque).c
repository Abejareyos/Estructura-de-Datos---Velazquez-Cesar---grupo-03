#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Tamaño máximo del deque

// Estructura de la cola doble (deque)
typedef struct {
    int datos[MAX]; // Arreglo para almacenar los elementos
    int front; // Indice del frente
    int size;  // Capacidad actual
} Deque;

// Funcion para inicializar la cola doble
void inicializar(Deque *dq) {
    dq->front = 0;
    dq->size = 0;
    printf("\n ------ Practica 6: Cola Doble (Deque) ------\n");
    printf(" ## Deque inicializado: front = %d, size = %d ## \n ", dq->front, dq->size);
}

// Funcion para obtener rear
int getRear(Deque *dq) { // rear es el indice del ultimo elemento
    if (dq->size == 0)
        return -1; // Deque vacío
    return (dq->front + dq->size - 1) % MAX; // Indice del ultimo elemento
}

// Verifica si el deque esta lleno o vacío
int estaLleno(Deque *dq) { return dq->size == MAX; } // Deque lleno
int estaVacio(Deque *dq) { return dq->size == 0; } // Deque vacío
//---- Operaciones deque ----
// Insertar por el frente
void insert_front(Deque *dq, int valor) {
    dq->front = (dq->front - 1 + MAX) % MAX; // Mueve el frente hacia atrás circularmente
    dq->datos[dq->front] = valor; // Coloca el valor en la nueva posición del frente
    dq->size++; // Incrementa el tamaño al colocar un nuevo elemento
    printf("insert_front(%d): front=%d, rear=%d, size=%d\n", valor, dq->front, getRear(dq), dq->size);
}

// Insertar por el final
void insert_rear(Deque *dq, int valor) {
    int rear = (dq->front + dq->size) % MAX; // Calcula el indice del final
    dq->datos[rear] = valor;
    dq->size++; // Incrementa el tamaño del deque
    printf("insert_rear(%d): front=%d, rear=%d, size=%d\n", valor, dq->front, getRear(dq), dq->size);
}

// Eliminar por el frente
void delete_front(Deque *dq) {
    int valor = dq->datos[dq->front];
    dq->front = (dq->front + 1) % MAX;
    dq->size--;
    printf("delete_front(): eliminado %d, front=%d, rear=%d, size=%d\n", valor, dq->front, getRear(dq), dq->size);
}

// Eliminar por el final
void delete_rear(Deque *dq) {
    int rear = getRear(dq); // Indice del ultimo elemento
    int valor = dq->datos[rear];
    dq->size--; // Disminuye el tamaño del deque
    printf("delete_rear(): eliminado %d, front=%d, rear=%d, size=%d\n", valor, dq->front, getRear(dq), dq->size);
}

// Ver el frente y el final
void peek_front(Deque *dq) {
    if (estaVacio(dq)) printf("Deque vacio\n"); // No hay elementos
    else printf("peek_front(): %d\n", dq->datos[dq->front]); // Muestra el elemento del frente
}

void peek_rear(Deque *dq) { // No hay elementos
    if (estaVacio(dq)) printf("Deque vacio\n");
    else printf("peek_rear(): %d\n", dq->datos[getRear(dq)]);
}

// Imprimir el contenido actual del deque
void printDeque(Deque *dq) {
    printf("--- Contenido del deque ---\n");
    if (estaVacio(dq)) {
        printf("vacio]\n"); // Si está vacío, solo muestra vacío
        return;
    }
    for (int i = 0; i < dq->size; i++) {
        int idx = (dq->front + i) % MAX;
        printf("[");
        printf("%d", dq->datos[idx]);
        printf("]");
    }
    printf("\n");
}

// Prueba de la cola doble (deque)
// Inicio del programa
int main() {
    Deque dq;
    inicializar(&dq); // Inicializa el deque

    insert_front(&dq, 10);
    insert_rear(&dq, 15);
    insert_rear(&dq, 20);
    insert_front(&dq, 30);
    insert_rear(&dq, 40);
    // Intento de inserción cuando está lleno
    printDeque(&dq);

    delete_front(&dq);
    delete_rear(&dq);

    printDeque(&dq);
    // Inserta nuevos valores para observar el movimiento de índices
    insert_rear(&dq, 50);
    insert_front(&dq, 60);
    insert_rear(&dq, 70);

    printDeque(&dq);

    peek_front(&dq);
    peek_rear(&dq);

    return 0;
}

/* Reflexion B*/
/*1. La cola circula usa una estructura lineal en la que solo los elementos pueden  ingresar por el final,
en cambio las colas dobles, los elementos se pueden agregar por ambos lados */
/*2. FIFO (cola): insert_rear() + delete_front() / LIFO (pila): insert_front() + delete_front()*/
/*3. Deque puede usarse tanto como pila, como cola, haciendo el programa mucho mas practico y concreto,
ademas es usado en algoritmos de busqueda y navegadores web al momento de avanzar, retroceder o eliminar
una pestana, ademas en los videojuegos de rol o estrategicos como pokemon, gestionan el orden de las acciones del pokemon*/
