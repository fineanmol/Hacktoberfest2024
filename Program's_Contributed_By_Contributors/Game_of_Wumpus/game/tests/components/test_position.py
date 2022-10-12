import unittest

from game.src.components.position import Position


class TestPosition(unittest.TestCase):
    def setUp(self):
        self.obj = Position(1, 2, 2)


class TestConstructor(TestPosition):
    def test_constructor(self):
        self.assertEqual(self.obj.x, 1)
        self.assertEqual(self.obj.y, 2)
        self.assertEqual(self.obj.orientation, 2)

    def test_constructor_orientation_out_of_bounds(self):
        for x in range(-4, 9):
            self.assertEqual(Position(0, 0, x).orientation, x % 4)


class TestMovement(TestPosition):
    def test_turn(self):
        pos = Position(0, 0, 1)
        for x in range(4, -3, -1):
            pos.turn_left()
            self.assertEqual(pos.orientation, x % 4)

        pos = Position(0, 0, -1)
        for x in range(10):
            pos.turn_right()
            self.assertEqual(pos.orientation, x % 4)

    def test_advance(self):
        pos = Position(5, 5, 0)
        pos.move_forward()
        self.validate_position(pos, Position(5, 6, 0))
        pos.turn_right()
        pos.move_forward()
        self.validate_position(pos, Position(6, 6, 1))
        pos.turn_right()
        pos.move_forward()
        self.validate_position(pos, Position(6, 5, 2))
        pos.turn_right()
        pos.move_forward()
        self.validate_position(pos, Position(5, 5, 3))

    def validate_position(self, position, expected):
        self.assertEqual(position.x, expected.x)
        self.assertEqual(position.y, expected.y)
        self.assertEqual(position.orientation, expected.orientation)


if __name__ == '__main__':
    unittest.main()
