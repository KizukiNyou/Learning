from typing import List
from random import randint
from safe_input import get_number


class Matrix:
    def __init__(self, lin: int = 3, col: int = 3, text: str = 'ascending'):
        if lin < 1 or col < 1:
            raise Exception("Negative or null values aren't accepted!")

        self.lin = lin
        self.col = col
        self.text = text
        self.body = Matrix.__fill_body(self, text)

    @staticmethod
    def __fill_body(self, _type: str):
        fill_types = ['ascending', 'descending', 'user', 'random']
        # Cries in switch case...
        if _type == 'ascending':
            return [[i*self.col + j + 1 for j in range(self.col)]
                    for i in range(self.lin)]
        elif _type == 'descending':
            return [[i * self.col - j for j in range(self.col)]
                    for i in range(self.lin, 0, -1)]
        elif _type == 'random':
            return [[randint(1, len(self)) for _j in range(self.col)]
                    for _i in range(self.lin)]
        elif _type == 'user':
            return Matrix.__fill_user_input(self)
        else:
            raise Exception(f'Wrong type! The supported types are:\n    {fill_types}')

    @staticmethod
    def __fill_user_input(self) -> List[list]:
        return [[get_number(f'Please enter a number for element a{i}{j}: ') for j in range(self.col)]
                for i in range(self.lin)]

    def main_diagonal(self):
        """Returns the sum of the main diagonal"""
        pass

    def secondary_diagonal(self):
        """Returns the sum of the secondary diagonal"""
        pass

    def is_triangular(self, lado=None):
        """Checks if the matrix is triangular"""

        # Checking lower triangular matrix
        for i in range(self.lin):
            pass

        # Checking upper triangular matrix
        for i in range(self.lin):
            pass

        # Result
        pass

    def __len__(self):
        return self.lin * self.col

    def __str__(self):
        s = ''
        for lin in self.body:
            s += str(lin) + '\n'
        s = s[:-1] + f'{self.lin}x{self.col}\n'
        return s

    def __repr__(self):
        return f'Matrix({self.lin!r}, {self.col!r}, text={self.text!r})'
    
    pass
