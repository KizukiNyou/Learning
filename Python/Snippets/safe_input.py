from typing import Union


def get_number(text: str = 'Enter with a number: ') -> Union[int, float]:
    while True:
        try:
            n = float(input(text))
            n = int(n) if n == int(n) else n
            break
        except (ValueError, TypeError):
            print("Invalid input! Please enter a number!")

    return n
