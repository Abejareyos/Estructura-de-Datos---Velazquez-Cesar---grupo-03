#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Estructura de datos para almacenar la informacion de una pelicula
struct pelicula {
    char nombre[50];
    char genero[50];
    int  anio;
    int  numDirectores;
    char directores[05][50]; 
};

void guardarPeliculas(struct pelicula *arreglo, int n);
void buscarPeliculas();
//* INICIO DEL PROGRAMA *//
int main() {
    int n;
    printf("\n####### Videoteca #######\n");
    printf("Cuantas peliculas deseas guardar? \n");
    printf("Si no es asi, introduce 0\n");
    scanf("%d", &n);
    getchar();
//Reserva memoria dinamica para n peliculas
    struct pelicula *videoteca = malloc(n * sizeof(struct pelicula));
//Lee los datos de las peliculas
    for (int i = 0; i < n; i++) {
        printf("\n####### Pelicula %d #######\n", i + 1);
        printf("Titulo: ");
        fgets(videoteca[i].nombre, 50, stdin);
        videoteca[i].nombre[strcspn(videoteca[i].nombre, "\n")] = 0;

        printf("Genero de la pelicula (accion, terror, romanticas, fantasia): ");
        fgets(videoteca[i].genero, 20, stdin);
        videoteca[i].genero[strcspn(videoteca[i].genero, "\n")] = 0;

        printf("Fecha de lanzamiento: ");
        scanf("%d", &videoteca[i].anio);
        getchar();

        printf("Cuantos directores tiene ?: ");
        scanf("%d", &videoteca[i].numDirectores);
        getchar();

        for (int j = 0; j < videoteca[i].numDirectores; j++) {
            printf("Director %d: ", j + 1);
            fgets(videoteca[i].directores[j], 50, stdin); //lee la cadena con espacios
            videoteca[i].directores[j][strcspn(videoteca[i].directores[j], "\n")] = 0; //elimina el salto de linea
        }
    }
//Guarda las peliculas en archivos segun su genero
    guardarPeliculas(videoteca, n);

    printf("\nQuieres buscar una pelicula (1=Si / 0=No): ");
    int opcion;
    scanf("%d", &opcion);
    getchar();
//Si el usuario desea buscar, llama a la funcion buscarPeliculas
    if (opcion == 1) {
        buscarPeliculas();
    }

    free(videoteca); //libera la memoria
    return 0;
}

void guardarPeliculas(struct pelicula *arreglo, int n) {
    for (int i = 0; i < n; i++) {
        char archivo[30];
        snprintf(archivo, sizeof(archivo), "%s.txt", arreglo[i].genero);

        FILE *f = fopen(archivo, "a");
        if (!f) {
            printf("Error al abrir el archivo %s\n", archivo);
            continue;
        }

        fprintf(f, "Titulo: %s\n", arreglo[i].nombre);
        fprintf(f, "Genero: %s\n", arreglo[i].genero);
        fprintf(f, "Fecha de lanzamiento: %d\n", arreglo[i].anio);
        fprintf(f, "Directores:\n");
        for (int j = 0; j < arreglo[i].numDirectores; j++) {
            fprintf(f, " - %s\n", arreglo[i].directores[j]);
        }
        fprintf(f, "----------------------\n");
        fclose(f);
    }
}


void buscarPeliculas() {
    char titulo[50], director[50];
    int anio;
    int usarTitulo, usarDirector, usarAnio;
    printf("\n--- Buscar Pelicula ---\n");
    printf("\nOpciones de busqueda:\n");
    

    printf("Quieres buscar por titulo (1=Si / 0=No): ");
    scanf("%d", &usarTitulo); getchar();
    if (usarTitulo) {
        printf("Titulo: ");
        fgets(titulo, 50, stdin);
        titulo[strcspn(titulo, "\n")] = 0;
    }

    printf("Deseas buscar por director (1=Si / 0=No): ");
    scanf("%d", &usarDirector); getchar();
    if (usarDirector) {
        printf("Introduce director: ");
        fgets(director, 50, stdin);
        director[strcspn(director, "\n")] = 0;
    }

    printf("Quieres buscar por su fecha de lanzamiento (1=Si / 0=No): ");
    scanf("%d", &usarAnio); getchar();
    if (usarAnio) {
        printf("Introduce anio: ");
        scanf("%d", &anio); getchar();
    }

   //Array con los nombres de los archivos de cada genero
    char *generos[] = {"accion", "terror", "romanticas", "fantasia"};

    for (int g = 0; g < 4; g++) {
        char archivo[30];
        snprintf(archivo, sizeof(archivo), "%s.txt", generos[g]);
        FILE *f = fopen(archivo, "r");
        if (!f) continue;

        char linea[100];
        char nombre[50] = "", genero[20] = "", dirTemp[50] = "";
        int year = 0;

        while (fgets(linea, sizeof(linea), f)) {
            if (strncmp(linea, "Titulo:", 7) == 0) {
                sscanf(linea, "Titulo: %[^\n]", nombre);
            } else if (strncmp(linea, "Genero:", 7) == 0) {
                sscanf(linea, "Genero: %[^\n]", genero);
            } else if (strncmp(linea, "Fecha", 5) == 0) {
                sscanf(linea, "Fecha de lanzamiento: %d", &year);
            } else if (linea[0] == ' ' && linea[1] == '-') {
                sscanf(linea, " - %[^\n]", dirTemp);

                
                int match = 0;
                if (usarTitulo && strstr(nombre, titulo)) match = 1;
                if (usarDirector && strstr(dirTemp, director)) match = 1;
                if (usarAnio && (year == anio)) match = 1;

                if (match) {
                    printf("\n--- Pelicula encontrada ---\n");
                    printf("Titulo: %s\n", nombre);
                    printf("Genero: %s\n", genero);
                    printf("Fecha de lanzamiento: %d\n", year);
                    printf("Director: %s\n", dirTemp);
                }
            }
        }
        fclose(f);
    }
}
