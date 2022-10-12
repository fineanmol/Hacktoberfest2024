import unittest

from game.src.components.arrow import Arrow


class TestArrow(unittest.TestCase):
    def test_constructor(self):
        for x in range(10):
            self.assertEqual(Arrow(x).trajectory, x % 4)


if __name__ == '__main__':
    unittest.main()
