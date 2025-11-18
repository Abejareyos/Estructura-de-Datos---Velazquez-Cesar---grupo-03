#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *arr = NULL;      
    int *arr2 = NULL;     
    int n, m, i; // n: tamaño inicial, m: nuevo tamaño

    //Paso1: Memorioa dinamica malloc
    printf("##### Paso 1 #####\n");
    printf("Cuantos enteros deseas almacenar? ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    

    printf("Valores iniciales (basura):\n[");
    for (i = 0; i < n; i++) {
        printf(" %d", arr[i]); 
    }
    printf(" ]\n\n");

    //Paso 2: Memoria dinamica calloc
    printf("##### Paso 2 #####\n");
    printf("Reservar memoria con calloc\n");
    arr2 = (int *)calloc(n, sizeof(int));
    

    printf("Valores iniciales en arr2 (calloc, ceros):\n[");
    for (i = 0; i < n; i++) {
        printf(" %d", arr2[i]); // Tendran que ser ceros
    }
    printf(" ]\n\n");

    //Paso 3: LLenar el arreglo
    printf("##### Paso 3 #####\n");
    printf("Llenar el arreglo\n");
    for (i = 0; i < n; i++) {
        printf("Ingresa valor para arr2[%d]: ", i);
        scanf("%d", &arr2[i]);
    }
    //Mostrar el arreglo
    printf("Valores en arr2:\n[");
    for (i = 0; i < n; i++) {
        printf(" %d", arr2[i]);
    }
    printf(" ]\n"); //Fin de la impresion del arrelgo

    //Paso 4: Redimensionar con realloc
    printf("##### Paso 4 #####\n");
    printf("Redimensionar con realloc\n");
    printf("Ingrese una nueva medida para el arreglo"); //Queria usar la palabra "tamaño" pero me marcaba error
    scanf("%d", &m);

    int *tmp = (int *)realloc(arr2, m * sizeof(int));
    arr2 = tmp;


    // Si el arreglo es más grande, pedir los valores que faltan
    if (m > n) {
        for (i = n; i < m; i++) {
            printf("Ingresa valor para arr2[%d]: ", i);
            scanf("%d", &arr2[i]);
        }
    }

    printf("Valores actuales en arr2:\n[");
    for (i = 0; i < m; i++) {
        printf(" %d", arr2[i]);
    }
    printf(" ]\n\n"); //Fin de la impresion del arrelgo

    //Paso 5: Liberar memoria
    printf("##### Paso 5 #####\n");
    printf("Es hora de liberar memoria\n");
    free(arr);
    free(arr2);
    printf("Memoria liberada\n");

    return 0;
}

/* 
1. ¿Qué diferencia observaron entre los valores iniciales con malloc y calloc?
En malloc los valores iniciales son basura (valores aleatorios), mientras que en 
calloc los valores iniciales son ceros.
2. ¿Qué sucede si en realloc piden un tamaño más grande que el original? ¿y más
pequeño?
Si pide un tamaño más grande, el contenido original se mantiene 
y el espacio adicional queda como basura. Si pide un tamaño más pequeño, el contenido se pierde
cualquier dato que excede el limite.
3. ¿Qué pasa si olvidan llamar a free?
Provocamos una fuga de memoria, "memory leak", lo que la memoria empieza a consumir RAM innecesariamente
*/