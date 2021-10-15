separador = " "  # can be any character / string
lista = [1, 2, 3, 4, 5]
str_lista = [str(i) for i in lista]  # makes sure the contents of the list are strings
print(separador.join(str_lista))
