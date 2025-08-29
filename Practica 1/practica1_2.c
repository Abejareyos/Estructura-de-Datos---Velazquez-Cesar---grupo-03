#include <stdio.h>

int n;
int a[50];
int i;

int main(){

    //variables para suma, resta, promedio, maximo y minimo
int suma = 0; 
int resta = a[0];  
int maximo = a[0], min = a[0];
int idx_maximo = 0, idx_min = 0;


printf("Ingresa una cantidad (maximo 50): ");
    scanf("%d", &n);

printf("Ingrese %d numeros : \n", n );
for (i=0 ; i < n; i++){
    printf("Elementos %d : ", i);
    scanf("%d", &a[i]);
}

resta = a[0];  
maximo = min = a[0];

for (i = 0; i < n; i++) {
        suma += a[i];
        if (i > 0) 
            resta -= a[i];

        if (a[i] > maximo) {
            maximo = a[i];
            idx_maximo = i;
        }
        if (a[i] < min) {
            min = a[i];
            idx_min = i;
        }
    }

    float promedio = (float)suma / n;

    printf("Resultados del arreglo\n");
    printf("Suma: %d\n", suma);
    printf("Resta: %d\n", resta);
    printf("Promedio: %.6f\n", promedio);
    printf("Valor minimo: %d, posicion %d\n", min, idx_min);
    printf("Valor maximo: %d, posicion %d\n", maximo, idx_maximo);

    return 0;
}