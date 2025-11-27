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
lista_diasDelMes=[31,28,31,30,31,30,31,31,30,31,30.31]

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
lista_numeros[5][0] = "Cinco"
print(lista_numeros[5])

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
print("valor actual {}".format(lista_diasDelMes[0]))
lista_diasDelMes[0] = 50
print("valor cambiado {}".format(lista_diasDelMes[0]))
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



