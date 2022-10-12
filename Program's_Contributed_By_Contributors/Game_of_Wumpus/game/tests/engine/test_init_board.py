import unittest

from game.src.components.enumerations import Perception, Object
from game.src.components.wumpus import Wumpus
from game.src.engine.board_utils import create_board

rows = 8
cols = 5
pits = 6


class TestInitBoard(unittest.TestCase):
    def setUp(self):
        self.board = create_board(cols, rows, pits)

    def test_walls(self):
        for row in range(rows):
            for col in range(cols):
                if col == 0 or col == cols - 1 or row == 0 or row == rows - 1:
                    self.assertTrue(Perception.WALL in self.board.cells[row][col].perceptions)
                else:
                    self.assertFalse(Perception.WALL in self.board.cells[row][col].perceptions)


class TestPits(TestInitBoard):
    def test_initial_cell_no_pit(self):
        cell = create_board(cols, rows, cols * rows - 2).cells[0][0]
        self.assertIsNot(cell.object, Object.PIT, "There shouldn't ber a pit at initial cell")

    def test_number_pits(self):
        cells = self.board.cells
        pit_counter = 0
        for row in range(rows):
            for col in range(cols):
                if Object.PIT == cells[row][col].object:
                    pit_counter += 1
        self.assertEqual(pit_counter, pits)

    def test_perception_pits(self):
        cells = self.board.cells
        for row in range(rows):
            for col in range(cols):
                if Object.PIT == cells[row][col].object:
                    self.validate_perception_surrounding_pit(cells, col, row)

    def validate_perception_surrounding_pit(self, cells, col, row):
        for i in [col - 1, col + 1]:
            self.validate_perception_pit(cells, i, row)
        for j in [row - 1, row + 1]:
            self.validate_perception_pit(cells, col, j)

    def validate_perception_pit(self, cells, col, row):
        if col in range(cols) and row in range(rows):
            self.assertTrue(Perception.BREEZE in cells[row][col].perceptions, f'Expected breeze at {col}x{row}')


class TestGoldBar(TestInitBoard):
    def test_only_one_gold_bar(self):
        cells = self.board.cells
        gold_bars = 0
        for row in range(rows):
            for col in range(cols):
                if Object.GOLD == cells[row][col].object:
                    gold_bars += 1
        self.assertEqual(gold_bars, 1, "There should be only one gold bat at the board")

    def test_gold_pit_collision(self):
        cells = create_board(cols, rows, cols * rows - 2).cells
        gold_bars = 0
        pit_counter = 0
        for row in range(rows):
            for col in range(cols):
                if Object.GOLD == cells[row][col].object:
                    gold_bars += 1
                elif Object.PIT == cells[row][col].object:
                    pit_counter += 1
        self.assertTrue(gold_bars == 1 and pit_counter == cols * rows - 2,
                        "Gold bar and pit shouldn't be placed at the same cell")


class TestWumpusLocation(TestInitBoard):
    def test_wumpus_location(self):
        wumpus = Wumpus()
        create_board(cols, rows, cols * rows - 2, wumpus)
        pos = wumpus.position
        self.assertFalse(pos.x == 0 and pos.y == 0, 'Wumpus cannot be initialized at 0x0')

    def test_wumpous_pit_collision(self):
        wumpus = Wumpus()
        cells = create_board(cols, rows, cols * rows - 2, wumpus).cells
        pos = wumpus.position
        self.assertFalse(cells[pos.y][pos.x] == Object.PIT, "Wumpus cannot be placed at a cell with a pit")


if __name__ == '__main__':
    unittest.main()
