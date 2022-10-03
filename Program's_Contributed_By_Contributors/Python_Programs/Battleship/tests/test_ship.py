import unittest

from Ship import Ship


class TestShip(unittest.TestCase):
    def setUp(self):
        self.ship = Ship(2, 1, 'P', 'A1')

    def test_ship(self):
        self.assertEqual(2, len(self.ship.indexes))

    def test_is_hit(self):
        self.assertEqual(True, self.ship.is_hit((0, 0)))
        self.assertEqual(False, self.ship.is_hit((3, 3)))

    def test_is_destroyed(self):
        self.assertEqual(False, self.ship.is_destroyed())
        self.ship.is_hit((0, 0))
        self.ship.is_hit((0, 1))
        self.assertEqual(True, self.ship.is_destroyed())


if __name__ == '__main__':
    unittest.main()
