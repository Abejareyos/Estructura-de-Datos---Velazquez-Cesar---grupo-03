#include <stdio.h>
#include <stdlib.h>

#define MAX 15  // Tamaño máximo de la pila y la cola

//Pila 
struct Pila {
    int elementos[MAX];
    int tope;
};
// Inicializar la pila
void iniciaPila(struct Pila *p) {
    p->tope = -1;
    printf("Pila inicializada vacia\n");
}

// Verificar si la pila está llena
int pilafull(struct Pila *p) {
    return p->tope == MAX - 1;
}

// Verificar si la pila está vacía
int pilaEmpty(struct Pila *p) {
    return p->tope == -1;
}

// Insertar elemento (push)
void push(struct Pila *p, int valor) {
    if (pilafull(p)) { // Si la pila esta llena, no se puede insertar
        printf("La pila esta llena %d \n", valor);
        printf("No puedes insertar el elemento");
        return;
    }
    p->tope++;
    p->elementos[p->tope] = valor; // Inserta el elemento
    printf("Elemento %d apilado \n", valor); 
}

// Extraer elemento (pop)
int pop(struct Pila *p) {
    if (pilaEmpty(p)) { // Si la pila está vacía no se puede extraer
        printf("La pila esta vacia \n");
        printf("No se puede extraer el elemento \n");
        return -1; // Valor de error
    }
    int valor = p->elementos[p->tope];
    p->tope--; // Disminuir el tope
    return valor;
}

// Mostrar pila
void mostrarPila(struct Pila *p) {
    if (pilaEmpty(p)) { // Si la pila está vacía
        printf("Pila vacia\n");
        return;
    }

    printf("-- Elementos de la pila -- \n"); // Mostrar toda la pila
    for (int i = 0; i <= p->tope; i++) {
        printf("%d ", p->elementos[i]);
    }
    printf("\n");
}

// Cola
struct Cola {
    int elementos[MAX]; 
    int frente;
    int final;
    int cantidad;
};

// Inicializar la cola
void iniciaCola(struct Cola *c) {
    c->frente = 0;
    c->final = -1;
    c->cantidad = 0;
    printf("Cola inicializada vacia\n");
}

// Verificar si la cola está llena
int colafull(struct Cola *c) {
    return c->cantidad == MAX;
}

// Verificar si la cola está vacía
int colaEmpty(struct Cola *c) {
    return c->cantidad == 0;
}

// Insertar elemento (enqueue)
void enqueue(struct Cola *c, int valor) {
    if (colafull(c)) {
        printf("La cola esta llena, no se puede insertar el elemento %d \n", valor);
        return;
    }
    c->final = (c->final + 1) % MAX;
    c->elementos[c->final] = valor;
    c->cantidad++;
    printf("Elemento %d encolado\n", valor);
}

// Extraer elemento (dequeue)
int dequeue(struct Cola *c) {
    if (colaEmpty(c)) {
        printf("La cola esta vacia, no se puede desencolar el elemento \n");
        return -1; // Valor de error
    }
    int valor = c->elementos[c->frente];
    c->frente = (c->frente + 1) % MAX;
    c->cantidad--;
    return valor;
}

// Mostrar cola
void mostrarCola(struct Cola *c) {
    if (colaEmpty(c)) {
        printf("Cola vacia\n");
        return;
    }

    printf("-- Elementos de la cola -- \n"); 
    int i = c->frente;
    for (int j = 0; j < c->cantidad; j++) {
        printf("%d ", c->elementos[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    struct Pila miPila;
    struct Cola miCola;

    iniciaPila(&miPila);
    iniciaCola(&miCola);

    int n, valor, desapilar, encolar, desencolar; // Variables para iniciar las operaciones de pila y cola
    // Lo que se mostrara en pantalla al iniciar el programa
    
    printf("\n #### Practica 5: Pila y Cola ####"); 
    printf("\n--- PILA ---\n");
    printf("Cuantos elementos deseas apilar? (maximo %d): ", MAX);
    scanf("%d", &n);
    if (n > MAX) n = MAX;

    for (int i = 0; i < n; i++) {
        printf("Ingresa el elemento #%d: ", i + 1);
        scanf("%d", &valor);
        push(&miPila, valor); // Apilar el elemento
        mostrarPila(&miPila);
    }

    printf("\nCuantos elementos deseas desapilar?: ");
    scanf("%d", &desapilar);

    for (int i = 0; i < desapilar; i++) {
        int elemento = pop(&miPila); // Desapilar el elemento
        if (elemento != -1) {
            printf("Elemento %d desapilado.\n", elemento);
            mostrarPila(&miPila);
        } else {
            break;
        }
    }

    // COLA
    printf("\n--- COLA ---\n");
    printf("Cuantos elementos deseas encolar? (enqueque) (maximo %d): ", MAX);
    scanf("%d", &encolar);
    if (encolar > MAX) encolar = MAX;

    for (int i = 0; i < encolar; i++) {
        printf("Ingresa el elemento #%d: ", i + 1);
        scanf("%d", &valor);
        enqueue(&miCola, valor);
        mostrarCola(&miCola);
    }

    printf("\nCuantos elementos deseas desencolar? (dequeque): ");
    scanf("%d", &desencolar);

    for (int i = 0; i < desencolar; i++) {
        int elemento = dequeue(&miCola);
        if (elemento != -1) {
            printf("Elemento %d desencolado\n", elemento);
            mostrarCola(&miCola);
        } else {
            break;
        }
    }

    printf("Orden de salida:\n");
    printf("Pila -> LIFO (ultimo en entrar, primero en salir)\n");
    printf("Cola -> FIFO (primero en entrar, primero en salir)\n");

    return 0;
}
//--- Actividad ---
/*1. Su orden de salida esta perfectamente definido en su concepto de LIFO en las pilas 
y FIFO en las colas*/
/*2. El programa intentara acceder a las posiciones de memoria 
provocando errores o un comportamiento indefinido si no le mandamos un mensaje de error*/
/* 3. Al tener un tamaño máximo, tanto la pila como la cola pueden llenarse. 
Si intentamos exeder el limite, el programa no se ejecutara correctamente corrompiendo la memoria
o en este caso mandando un mensaje de error reiniciando el programa*/