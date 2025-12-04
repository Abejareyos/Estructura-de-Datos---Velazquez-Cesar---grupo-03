from __future__ import annotations # Para anotaciones de tipo diferidas
from typing import List, Dict
import pickle

def fibonacci_iterativo_v1(numero: int) -> int: # Variante básica iterativa
    if numero <= 1: # Si el numero es menor o igual a 1, no es valido
        raise ValueError("El numero debe ser >= 1 ") # Convención: F(1)=0, F(2)=1, F(3)=1, ...
    if numero == 1: # Si el numero es 1, retorna a 0
        return 0
    if numero == 2: # Si el numero es 2, retorna a 1, porque F(2)=1
        return 1

    f1 = 0
    f2 = 1
    tmp = 0
    for _ in range(1, numero - 1): # Itera desde 1 hasta el numero-2
        tmp = f1 + f2
        f1 = f2
        f2 = tmp
    return f2

def fibonacci_iterativo_v2(numero: int) -> int: # Variante con asignacion paralela
    if numero <= 1: # Si el numero es menor o igual a 1, no es valido
        raise ValueError("El numero debe ser >= 1 ") # Convención: F(1)=0, F(2)=1, F(3)=1, ...
    if numero == 1: # Si el numero es 1, retorna a 0
        return 0
    if numero == 2: # Si el numero es 2, retorna a 1, porque F(2)=1
        return 1

    f1, f2 = 0, 1
    for _ in range(1, numero - 1): # Itera desde 1 hasta el numero-2
        f1, f2 = f2, f1 + f2  # asignación paralela
    return f2

def fibonacci_bottom_up(numero: int, verbose: bool = True) -> int: # Variante Bottom-up

    if numero <= 1: # Si el numero es menor o igual a 1, no es valido
        raise ValueError("El numero debe ser >= 1") # Convención: F(1)=0, F(2)=1, F(3)=1, ...
    f_parciales: List[int] = [0, 1, 1]  # soluciones conocidas F(1), F(2), F(3)
    while len(f_parciales) < numero:
        f_parciales.append(f_parciales[-1] + f_parciales[-2])
        if verbose: # Imprime los valores parciales si verbose es True
            print(f_parciales)
    return f_parciales[numero - 1]

memoria: Dict[int, int] = {1: 0, 2: 1, 3: 1}

def fibonacci_top_down(numero: int) -> int:
    if numero in memoria: # Si el numero ya está en la memoria, retorna su valor
        return memoria[numero]
    f = fibonacci_iterativo_v2(numero - 1) + fibonacci_iterativo_v2(numero - 2)
    memoria[numero] = f # Guarda el resultado en la memoria
    return memoria[numero]

def guardar_memoria(ruta: str = "memoria.p") -> None: # Guarda la memoria en un archivo usando pickle
    with open(ruta, "wb") as archivo: # Abre el archivo en modo escritura binaria
        pickle.dump(memoria, archivo)

def cargar_memoria(ruta: str = "memoria.p") -> Dict[int, int]: # Carga la memoria desde un archivo usando pickle
    with open(ruta, "rb") as archivo:
        m = pickle.load(archivo)
    return m

def quicksort(lista: List[int], debug: bool = True) -> None: # Implementa el QuickSort
    if not lista:   
        return  
    quicksort_aux(lista, 0, len(lista) - 1, debug)

def quicksort_aux(lista: List[int], inicio: int, fin: int, debug: bool) -> None: # Funcion auxiliar recursiva
    if inicio >= fin: # Si el subarreglo tiene uno o ningún elemento
        return
    pivote = particion(lista, inicio, fin, debug)
    quicksort_aux(lista, inicio, pivote - 1, debug)
    quicksort_aux(lista, pivote + 1, fin, debug)

def particion(lista: List[int], inicio: int, fin: int, debug: bool) -> int: # Funcion de particion, retorna el indice del pivote
    pivote = lista[inicio]
    izquierda = inicio + 1
    derecha = fin

    if debug: #Si debug es True, imprime el estado inicial de la lista y el pivote
        print("\nPivote: {}".format(pivote))
        print("Estado inicial:", lista)

    bandera = False # Bandera para controlar el ciclo
    while not bandera: # Mientras la bandera sea False, realiza el proceso de particion
        while izquierda <= derecha and lista[izquierda] <= pivote:
            izquierda += 1
        while derecha >= izquierda and lista[derecha] >= pivote:
            derecha -= 1
        if derecha < izquierda: # Si los indices se cruzan, termina el ciclo
            bandera = True
        else: # Si no se han cruzado, intercambia los elementos en los indices izquierda y derecha
            temp = lista[izquierda]
            lista[izquierda] = lista[derecha]
            lista[derecha] = temp
            if debug: # Si debug es True, imprime el estado de la lista tras el intercambio
                print("Intercambio ->", lista)
    temp = lista[inicio]
    lista[inicio] = lista[derecha]
    lista[derecha] = temp

    if debug:
        print("Lista tras colocar pivote:", lista)
    return derecha

if __name__ == "__main__": # Modulo principal 
    print("Pactica 12")
    print("\n### Fibonacci iterativo v1 ###")
    print(fibonacci_iterativo_v1(6))  # esperado: 5

    print("\n### Fibonacci iterativo v2 ###")
    print(fibonacci_iterativo_v2(6))  # esperado: 5

    print("\n### Fibonacci Bottom-up ###")
    resultado_bottom_up = fibonacci_bottom_up(5, verbose=True)  # imprime parciales, esperado: 3
    print(resultado_bottom_up)  # esperado: 3

    print("\n### Fibonacci Top-Down con memoizacion ###")
    print(fibonacci_top_down(12))  # esperado: 89
    print("memoria")
    print(memoria)

    print("\nCalculando F(8) usando Top-Down ( reutiliza la memoria si existe):")
    print(fibonacci_top_down(8))  # esperado: 13
    print("memoria")
    print(memoria) # Imprime la memoria actual

    print("\n ### Guardando y cargando memoria con pickle ### \n")
    guardar_memoria("memoria.p")
    memoria_de_archivo = cargar_memoria("memoria.p") # Carga la memoria desde el archivo
    print("memoria")
    print(memoria) # Imprime la memoria actual
    print("\nmemoria_de_archivo")
    print(memoria_de_archivo) # Imprime la memoria cargada desde el archivo

    print("\n### QuickSort (Divide & Conquer) ###")
    Lista = [21, 10, 0, 1, 5, 9, 20, 14, 1]
    print("Lista inicial:", Lista)
    quicksort(Lista, debug=True) # Ordena la lista con debug activado
    print("Lista ordenada:", Lista)