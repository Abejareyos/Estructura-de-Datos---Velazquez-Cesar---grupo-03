
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char* add_str(const char* a, const char* b) { // Suma dos numeros representados como cadenas
    size_t la = strlen(a), lb = strlen(b);
    size_t max = (la > lb ? la : lb); // Longitud maxima de las dos cadenas
    char* out = (char*)malloc(max + 2); // +1 para posible acarreo, +1 para el terminador nulo
    if (!out) { fprintf(stderr, "Memoria insuficiente\n"); exit(1); } // Si no hay memoria disponible, tenemos un error

    int carry = 0; size_t ia = la, ib = lb; size_t io = 0; // Indices para a, b y out
    while (ia > 0 || ib > 0 || carry) {  // Mientras queden digitos o acarreo, seguimos sumando
        int da = (ia > 0 ? a[--ia] - '0' : 0); // Digito actual de a (o 0 si ya no quedan)
        int db = (ib > 0 ? b[--ib] - '0' : 0); // Digito actual de b (o 0 si ya no quedan)
        int s = da + db + carry; // Suma de los digitos y el acarreo
        out[io++] = (char)('0' + (s % 10));
        carry = s / 10;
    }
    for (size_t i = 0; i < io/2; ++i) { // Invertimos la cadena resultante
        char tmp = out[i]; // Intercambiamos out[i] y out[io-1-i]
        out[i] = out[io-1-i];
        out[io-1-i] = tmp;
    }
    out[io] = '\0';
    return out; // Retornamos la cadena resultante
}

static char** memo = NULL; // La memorizacion para los Fibonacci, inicia vacia
static int memo_size = 0; // Tamaño actual de la memorizacion

static char* fib_rec(int n) { // Fibonacci recursivo con memorizacion
    if (n < memo_size && memo[n] != NULL) return memo[n]; // Si la solucion ya esta memorizada, la retornamos
    char* res;
    if (n == 0) { // Si es F(0), retornamos "0"
        res = strdup("0");
    } else if (n == 1) { // Si es F(1), retornamos "1"
        res = strdup("1");
    } else { // Si no, calculamos F(n-1) + F(n-2)
        char* a = fib_rec(n-1);
        char* b = fib_rec(n-2);

        res = add_str(a, b);
    }

    if (n >= memo_size) { // Si no hay espacio en la memorizacion, la ampliamos una vez 
        int new_size = n + 1; // Nuevo tamaño necesario
        char** new_memo = (char**)calloc(new_size, sizeof(char*));
        if (!new_memo) { fprintf(stderr, "Memoria insuficiente\n"); exit(1); } // Si no hay memoria disponible, tenemos un error y se muestra un mensaje de error

        for (int i = 0; i < memo_size; ++i) new_memo[i] = memo[i]; // Copiamos los valores anteriores
        free(memo); // Liberamos la memoria antigua
        memo = new_memo;
        memo_size = new_size;
    }
    memo[n] = res;
    return res; // Retornamos el resultado calculado
}

int main(void) { // Menu del programa

    printf("\n ### Calculadora de Fibonacci ### \n");
    printf("Posiciones 7, 21, 40, 71 y 94 \n");
    memo_size = 2;
    memo = (char**)calloc(memo_size, sizeof(char*)); // Inicializamos la memorizacion con espacio para F(0) y F(1)
    if (!memo) { fprintf(stderr, "Memoria insuficiente\n"); return 1; } // Si no hay memoria disponible, tenemos un error
    memo[0] = strdup("0");
    memo[1] = strdup("1");

    int posiciones[] = {7, 21, 40, 71, 94}; // Posiciones a calcular mostradas en el enunciado
    int npos = sizeof(posiciones)/sizeof(posiciones[0]); // Numero de posiciones a calcular

    for (int i = 0; i < npos; ++i) { // Calculamos y mostramos cada Fibonacci
        int n = posiciones[i];
        char* fn = fib_rec(n);
        printf("F(%d) = %s\n", n, fn);
    }

    for (int i = 0; i < memo_size; ++i) free(memo[i]);
    free(memo);
    return 0;
}