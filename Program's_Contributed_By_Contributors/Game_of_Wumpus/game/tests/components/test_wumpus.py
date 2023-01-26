import unittest
from random import seed, randint

from game.src.components.position import Position
from game.src.components.wumpus import Wumpus


class TestWumpus(unittest.TestCase):
    def setUp(self):
        self.wumpus = Wumpus()

    def test_constructor(self):
        self.assertEqual(self.wumpus.name, "Wumpus")

    def test_set_initial_pos(self):
        seed()
        x = randint(0, 10)
        y = randint(0, 10)
        orientation = randint(0, 10) % 4
        self.wumpus.set_position(x, y, orientation)
        self.validate_position(self.wumpus.position, Position(x, y, orientation))

    def validate_position(self, position, expected):
        self.assertEqual(position.x, expected.x)
        self.assertEqual(position.y, expected.y)
        self.assertEqual(position.orientation, expected.orientation)


if __name__ == '__main__':
    unittest.main()
