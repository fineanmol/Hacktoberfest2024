import unittest

from game.src.components.character import Character
from game.src.components.position import Position


class TestCharacter(unittest.TestCase):
    def setUp(self):
        self.char = Character("name")

    def validate_position(self, position, expected):
        self.assertEqual(position.x, expected.x)
        self.assertEqual(position.y, expected.y)
        self.assertEqual(position.orientation, expected.orientation)


class TestConstructor(TestCharacter):
    def test_constructor_default(self):
        self.assertEqual(self.char.name, "name")
        self.validate_position(self.char.position, Position(0, 0, 0))

    def test_constructor_other_values(self):
        other_character = Character("name", 3, 5, 3)
        self.validate_position(other_character.position, Position(3, 5, 3))


class TestMovement(TestCharacter):
    def test_turn(self):
        self.char.position = Position(0, 0, 1)
        for x in range(4, -3, -1):
            self.char.turn_left()
            self.assertEqual(self.char.position.orientation, x % 4)

        self.char.position = Position(0, 0, -1)
        for x in range(10):
            self.char.turn_right()
            self.assertEqual(self.char.position.orientation, x % 4)

    def test_advance(self):
        self.char.position = Position(5, 5, 0)
        self.char.move_forward()
        self.validate_position(self.char.position, Position(5, 6, 0))
        self.char.turn_right()
        self.char.move_forward()
        self.validate_position(self.char.position, Position(6, 6, 1))
        self.char.turn_right()
        self.char.move_forward()
        self.validate_position(self.char.position, Position(6, 5, 2))
        self.char.turn_right()
        self.char.move_forward()
        self.validate_position(self.char.position, Position(5, 5, 3))


if __name__ == '__main__':
    unittest.main()
