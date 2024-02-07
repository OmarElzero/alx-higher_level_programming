#!/usr/bin/python3

class Square:
    """
    Class Square that defines a square.
    """

    def __init__(self):
        self.side = 0
        self.dict_ = {}

    def __repr__(self):
        return f'Square(side={self.side})'

    def __str__(self):
        return f'Square with side length {self.side}'

    def update_side(self, side_length):
        """
        Update the side length of the square.
        """
        self.side = side_length
        self.dict_['side'] = self.side

    def area(self):
        """
        Calculate the area of the square.
        """
        return self.side ** 2
