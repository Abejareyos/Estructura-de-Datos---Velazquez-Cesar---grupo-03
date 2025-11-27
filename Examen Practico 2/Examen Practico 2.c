/*  
ALGORITMO maximo(A, inicio, fin):

    a) DIVIDE & CONQUER:
    - DIVIDIR: Partimos el arreglo en dos.
    - CONQUISTAR: Obtenemos el valor máximo de cada mitad mediante recursión.
    - COMBINAR: Comparamos ambos máximos y devolvemos el mayor.

     c) CASO BASE:
        Cuando inicio == fin, la sublista tiene un solo elemento.
        Ese elemento es el máximo de esa parte.
    SI inicio == fin ENTONCES
        REGRESAR A[inicio]

     División del arreglo
    medio ← (inicio + fin) / 2

     b) PSEUDOCÓDIGO RECURSIVO PARA CONQUISTAR
    max_izq ← maximo(A, inicio, medio)
    max_der ← maximo(A, medio + 1, fin)

     Combinación
    SI max_izq > max_der ENTONCES
        max_global ← max_izq
    SINO
        max_global ← max_der

    REGRESAR max_global

     ### PUNTO EXTRA: COMPLEJIDAD TEMPORAL DEL ALGORITMO ###
       La recurrencia del algoritmo es:
             T(n) = 2T(n/2) + O(1)
       Por el Teorema Maestro, la complejidad total es:
             T(n) = O(n)
FIN ALGORITMO


*/


#include <stdio.h>
#include <stdlib.h>

// Función recursiva para encontrar el máximo usando Divide & Conquer
int max(int A[], int inicio, int fin) {
    
    if (inicio == fin) { // Si el subarreglo tiene un unico elemento, es el maximo
        return A[inicio];
    }

    int medio = (inicio + fin) / 2; // División del arreglo

    int max_izq = max(A, inicio, medio); // Máximo de la mitad izquierda
    int max_der = max(A, medio + 1, fin); // Máximo de la mitad derecha
    return (max_izq > max_der) ? max_izq : max_der; // Combinación: devolver el mayor de ambos máximos
}

int main() {
    int n;
    printf("### Examen practico 2 ###\n");
    printf("Ingresa la medida del arreglo: ");
    scanf("%d", &n);

    int *A = (int *)malloc(n * sizeof(int)); // Reserva memoria dinamica para el arreglo
    printf("Ingresa los elementos:\n");
    for (int i = 0; i < n; i++) { // Para leer los elementos del arreglo se usa un ciclo for
        scanf("%d", &A[i]);
    }

    int resultado = max(A, 0, n - 1); // Llamada a la función max
    printf("El valor maximo es: %d\n", resultado);
    free(A); // Libera la memoria asignada por malloc
    return 0;
}
