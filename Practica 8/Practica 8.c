
#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *anterior;
    struct Nodo *siguiente;
};

void insertarInicio(struct Nodo **inicio, int valor) { // Insertar al inicio
    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo)); // Crea un nuevo nodo
    nuevo->dato = valor; // Asigna un valor al nuevo nodo
    nuevo->anterior = NULL; 
    nuevo->siguiente = *inicio;

    if (*inicio != NULL) // Si la lista no esta vacia, actualiza el puntero anterior del nodo actual de inicio
        (*inicio)->anterior = nuevo;

    *inicio = nuevo;
}

void insertarFinal(struct Nodo **inicio, int valor) { // Insertar al final
    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo)); // Crear nuevo nodo
    nuevo->dato = valor; 
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL; // Inicializa al puntero anterior

    if (*inicio == NULL) { // Si la lista esta vacia, asigna un nuevo nodo al inicio
        *inicio = nuevo;
        return;
    }

    struct Nodo *temp = *inicio;
    while (temp->siguiente != NULL) // Si no esta vacia, recorre hasta el final
        temp = temp->siguiente;

    temp->siguiente = nuevo; // Asigna el nuevo nodo al final
    nuevo->anterior = temp; // Actualiza el puntero anterior del nuevo nodo
}

void recorrerAdelante(struct Nodo *inicio) { // Recorre hacia adelante
    struct Nodo *temp = inicio; // Crea un nodo temporal para recorrer la lista 
    printf("\nLista hacia adelante: "); 
    while (temp != NULL) { // Mientras no sea NULL, imprime el dato y avanza al siguiente
        printf("%d ", temp->dato);
        temp = temp->siguiente;
    }
    printf("\n");
}

void recorrerAtras(struct Nodo *inicio) { // Recorre hacia atrás la lista para imprimir los nodos
    if (inicio == NULL) return; // Si la lista esta vacia, regresa a la funcion NULL

    struct Nodo *temp = inicio;
    while (temp->siguiente != NULL) // Recorre hasta el final de la lista
        temp = temp->siguiente;

    printf("\nLista hacia atras: ");
    while (temp != NULL) {
        printf("%d ", temp->dato); // Imprime el dato y retrocede al anterior
        temp = temp->anterior;
    }
    printf("\n");
}

void eliminar(struct Nodo **inicio, int valor) { // Elimina un nodo con un valor especifico
    if (*inicio == NULL) return; // Si la lista esta vacia, regresa a la funcion NULL
   
    struct Nodo *temp = *inicio; // Crea un nodo temporal para recorrer la lista

    while (temp != NULL && temp->dato != valor)
        temp = temp->siguiente; // Recorre hasta encontrar el valor o llegar al final

    if (temp == NULL) {// Si no se encuentra nungin nodo se imprime un mensaje y regresa
        printf("Valor no encontrado\n");
        return;
    }

    if (temp == *inicio) { // Si es el inicio entonces actualiza el puntero
        *inicio = temp->siguiente;
        if (*inicio != NULL) // Si la lista no queda vacia, actualiza el puntero anterior
            (*inicio)->anterior = NULL;
    }
    else if (temp->siguiente == NULL) { // Si es el final, actualiza el puntero siguiente del anterior
        temp->anterior->siguiente = NULL;
    }
    else { // Si es un nodo intermedio, actualiza ambos punteros
        temp->anterior->siguiente = temp->siguiente;
        temp->siguiente->anterior = temp->anterior;
    }

    free(temp); // Libera memoria del nodo eliminado para evitar fugas de memoria
    printf("Nodo eliminado\n");
}

void liberar(struct Nodo *inicio) { // Libera toda la memoria de la lista
    struct Nodo *temp;
    while (inicio != NULL) {
        temp = inicio;
        inicio = inicio->siguiente;
        free(temp);
    }
    printf("Memoria liberada correctamente.\n"); // Mensaje de confirmacion
} 

void insertarCircularFinal(struct Nodo **inicio, int valor) { // Inserta al final una lista circular doblemente ligada
    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    nuevo->dato = valor;

    if (*inicio == NULL) { // Si la lista esta vacia, el nuevo nodo apunta a si mismo y se asigna como inicio
        *inicio = nuevo;
        nuevo->siguiente = nuevo;
        nuevo->anterior = nuevo;
        return;
    }

    struct Nodo *ultimo = (*inicio)->anterior; // Obtiene el ultimo nodo

    nuevo->siguiente = *inicio;
    nuevo->anterior = ultimo;
    ultimo->siguiente = nuevo;
    (*inicio)->anterior = nuevo;
}

void recorrerCircular(struct Nodo *inicio) { // Recorre e imprime una lista circular doblemente ligada
    if (inicio == NULL) return; // Si la lista esta vacia, regresa a la funcion NULL

    struct Nodo *temp = inicio;
    printf("\nLista circular: ");

    do {
        printf("%d ", temp->dato); // Imprime el dato y avanza al siguiente
        temp = temp->siguiente;
    } while (temp != inicio);

    printf("\n");
}

void eliminarCircular(struct Nodo **inicio, int valor) { // Elimina un nodo con un valor especifico en una lista circular doblemente ligada
    if (*inicio == NULL) return; // Si la lista esta vacia, regresa a la funcion NULL

    struct Nodo *temp = *inicio; // Crea un nodo temporal para recorrer la lista

    do { // Recorre la lista hasta encontrar el valor o volver al inicio
        if (temp->dato == valor) break;
        temp = temp->siguiente;
    } while (temp != *inicio); // Uso de do-while para asegurar una iteracion

    if (temp->dato != valor) { // Si no se encuentra el valor, imprime un mensaje y regresa
        printf("Valor no encontrado\n");
        return;
    }

    if (temp->siguiente == temp) { // Si es el unico nodo, libera y asigna NULL al inicio
        free(temp);
        *inicio = NULL;
        printf("La lista quedo vacia\n");
        return;
    }

    if (temp == *inicio) // Si es el nodo de inicio, actualiza el puntero de inicio
        *inicio = temp->siguiente;

    temp->anterior->siguiente = temp->siguiente;
    temp->siguiente->anterior = temp->anterior;

    free(temp);
    printf("Nodo eliminado correctamente\n");
}

int main() { // Menu principal del programa, parte A y B
    struct Nodo *inicio = NULL;
    int n, valor;

    printf("\n### LISTA DOBLEMENTE LIGADA ###\n");
    printf("Cuantos valores deseas insertar al inicio? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &valor);
        insertarInicio(&inicio, valor);
    }

    recorrerAdelante(inicio);

    printf("\nCuantos valores deseas insertar al final? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &valor);
        insertarFinal(&inicio, valor);
    }

    recorrerAdelante(inicio);
    recorrerAtras(inicio);

    printf("\nValor a eliminar: ");
    scanf("%d", &valor);
    eliminar(&inicio, valor);
    recorrerAdelante(inicio);

    liberar(inicio);

    inicio = NULL; // Reinicia el inicio para la parte B y no escribir sobre memoria liberada, ademas de evitar escribir el codigo por separado 
    printf("\n#### LISTA CIRCULAR DOBLE ####\n"); 
    printf("Cuantos valores deseas insertar en la lista circular doble? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &valor);
        insertarCircularFinal(&inicio, valor);
    }

    recorrerCircular(inicio);

    printf("\nValor que desea eliminar en la lista circular: ");
    scanf("%d", &valor);
    eliminarCircular(&inicio, valor);
    recorrerCircular(inicio);

    return 0;
}

/*
 PREGUNTAS PARTE (A): LISTA DOBLEMENTE LIGADA
1.  Porque tenemos acceso directo tanto al nodo anterior como al nodo siguiente, 
 lo que facilita la insercion y eliminacion de nodos en ambas direcciones
2.  Se rompe la lista, causa errores o segmentation faults al intentar acceder a nodos que ya no existen
3. Navegadores web (adelante/atrás), listas de reproducción, editores
 (deshacer/rehacer), videojuegos como listas de objetos o inventarios

PREGUNTAS PARTE (B): LISTA DOBLEMENTE LIGADA CIRCULAR

1.  La lista circular nunca tiene NULL, la doble si porque el primer nodo apunta al ultimo y viceversa
2.  No detenerse cuando volvemos al nodo inicio, sino usar un do-while para asegurar que se recorra al menos una vez
3.  Juegos por turnos parecidos a los juegos de mesa en las que cada jugador toma su turno para tirar los dados o hacer un movimiento,
otro ejemplo podrian ser las galerias de imagenes que permiten navegar continuamente a traves de las imagenes sin llegar a un final.
   */
