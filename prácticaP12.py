import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import random

times_insertion = 0
times_merge = 0
times_quick = 0

def insertionSort(n_lista):
    global times_insertion
    for index in range(1, len(n_lista)):
        times_insertion += 1
        actual = n_lista[index]
        posicion = index
        while(posicion > 0 and n_lista[posicion-1] > actual):
            times_insertion += 1
            n_lista[posicion] = n_lista[posicion-1]
            posicion = posicion-1
        n_lista[posicion] = actual
    return n_lista

def mergeSort(n_lista):
    global times_merge
    if len(n_lista) <= 1:
        return n_lista
    
    # Dividir la lista en mitades
    mitad = len(n_lista) // 2
    izquierda = n_lista[:mitad]
    derecha = n_lista[mitad:]
    
    # Llamadas recursivas para ordenar las mitades
    izquierda = mergeSort(izquierda)
    derecha = mergeSort(derecha)
    
    # Combinar las mitades ordenadas
    merged = merge(izquierda, derecha)
    return merged

def merge(izquierda, derecha):
    global times_merge
    merged = []
    i = j = 0
    
    while i < len(izquierda) and j < len(derecha):
        times_merge += 1
        if izquierda[i] <= derecha[j]:
            merged.append(izquierda[i])
            i += 1
        else:
            merged.append(derecha[j])
            j += 1
    
    while i < len(izquierda):
        merged.append(izquierda[i])
        i += 1
    
    while j < len(derecha):
        merged.append(derecha[j])
        j += 1
    
    return merged

def quickSort(n_lista):
    global times_quick
    if len(n_lista) <= 1:
        return n_lista
    
    pivot = n_lista[len(n_lista) // 2]
    less = []
    equal = []
    greater = []
    
    for element in n_lista:
        times_quick += 1
        if element < pivot:
            less.append(element)
        elif element == pivot:
            equal.append(element)
        else:
            greater.append(element)
    
    return quickSort(less) + equal + quickSort(greater)

TAM = 101
eje_x = list(range(1, TAM, 1))
eje_y_insertion = []
eje_y_merge = []
eje_y_quick = []
lista_variable = []

for num in eje_x:
    lista_variable = random.sample(range(0, 1000), num)
    print(lista_variable)
    
    times_insertion = 0
    sorted_insertion = insertionSort(lista_variable.copy())
    eje_y_insertion.append(times_insertion)
    
    times_merge = 0
    sorted_merge = mergeSort(lista_variable.copy())
    eje_y_merge.append(times_merge)
    
    times_quick = 0
    sorted_quick = quickSort(lista_variable.copy())
    eje_y_quick.append(times_quick)
    
print(sorted_insertion)
print(sorted_merge)
print(sorted_quick)

fig, ax = plt.subplots(facecolor='w', edgecolor='k')
ax.plot(eje_x, eje_y_insertion, marker='o', color='b', linestyle='None')
ax.plot(eje_x, eje_y_merge, marker='o', color='r', linestyle='None')
ax.plot(eje_x, eje_y_quick, marker='o', color='g', linestyle='None')

ax.set_xlabel("x")
ax.set_ylabel("y")
ax.grid(True)
ax.legend(["Insertion Sort", "Merge Sort", "Quick Sort"])

plt.title("Comparison of Sorting Algorithms")
plt.show()