# WITHOUT LIST COMPREHENSION
def gera_matriz(tipo: int = 1, tamanho: tuple = (3, 3)) -> list:
    # Retorna uma matriz ixj baseada no tipo desejado
    # Tamanho = (i, j) ou (linhas, colunas)

    # Input inválido
    for num in tamanho:
        if num < 1:
            return []

    matriz = []

    # Tipo 1 (default): sequencia de 1 até i*j
    if tipo == 1:
        for i in range(tamanho[0]):
            linha = []
            for j in range(tamanho[1]):
                linha.append(i*(tamanho[1]) + j + 1)
            matriz.append(linha)

    # Tipo 2: matriz identidade
    # Caso o input de tamanho tenha valores (i,j) diferentes entre si,
    # a função retorna a fatia da matriz identidade correspondente ao tamanho pedido
    if tipo == 2:
        for i in range(tamanho[0]):
            linha = [0] * tamanho[1]  # Cria uma linha cheia de zeros
            if i < tamanho[1]:
                linha[i] = 1  # Muda o valor da diagonal principal para 1, quando possivel
            matriz.append(linha)

    # Tipo 3: valores aleatorios dentro do intervalo [1, i*j]
    if tipo == 3:
        for i in range(tamanho[0]):
            linha = []
            for j in range(tamanho[1]):
                linha.append(randint(1, tamanho[0]*tamanho[1]))
            matriz.append(linha)

    return matriz


# WITH LIST COMPREHENSION
def gera_matriz(tipo: int = 1, tamanho: tuple = (3, 3)) -> list:
    # Retorna uma matriz ixj baseada no tipo desejado
    # Tamanho = (i, j) ou (linhas, colunas)

    # Input inválido
    for num in tamanho:
        if num < 1:
            return []
    
    matriz = []
    
    # Tipo 1: sequencia de 1 até i*j
    if tipo == 1:
        matriz = [[(i*tamanho[1] + j + 1) for j in range(tamanho[1])] for i in range(tamanho[0])]

    # Tipo 2: matriz identidade
    # Caso o input de tamanho tenha valores (i,j) diferentes entre si,
    # a função retorna a fatia da matriz identidade correspondente ao tamanho pedido
    elif tipo == 2:
        matriz = [[1 if (i == j and i < tamanho[1]) else 0 for j in range(tamanho[1])]
                  for i in range(tamanho[0])]

    # Tipo 3: valores aleatorios dentro do intervalo [1, i*j]
    elif tipo == 3:
        matriz = [[randint(1, tamanho[0]*tamanho[1]) for j in range(tamanho[1])]
                  for i in range(tamanho[0])]
    
    return matriz
  
