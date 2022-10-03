"""
BattleArea class is the model for the play area
"""
from Utilities import col_to_index


def get_battlefield_dimension(row):
    """
    Splits the param Returns tuple of width and height for the battle area
    :param row: str
    :return: (str, str)
    """
    try:
        w, h = str(row).split(' ')
    except Exception:
        raise Exception('Invalid Battlefield dimensions')
    return w, h


class BattleArea:

    _height: int
    _width: int

    def __init__(self, row):
        w, h = get_battlefield_dimension(row)
        self.width = w
        self.height = h

    @property
    def width(self):
        return self._width

    @width.setter
    def width(self, width):
        width = int(width)
        if width > 9 or width < 1:
            raise Exception("Battle Area width must between 1-9")
        self._width = width

    @property
    def height(self):
        return self._height

    @height.setter
    def height(self, height):
        h = col_to_index(height)
        if h > 26 or h < 1:
            raise Exception("Battle Area height must between A-Z")
        self._height = h
