def get_int(frase: str = 'Insira um número: ') -> int:
    while True:
        try:
            n = int(input(frase))
            
            # Bloco adicionado para casos de uso específicos
            # if n < 0 or n > 10: 
            #     raise ValueError
            break
        except ValueError:
            print("Número invalido!")

    return n


def get_number(frase: str = 'Insira um número: ') -> float:
    while True:
        try:
            n = float(input(frase))      
            break
        except ValueError:
            print("Número invalido!")
    
    return n
  
