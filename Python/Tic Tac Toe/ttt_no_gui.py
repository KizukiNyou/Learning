import tabulate
from tabulate import tabulate
from PIL import Image
import requests


def init_board() -> list:
    return [[1, 2, 3],
            [4, 5, 6],
            [7, 8, 9]]


def draw_board(board: list):
    print(tabulate(board, tablefmt='fancy_grid'))


def player1_plays(board: list):
    jogadas = ['1', '2', '3', '4', '5', '6', '7', '8', '9']
    while True:
        buffer = input('Jogador 1: Onde você vai jogar? '
                       'Escolha um dos números na tabela: ')
        if buffer in jogadas:
            play = int(buffer)
            temp = play-1
            i = temp // 3
            j = temp % 3
            if board[i][j] == play:
                board[i][j] = 'X'
                break
            else:
                print('Jogada inválida!')
        else:
            print('Jogada inválida!')


def player2_plays(board: list):
    jogadas = ['1', '2', '3', '4', '5', '6', '7', '8', '9']
    while True:
        buffer = input('Jogador 2: Onde você vai jogar? '
                       'Escolha um dos números na tabela: ')
        if buffer in jogadas:
            play = int(buffer)
            temp = play-1
            i = temp // 3
            j = temp % 3
            if board[i][j] == play:
                board[i][j] = 'O'
                break
            else:
                print('Jogada inválida!')
        else:
            print('Jogada inválida!')


def check_win(board: list) -> int:
    # Checks the board
    # Returns 1 if player1 wins
    # Returns 2 if player2 wins
    # Returns -1 if it's a draw
    # Returns 0 if the game is still going

    # Checks horizontal victory
    for line in board:
        if line.count('X') == 3:
            return 1
        if line.count('O') == 3:
            return 2

    # Checks vertical victory
    for i in range(3):
        x_count = o_count = 0
        for j in range(3):
            if board[j][i] == 'X':
                x_count += 1
            elif board[j][i] == 'O':
                o_count += 1

        if x_count == 3:
            return 1
        if o_count == 3:
            return 2

    # Checks diagonal victory
    diagonal1 = [board[0][0], board[1][1], board[2][2]]
    diagonal2 = [board[0][2], board[1][1], board[2][0]]
    if diagonal1.count('X') == 3 or diagonal2.count('X') == 3:
        return 1
    if diagonal1.count('O') == 3 or diagonal2.count('O') == 3:
        return 2

    # Checks for a draw
    have_numbers = False
    for line in board:
        for i in line:
            if i != 'X' and i != 'O':
                have_numbers = True
                break
    if have_numbers is False:
        return -1

    # The game didn't end
    return 0


def velha():
    url = 'https://i.imgur.com/c2Vur2L.png'
    img = Image.open(requests.get(url, stream=True).raw)
    img.show()


def main():
    board = init_board()
    draw_board(board)
    
    # Main Game Loop
    while True:
        player1_plays(board)
        draw_board(board)
        winner = check_win(board)
        if winner != 0:
            break

        player2_plays(board)
        draw_board(board)
        winner = check_win(board)
        if winner != 0:
            break

    if winner == 1:
        print("JOGADOR 1 VENCEU!")
    elif winner == 2:
        print("JOGADOR 2 VENCEU!")
    else:
        print("Ihh... deu velha! ¯\\_(ツ)_/¯")
        velha()


if __name__ == "__main__":
    main()
