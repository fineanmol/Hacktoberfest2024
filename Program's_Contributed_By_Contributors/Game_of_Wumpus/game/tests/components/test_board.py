import unittest

from game.src.components.board import Board

cols = 8
rows = 5


class TestBoard(unittest.TestCase):
    def setUp(self):
        self.board = Board(cols, rows)

    def test_board_cells(self):
        for row in range(rows):
            for col in range(cols):
                self.assertEqual(self.board.cells[row][col].id, f'{col}x{row}')


if __name__ == '__main__':
    unittest.main()
