#!/usr/bin/python3
#biblioteca.py
#
#Author: José Baños
#Date: 15/05/2023
#License: MIT

from xml.sax import default_parser_list

list_books = ['Dune', 'It', 'The Shining', 'Berserk']

def sort_books():
    list_books.sort()
    print ('La biblioteca queda con el siguiente orden:\n')
    print(list_books)
    print('\n')
#end def

def insert_book():
    book_name = input('Nombre del libro:\n')
    list_books.append(book_name)
    print('\n')
#end def

def delete_book():
    book_name = input('Nombre del libro:\n')
    list_books.remove(book_name)
    print('\n')
#end def

def look_bib():
    print (list_books)
    print('\n')
#end def

def show_menu():
    print ('Bienvenido a la biblioteca, puede realizar las siguientes operaciones.\n')
    print ('1 Agregar libro\n2 Eliminar libro\n3 Ordenar biblioteca\n4 Ver biblioteca\n5 Salir\n')
#end def
    
menu={
    1: insert_book,
    2: delete_book,
    3: sort_books,
    4: look_bib,
    5: exit
}

opcion = 0

while (opcion >= 0) :
    show_menu()
    opcion = int(input('Ingresa la opción:\n'))
    menu.get(opcion, default_parser_list)()
#end while



