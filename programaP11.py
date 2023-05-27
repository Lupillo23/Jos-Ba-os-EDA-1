from xml.sax import default_parser_list

def binario(n):
    if n <= 0:
        return ''
    else:
       return binario(n // 2) + str(n % 2)
#end def

def recur_fibo(n):
    if n<=1:
        return n
    else:
        return(recur_fibo(n-1) + recur_fibo(n-2))
#end def

def print_bin():
    n = int(input("\nIngrese un número decimal\n"))
    if n < 0:
        print("Ingrese un número positivo!!\n")
    else:
        bin = binario(n)
        print("El número proporcionado es equivalente a :", bin)
#end def

def print_fibo():
    nterms = int(input("\nIngrese un entero positivo\n"))
    if nterms <= 0:
        print("Parámetro inválido!!\n")
    else:
        print("\nSecuencia fibonacci:")
    for i in range(nterms -1, -1, -1):
        print(recur_fibo(i))
#end else

def show_menu():
    print ('\nBienvenido, puede realizar las siguientes operaciones.\n')
    print ('1 Conversión de bases\n2 Serie Fibonacci\n3 Salir')
#end def

menu={
    1: print_bin,
    2: print_fibo,
    3: exit
}

opcion = 0

while (opcion >= 0) :
    show_menu()
    opcion = int(input('\nIngresa la opción:\n'))
    menu.get(opcion, default_parser_list)()
#end while
