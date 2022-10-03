import enum

from Utilities import get_index


class Ship:

    start_pos: str
    height: int
    width: int
    ship_type_str: str

    def __init__(self, width, height, ship_type_str, start_pos):
        self.indexes = {}
        self.width = width
        self.height = height
        self.start_pos = start_pos
        self.ship_type_str = ship_type_str
        self.initialize()

    def initialize(self):
        row, col = get_index(self.start_pos)
        i = j = 0
        while i < self.height:
            while j < self.width:
                self.indexes[(row + i, col + j)] = ShipType[self.ship_type_str].value
                j = j + 1
            i = i + 1

    def is_destroyed(self):
        for val in self.indexes.values():
            if val != 0:
                return False
        return True

    def is_hit(self, index):
        """

        :type index: (int, int)
        """
        if index in self.indexes and self.indexes[index] != 0:
            self.indexes[index] = self.indexes[index] - 1
            return True
        else:
            return False


class ShipType(enum.Enum):
    P = 1
    Q = 2
