"""
Utilities.py | Contains common utilities for the project
"""


def col_to_index(col):
    """Converts coordinate to 0 based index example A = 0
    :param col: str
    :return: int
    >>> col_to_index('A')
    0
    >>> col_to_index('Z')
    25
    >>> col_to_index('M')
    12
    """
    return ord(col) - 65


def get_index(position):
    """
    Converts position to row & col indexes example A1 is 0,0
    :param position: str
    :return: (int, int)
    >>> get_index('A1')
    (0, 0)
    >>> get_index('Z4')
    (25, 3)
    >>> get_index('B7')
    (1, 6)
    """
    col = int(position[1:]) - 1
    row = col_to_index(position[0])
    return row, col
