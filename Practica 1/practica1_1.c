#include <stdio.h>
int n;
int a[50];
int i;

int main(){
printf("Ingresa una cantidad (maximo 50): ");
    scanf("%d", &n);

while(n <=0 || n>50 ){
    printf("Tu valor es invalido, porfavor ingrese otro:");
    scanf("%d", &n);
}
printf("Ingrese %d numeros : \n", n );
for (int i=0 ; i < n; i++){
    printf("Elementos %d : ", i);
    scanf("%d", &a[i]);
}
printf("\n Los elementos del arraya son: \n");
    for (int i=0 ; i<n ; i++){
        printf("%d", a[i]);
    }

    printf("\n");
    return 0;
}