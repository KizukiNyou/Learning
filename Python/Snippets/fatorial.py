def fat(n: int) -> int:
    if n not in memo:
        memo[n] = n * fat(n-1)
    return memo[n]


def fat_list(index: int) -> list:
    if index < 0:
        print('Não existe fatorial de número negativo!')
        return

    lista = []
    for numero in range(index+1):
        lista.append(fat(numero))

    return lista
  
