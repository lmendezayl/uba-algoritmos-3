# Ejercicio 3
def izquierda_dominante(arr):
    # Complejidad: O(n log n)
    n = len(arr)
    if n == 2:
        return arr[0] > arr[1]
    medio = n // 2
    izq = arr[medio:]
    der = arr[:medio]
    return (sum(izq)<sum(der)) and izquierda_dominante(izq) and izquierda_dominante(der)

#######################################

# Ejercicio 4
####### PREGUNTAR #######
def indice_espejo(arr, izq=0, r=None):
    # Complejidad: O(log n)
    if r is None:
        r = len(arr)-1
    if izq > r:
        return False
    medio = (izq+r) // 2
    if arr[medio] == medio:
        return medio
    # la idea es buscar punto fijo, hasta que se cumpla que left > right
    # para eso, hacemos arr[e] - m para todo e en arr si no es verdad que arr[m] = m
    # con esto mantenemos posiciones relativas ya que en cada recursion len(arr) = n/2
    # o sea len(arr) = len(arr) - medio
    if arr[medio] < medio:
        arr = [e - medio for e in arr] # busco punto fijo arr[i] = i 
        return indice_espejo(arr, medio+1, r) 
    if arr[medio] > medio:
        arr = [e - medio for e in arr] # idem
        return indice_espejo(arr, izq, medio-1)
    # somehow, no funciona esto, tira maxrecursionlevel error
    
#######################################
    
# Ejercicio 5
def potencia(a,b):
    # Complejidad: O(log n)
    if b == 1:
        return a
    medio = b // 2
    if b % 2 == 0:
        return potencia(medio) * potencia(medio)
    else: 
        return potencia(medio) * potencia(medio) * a 

#######################################

# Ejercicio 6
def maximo_montana(arr, izq=0, der=None):
    if der is None:
        der = len(arr) - 1
    if izq == der:
        return izq 
    medio = (izq + der) // 2
    # solo hace falta mirar si hay alguien mas grande que yo
    # lo importante es ver EN QUE LADO esta ese numero mas grande
    # garantizado por la monotonia de las subsecuencias de arr
    
    # si la izquierda es mas grande, el máximo está en la mitad izquierda
    if arr[medio] < arr[medio - 1]:
        return maximo_montana(arr, izq, medio - 1)
    # si la derecha es mas grande, el máximo está en la mitad derecha
    elif arr[medio] < arr[medio + 1]: 
        return maximo_montana(arr, medio + 1, der)
    # si ninguno de los vecinos es mayor, estoy parado en el maximo
    else:
        return medio

#######################################

# Ejercicio 8
def max_subsecuencia(arr, izq=0, der=None):
    # buscamos tanto subarrays por izq, der y cruzados
    if der is None:
        der = len(arr) - 1
    # caso base, cuando llegamos aca retornamos para comparar con los otros maximos
    if izq == der:
        return arr[izq]
    medio = (izq + der) // 2
    # buscamos los maximos de cada mitad recursivamente
    max_izq = max_subsecuencia(arr, izq, medio)
    max_der = max_subsecuencia(arr, medio + 1, der)
    # para este caso, tenemos que ir desde el medio y mirar hacia la der e izq
    max_cruzado = suma_maxima_cruzada(arr, izq, medio, der)
    return max(max_izq, max_der, max_cruzado)

def suma_maxima_cruzada(arr, izq, medio, der):
    # lo que me garantiza que podemos ir desde el medio hacia atras y adelante
    # es que si esta cruzada, si o si contiene al ultimo de la mitad izquierda
    # y al primero de la mitad derecha, entonces basta con encontrar los maximos
    # de cada mitad desde el medio y luego sumarlos para retornar el maximo 
    # de la suma cruzada
    suma_izq = float('-inf')
    suma = 0
    for i in range(medio, izq - 1, -1): # i = medio, medio-1,..., l+1, l
        # comparamos suma con suma_izq, en primer iteracion siempre asigna suma
        suma += arr[i]
        suma_izq = max(suma_izq, suma)
    suma_der = float('-inf')
    suma = 0
    for i in range(medio + 1, der + 1):
        suma += arr[i]
        suma_der = max(suma_der, suma)
    return suma_izq + suma_der

#######################################

# Ejercicio 9

#######################################

# Ejercicio 11
# PREGUNTAR
# La duda es como puedo hcer para que la modificacion que estoy pensando funcione
# No se como hacer para que retorne k, pero que siga manteniendo el array 
# sobre el que estoy evaluando.
def desorden_sort(arr):
    if len(arr) <= 1:
        return arr
    medio = len(arr) // 2
    mitad_izq = desorden_sort(arr[:medio])
    mitad_der = desorden_sort(arr[medio:])
    return desordenados(mitad_izq, mitad_der)


def desordenados(izq, der):
    i = 0
    j = 0
    # Contador de parejas
    k = 0
    while i < len(izq) and j < len(der):
        # Si este par (i,j) esta desordenado
        if izq[i] > der[j]:
            k += 1
            i += 1
        else:
            j += 1
    # En mergesort aca concatenariamos la lista izq o der restante que no fue
    # clasificada, pero en este caso, no nos interesa, no es info de desorden.
    return k

