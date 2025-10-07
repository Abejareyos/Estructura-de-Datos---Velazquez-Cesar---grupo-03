#include <stdio.h>
#include <stdlib.h>

int main() {
    // n: numero inicial de estudiantes
    // agregar: numero de estudiantes a agregar
    // nuevo_tamano: nuevo tamaño del arreglo
    int n, agregar, nuevo_tamano; 
    float *calificaciones = NULL;
    float suma = 0, promedio; // Variables para el promedio
    char opcion;

    printf("=== Registro de calificaciones ===\n");
    printf("Cuantos estudiantes desea registrar? "); //Sele pregunta al usuario el numero de estudiantes
    scanf("%d", &n);

    calificaciones = (float *) malloc(n * sizeof(float)); //Se reserva memoria para n estudiantes
    if (calificaciones == NULL) {
        printf("Error. \n"); //El sistema no pudo asignar memoria
        return 1;
    }

    for (int i = 0; i < n; i++) { //Se piden las calificaciones de los estudiantes
        printf("Calificacion del estudiante %d: ", i + 1);
        scanf("%f", &calificaciones[i]); //Se almacenan en el arreglo
        suma += calificaciones[i]; //Se suma para el promedio
    }

    promedio = suma / n; // Formula del promedio
    // Se muestran las calificaciones y el promedio
    printf("\nCalificaciones registradas correctamente:\n");
    for (int i = 0; i < n; i++) {
        printf("Estudiante %d: %.2f\n", i + 1, calificaciones[i]); 
    }
    printf("Promedio: %.2f\n", promedio); 
    //Sele da la opcion al usuario de agregar mas estudiantes
    printf("\nDesea registrar mas estudiantes? (s/n): ");
    scanf(" %c", &opcion); 

    while (opcion == 's' || opcion == 'S') {
        printf("Cuantos estudiantes quiere agregar? ");
        scanf("%d", &agregar); //Se registra el numero de estudiantes nuevos para agregar
        suma = 0; //Se reinicia la suma para el nuevo promedio

        nuevo_tamano = n + agregar; //Se calcula el nuevo tamaño del arreglo con los nuevos estudiantes
        //Se redimensiona el arreglo con realloc

        calificaciones = (float *) realloc(calificaciones, nuevo_tamano * sizeof(float)); 
        if (calificaciones == NULL) { 
            printf("Error.\n"); // El sistma no pudo asignar memoria
            return 1; // Termina el programa
        }
        //Se piden las calificaciones de los nuevos estudiantes
        for (int i = n; i < nuevo_tamano; i++) { 
            printf("Calificacion del nuevo estudiante %d: ", i + 1);
            scanf("%f", &calificaciones[i]); 
            suma += calificaciones[i];
        }

        // Actualiza el tamano y promedio
        n = nuevo_tamano;
        promedio = suma / n;

        // Muestra los resultados actualizados
        printf("\n== Calificaciones actualizadas ==\n");
        for (int i = 0; i < n; i++) { // Recorre todo el arreglo
            printf("Estudiante %d: %.2f\n", i + 1, calificaciones[i]); // Imprime todas las calificaciones
        }
        printf("Nuevo promedio: %.2f\n", promedio); // Imprime el nuevo promedio agregando a los nuevos estudiantes

        // Volver a preguntar al usuario si desea agregar mas estudiantes
        printf("\nDesea agregar aun mas estudiantes? (s/n): ");
        scanf(" %c", &opcion);
    }
    // Libera la memoria al finalizar el programa
    free(calificaciones);
    printf("\nMemoria liberada. El programa fue ejecutado correctamente.\n");
    printf("Que tenga un buen dia.\n");

    return 0;
}
