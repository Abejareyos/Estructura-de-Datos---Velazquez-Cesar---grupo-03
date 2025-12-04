#Inicializando variables
x = 10 
print(x)

cadena = "Hola, Mundo"
print(cadena)

#Asigana un mismo valor a tres valores
x = y = z = 10
print(x, y, z)

#La funcion type() permite conocer el tipo de una variable
type(x)
type(cadena)

#Cambiar los valores de las variables y el tipo se cambia automaticamente
x = "Hola mundo"
cadena = 10
type(x) 
type(cadena)

#Inicializar cadenas
cadena1 = 'Hola'
cadena2 = "Mundo"
print(cadena1)
print(cadena2)
concat_cadenas = cadena1 + cadena2 #Concatenacion de cadenas
print(concat_cadenas)

#Para concatenar un numero y una cadena se debe usar la funcion str()
num_cadena = concat_cadenas + ' ' + str(3)
print(num_cadena)

#El valor de la variable se va a imprimir en el lugar donde se encuentre {} en la cadena
num_cadena = "{} {} {}".format(cadena1, cadena2, 3)
print(num_cadena)

#Cuando se agrega un numero dentro de {#}, el valor la variable que se encuentra en esa posicion
num_cadena = "Cambiando el roden: {1} {2} {0}".format(cadena1, cadena2, 3)
print(num_cadena)

#Para el exponente se puede utilizar asterisco
print(1 + 5 )
print(6 + 3)
print(10 - 4)
print(100 / 50)
print(10%2)
print(((20*3)+(10+1))/10)
print(2**2)

#Comparacion: >, <, >=, <=, ==
print(7<5) #Falso
print(7>5) #Verdadero
print((11*3)+2 == 36 -1) #Verdadero
print("curso" != "CuRsO") #Verdadero

#Declaracion de una lista simple
lista_diasDelMes=[31,28,31,30,31,30,31,31,30,31,30,31]
print(lista_diasDelMes) #Imprime lista completa
print(lista_diasDelMes[0]) #Imprime elemento 1
print(lista_diasDelMes[6]) #Imprime elemento 7
print(lista_diasDelMes[11]) #Imprime elemento 12

#Declaracion de listas anidadas
lista_numeros=['cero',0],['uno',1,'UNO'],['dos',2,'DOS']
print(lista_numeros) #Imprime lista completa
print(lista_numeros[0]) #Imprime elemento 0 
print(lista_numeros[1]) #Imprime elemento 1

print(lista_numeros[2][0]) #Imprime elemento 2 del elemento 1
print(lista_numeros[2][1])

print(lista_numeros[1][0])
print(lista_numeros[1][1])
print(lista_numeros[1][2])

#Se cambio el valor de uno de los elementos de la lista
#lista_numeros[5][0] = 'Cinco'
#print(lista_numeros[5])

#Declaracion de una tupla
tupla_diasDelMes=(31,28,31,30,31,30,31,31,30,31,30,31)
print(tupla_diasDelMes) #Imprime tupla completa
print(tupla_diasDelMes[0]) #Imprime elemento 1
print(tupla_diasDelMes[3]) #Imprime elemento 4
print(tupla_diasDelMes[1]) #Imprime elemento 2

#Declaracion de tuplas anidadas
tupla_numeros=('cero',0),('uno',1,'UNO'),('dos',2),('tres',3),('cuatro',4),('X',5)
print(tupla_numeros) #Imprime tupla completa
print(tupla_numeros[0]) #Imprime elemento 0
print(tupla_numeros[1]) #Imprime elemento 1

print(tupla_numeros[2][0]) #Imprime elemento 2 del elemento 1
print(tupla_numeros[2][1])

print(tupla_numeros[1][0])
print(tupla_numeros[1][1])
print(tupla_numeros[1][2])

#Probando la mutabilidad de las listas vs la no mutabilidad de las tuplas
print("valor_actual {}".format(lista_diasDelMes[0]))
lista_diasDelMes[0] = 50
print("valor_cambiado {}".format(lista_diasDelMes[0]))
# tupla_diasDelMes[0] = 50 Esta asignacion mandaria un error porque las tuplas no se pueden cambiar su valor
#Se debe importat la libreria para hacer uso de namedtuple
from collections import namedtuple
#Se crea la tupla con nombre
#El primer argumento es el nombre de la tupla, mientas que el segundo argumento son los campos
#p es la referencia a la tupla
planeta = namedtuple('planeta', ['nombre', 'numero'])
#Se crea una instancia de la tupla
planetal = planeta('Mercurio', 1)
print(planetal)
#Se crea el planeta 2
planeta2 = planeta('Venus', 2)
#Se immprimen los valores de los campos 
#Usando la referencia se llama a cada uno de sus campos
print(planetal.nombre, planetal.numero)
print(planeta2[0],planeta2[1])
print('Campos de la tupla: {}'.format(planeta._fields))

#Creando un diccionario
elementos = { 'hidrogeno': 1, 'helio': 2, 'carbon': 6 }

#El momento de la impresión, pueden aparecer en diferente orden del introducido
print(elementos)
print(elementos['hidrogeno'])

#Se puede agregar elementos al diccionario
elementos['litio'] = 3
print(elementos) #Imprime todos los elementos, ahora que los elementos no están ordenados

#Creando un diccionario con valores
peso_elementos = { 'hidrogeno': {'numero': 1, 'peso': 1.00794},
                   'helio': {'numero': 2, 'peso': 4.002602},
                   'carbon': {'numero': 6, 'peso': 12.0107} }
print(peso_elementos)
print(peso_elementos['hidrogeno'])
print(peso_elementos['hidrogeno']['peso'])

#Añadiendo el valor de un elemento
peso_elementos['hidrogeno']['peso'] = 1.00786
print(peso_elementos['hidrogeno'])

#Creando una llave
peso_elementos['hidrogeno']['gas noble'] = True
print(peso_elementos['hidrogeno'])

#Recorrer todos los elementos del diccionario
for llave in peso_elementos:
    print(llave, peso_elementos[llave]['numero'], peso_elementos[llave]['peso'])

#Las funciones pueden recibir n número de parámetros, no se necesita indicar el tipo
def imprime_nombre(nombre):
    print('hola ' + nombre)

#Llamada a la función
imprime_nombre('JJ')

#Definiendo una función que regrese el cuadrado de un número
def cuadrado(x):
    return x * x

#La función format() sirve para convertir los parámetros que recibe, en cadenas; decora valores
def imprime_valores(val1, val2, val3):
    print('1: {} 2: {} 3: {}'.format(val1, val2, val3))

#Función con un valor por defecto
def cuadrado_def(x=2):
    return x * x

print(cuadrado_def())

#Variables globales
global_var = 'Global'
print(global_var)

def imprime_global():
    print(global_var)

imprime_global()

#Se crea una variable local que tiene el mismo nombre que la variable global
def funcion_vg1():
    vg = 'local'
    print(vg)


#Para resolver el problema anterior y especificar que no quiero hacer uso de la
#palabra reservada global
def funcion_vg():
    global vg
    vg = 'Local'
    print(vg)

funcion_vg()
print(vg)

#Declaraciones if-else
def elementoMayor(param1, param2):
    if param1 > param2:
        print(param1)
    else:
        print(param2)

#Declaraciones if-elif-else
def numero(n):
    if n == 1:
        print('n es 1')
    elif n == 2:
        print('n es 2')
    else:
        print('No hay opción')

#Ciclo while
i = 0
while i < 5:
    print(i)
    i += 1

#Iteración en listas
for n in [1,2,3,4,5]:
    print(n)

for n in range(5):
    print(n)

for n in range(-3,2):
    print(n)

for n in ["uno", "dos", "tres", "cuatro"]:
    print(n)

#Iteración en diccionarios
elementos = { 'hidrogeno': 1, 'helio': 2, 'carbon': 6 }
for llave, valor in elementos.items():
    print(llave, valor)

#Uso de librerías
import math
a = math.cos(math.pi)
print(a)

from math import pi
b = math.cos(pi)
print(b)

#Gráfica con matplotlib
import matplotlib.pyplot as plt  
import numpy as np
x = np.arange(-10, 10, 0.5)
y = x**2
plt.plot(x, y, 'ro')
plt.title('Puntos')
plt.show()



