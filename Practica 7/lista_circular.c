#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *siguiente;
};

void insertarInicio(struct Nodo **cabeza, struct Nodo **ultimo, int valor) {
    struct Nodo *nuevo = (struct Nodo*)malloc(sizeof(struct Nodo)); // Asignar memoria para el nuevo nodo
    if (!nuevo) {
        printf("No se pudo reservar memoria\n"); // Verifica si la memoria fue asignada correctamente
        return;
    }

    nuevo->dato = valor;
    if (*cabeza == NULL) { // Si la lista esta vacia la nueva cabeza y la ultima seran el nuevo nodo
        *cabeza = nuevo;
        *ultimo = nuevo;
        nuevo->siguiente = nuevo; // Apunta a sí mismo
    }

    else { // Si la lista no esta vacia se inserta al inicio 
        nuevo->siguiente = *cabeza;
        *cabeza = nuevo;
        (*ultimo)->siguiente = *cabeza; // Mantiene su estructura circular
    }
}

void recorrer(struct Nodo *cabeza) { // Recorre e imprime la lista circular 
    struct Nodo *actual = cabeza;
    do { // Usa un ciclo do-while para asegurar que se recorra al menos una vez
        printf("%d -> ", actual->dato); // Imprime el valor del nodo actual
        actual = actual->siguiente;
    } while (actual != cabeza); // Si llega a la cabeza, termina el recorrido

    printf("%d (inicio)\n", cabeza->dato); // ! Indica que la lista circular vuelve al inicio
}

void eliminar(struct Nodo **cabeza, struct Nodo **ultimo, int valor) { // Elimina un nodo con el valor que indique el usuario
    if (*cabeza == NULL) { // Si la lista esta vacia no se puede eliminar ningun nodo
        printf("La lista esta vacia\n"); 
        return;
    }

    struct Nodo *actual = *cabeza; // Inicia desde la cabeza
    struct Nodo *anterior = *ultimo; // El anterior del nodo de la cabeza se convierte en el ultimo nodo

    do {
        if (actual->dato == valor) // Si encuentra el valor que el usuario quiere eliminar lo va a eliminar 
            break;

        anterior = actual;
        actual = actual->siguiente; // Avanza al siguiente nodo
    } while (actual != *cabeza); // Continua hasta volver a la cabeza


    if (actual == *cabeza && actual == *ultimo) { // Si solo hay un nodo en la lista se elimina
        *cabeza = NULL;
        *ultimo = NULL;
        free(actual);
        printf("Se eliminó el único nodo de la lista\n");
        return;
    }

    if (actual == *cabeza) { // Si el nodo a eliminar es la cabeza
        *cabeza = actual->siguiente;
        (*ultimo)->siguiente = *cabeza;
        free(actual);
        printf("Se eliminó %d (estaba en cabeza)\n", valor);
        return;
    }

    anterior->siguiente = actual->siguiente;

    if (actual == *ultimo) { // Si el nodo a eliminar es el ultimo
        *ultimo = anterior; 
    }

    free(actual); // Libera la memoria del nodo eliminado
    printf("Se elimino el valor %d\n", valor);
}

void liberar(struct Nodo *cabeza, struct Nodo *ultimo) { // Libera la memoria de la lista circular
    if (cabeza == NULL) { // Si la lista esta vacia no hay nada que liberar
        printf("Memoria liberada correctamente\n");
        return;
    }

    struct Nodo *actual = cabeza; // Comienza desde la cabeza
    struct Nodo *temp;

    do { // Recorre la lista circular para liberar cada nodo
        temp = actual;
        actual = actual->siguiente;
        free(temp);
    } while (temp != ultimo);

    printf("Memoria liberada correctamente\n");
}

int main() {
    struct Nodo *cabeza = NULL;
    struct Nodo *ultimo = NULL;
    int n, valor, eliminarValor;
    printf("### Lista circular ###\n");
    printf("Cuantos valores deseas insertar? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Ingresa un valor: ");
        scanf("%d", &valor);

        insertarInicio(&cabeza, &ultimo, valor); // Inserta el nuevo valor al inicio de la lista circular
        printf("Lista circular actual: ");
        recorrer(cabeza);
    }
    printf("****************************\n");
    printf("##### Elimina un valor de la lista #####\n");
    printf("Lista circular final: ");
    printf("\nQue valor deseas eliminar? ");
    scanf("%d", &eliminarValor);

    eliminar(&cabeza, &ultimo, eliminarValor);

    printf("Lista final al eliminar un elemento: ");
    recorrer(cabeza);

    liberar(cabeza, ultimo);

    return 0;
}

/*
1. ¿Qué ventaja tiene la lista circular frente a la simple?
Las listas circulares nos permiten recorrer la lista desde cualquier nodo sin necesidad de volver al inicio, 
facilitando las operaciones de insercion y eliminacion de nodos.
2. ¿Qué error puede causar un bucle infinito en una lista circular?
Las listas circulares apuntaran un nodo al siguiente de forma indefinida 
hasta que el programa se quede sin memoria o se bloquee.
3. ¿Qué estructuras o programas del mundo real se basan en listas circulares?
Los videojuegos al momento de elejir algun elemento, ya que al llegar al final de la lista volveremos al inicio,
otro ejemplo son las playlists de musica y la opcion de repetir una cancion de forma indefinida, ademas de 
las luces de navidad que se encienden y apagan en una secuencia continua. 
*/