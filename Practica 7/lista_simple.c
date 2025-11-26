#include <stdio.h>
#include <stdlib.h>
struct Nodo {
    int dato;
    struct Nodo *siguiente;
};

void insertarInicio(struct Nodo **cabeza, int valor) { // Inserta un nuevo nodo al inicio de la lista
    struct Nodo *nuevo = (struct Nodo*)malloc(sizeof(struct Nodo)); // Asignar memoria para el nuevo nodo
    nuevo->dato = valor; // Asignar un nuveo valor al nodo
    nuevo->siguiente = *cabeza; // El nuevo nodo apunta a la anterior cabeza
    *cabeza = nuevo; // Actualiza la cabeza para que sea un nuevo nodo
}

void recorrer(struct Nodo *cabeza) {
    struct Nodo *actual = cabeza;
    while (actual != NULL) {
        printf("%d -> ", actual->dato); // Imprime el valor del nodo actual
        actual = actual->siguiente;
    }
    printf("NULL\n"); // Indica el final de la lista
}

void eliminar(struct Nodo **cabeza, int valor) {
    struct Nodo *actual = *cabeza;
    struct Nodo *anterior = NULL;

    if (actual->dato == valor) { 
        *cabeza = actual->siguiente; // Si el valor esta en la cabeza, actualiza la cabeza 
        free(actual); // Libera la memoria del nodo eliminado porque ya no esta en la lista
        printf("Se elimino el valor %d \n", valor); 
        return;
    }

    while (actual != NULL && actual->dato != valor) { // Busca el valor en la lista
        anterior = actual; // Guarda el nodo anterior
        actual = actual->siguiente; 
    }

    anterior->siguiente = actual->siguiente;
    free(actual); // Libera memoria del nodo eliminado como en el caso anterior
    printf("Se elimino el valor %d\n", valor); 
}


void liberar(struct Nodo *cabeza) { // Libera toda la memoria usada por la lista
    struct Nodo *actual = cabeza; // Comienza desde la cabeza
    while (actual != NULL) { // Recorre toda la lista para insertar los nodos 
        struct Nodo *temp = actual; // Guarda el nodo actual
        actual = actual->siguiente; 
        free(temp); 
    }
    printf("Memoria liberada correctamente\n");
}

int main() {
    struct Nodo *cabeza = NULL; // La cabeza de la lista inicia como NULL
    int n, valor, eliminarValor; 

    printf("### Lista simple ###\n");
    printf("Cuantos elementos deseas insertar?\n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Ingresa un valor: ");
        scanf("%d", &valor);

        insertarInicio(&cabeza, valor);
        printf("Lista actual: ");
        recorrer(cabeza); // Muestra la lista despues de que el usuario inserte un nuevo valor 
    }

    printf("****************************\n");
    printf("##### Elimina un valor de la lista #####");
    printf("\nQue valor deseas eliminar? (Escribe el numero): ");
    scanf("%d", &eliminarValor);
    eliminar(&cabeza, eliminarValor);

    printf("Lista final al eliminar un elemento: ");
    recorrer(cabeza);

    liberar(cabeza);
    return 0;
}
