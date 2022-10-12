from game.src.components.cell import Cell


class Board:
    def __init__(self, cols, rows):
        self.cells = [[Cell(f'{j}x{i}') for j in range(cols)] for i in range(rows)]
