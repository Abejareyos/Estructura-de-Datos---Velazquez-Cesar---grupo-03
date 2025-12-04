
from string import ascii_letters, digits
from itertools import product
from time import time
#  ALGORITMO 1: FUERZA BRUTA
#  Para contraseñas de 4, 8 y 10 caracteres
caracteres = ascii_letters + digits
def fuerza_bruta(contrasena): # contrasena: de tipo str (4, 8 o 10 caracteres)
    tam = len(contrasena)

    if tam not in (4, 8, 10): # Si la contraena no es de 4,8 o 10 caracteres el programa muestra un mensaje y termina
        print("La contrasena debe ser de 4, 8 o 10 caracteres")
        return
    
    print("\n ### Buscando contrasena por fuerza bruta ### \n")
    print(" Longitud:", tam)
    t0 = time()

    for combinacion in product(caracteres, repeat=tam): # Enumera todas las combinaciones posibles, luego une los caracteres y compara con la contrasena a buscar
        prueba = "".join(combinacion)
        if prueba == contrasena: # Si la combinacion generada es igual a la contrasena, muestra el resultado y el tiempo de ejecucion
            print("Contrasena encontrada exitosamente: {}".format(prueba))
            print("Tiempo de ejecucion: {:.6f} segundos\n".format(time() - t0))
            print("Fin de la busqueda \n")
            return

def cambio(cantidad, denominaciones): # Entradas: cantidad (int), denominaciones (lista de int)
    print("\n### Cambio de monedas ###\n")
    print("Cantidad a cambiar:", cantidad)
    print("Denominaciones disponibles:", denominaciones) 
    resultado = [] # Lista donde se guardan las denominaciones usadas y su cantidad
    while cantidad > 0: # Mientras quede cantidad por cambiar, se revisan las denominaciones
        if cantidad >= denominaciones[0]: # Si la cantidad es mayor o igual a la denominacion actual, se calcula cuantas monedas de esa denominacion se pueden usar
            num = cantidad // denominaciones[0]
            cantidad -= num * denominaciones[0]
            resultado.append([denominaciones[0], num])
        denominaciones = denominaciones[1:]   # se elimina la primera denominacion, para pasar a la siguiente
    return resultado

def insertionSort(lista): # Entrada: lista de numeros desordenados
    print("\n ### Insertion sort ### \n")

    for index in range(1, len(lista)): # Recorre la lista desde el segundo elemento hasta el final
        actual = lista[index]
        posicion = index

        print("\nValor a ordenar:", actual) # Muestra el valor que se va a ordenar en esta iteracion

        while posicion > 0 and lista[posicion - 1] > actual: # Compara el valor actual con los elementos anteriores
            lista[posicion] = lista[posicion - 1]
            posicion -= 1
            lista[posicion] = actual
            print(lista)

        print(lista)

    print("\nLista ordenada:", lista) # Muestra la lista ordenada
    return lista

if __name__ == "__main__": # Programa principal, donde se llaman a las funciones de prueba y se muestran los resultados

    print("Estrategias para la construcción de Algoritmos I")
    print("\n FUERZA BRUTA")
    fuerza_bruta("z3uS")   # Prueba con contrasena de 4 caracteres
    print("\n PRUEBAS GREEDY (Cambio de monedas)\n") # Pruebas con diferentes cantidades y denominaciones
    print("Caso optimo:")

    print(cambio(1000, [500, 200, 100, 50, 20, 5, 1]))
    print(cambio(500,  [500, 200, 100, 50, 20, 5, 1]))
    print(cambio(300,  [50, 20, 5, 1]))
    print(cambio(200,  [5]))
    print(cambio(98,   [50, 20, 5, 1]))
    
    print("\nCaso no optimo:") # Prueba con un caso donde la estrategia greedy no da la solucion optima
    print(cambio(98, [5, 20, 1, 50])) # La solucion optima es 1x50, 2x20, 1x5, 3x1 (7 monedas), pero la estrategia greedy da 1x5, 4x20, 3x1 (8 monedas)

    lista = [21, 10, 0, 11, 9, 24, 20, 14, 1] # Prueba del algoritmo de ordenamiento por insercion
    print("\n INSERTION SORT")
    print("Lista desordenada:", lista)
    insertionSort(lista)
