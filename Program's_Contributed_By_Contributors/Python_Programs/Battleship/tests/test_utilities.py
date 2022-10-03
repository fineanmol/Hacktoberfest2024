import unittest

from Utilities import col_to_index, get_index


class TestUtilities(unittest.TestCase):
    def test_col_to_index(self):
        self.assertEqual(0, col_to_index('A'))
        self.assertEqual(25, col_to_index('Z'))

    def test_get_index(self):
        self.assertEqual((0, 0), get_index('A1'))


if __name__ == '__main__':
    unittest.main()
