#include <stdio.h>
int n;
int a[50];
int i;

int main(){
int temp;

printf("Ingresa una cantidad (maximo 50): ");
    scanf("%d", &n);

    printf("Ingrese %d numeros : \n", n );
for (int i=0 ; i < n; i++){
    printf("Elementos %d : ", i);
    scanf("%d", &a[i]);
}

printf("Valor del vector: \n");
    for (i=0 ; i<n ; i++){
        printf("%d", a[i]);
    }

for (int i = 0, j = n - 1; i < j; i++, j--) {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    printf("Vector invertido");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    printf("\n");
    return 0;
}