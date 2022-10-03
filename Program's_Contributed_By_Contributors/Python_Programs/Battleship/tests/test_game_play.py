import unittest
from unittest.mock import patch

from Gameplay import initialize_game, get_ships, play
from Player import Player
from Ship import Ship

lines = ["5 E",
         "2",
         "Q 1 1 A1 B2",
         "P 2 1 D4 C3",
         "A1 B2 B2 B3",
         "A1 B2 B3 A1 D1 E1 D4 D4 D5 D5"]


class TestGamePlay(unittest.TestCase):

    def test_initialize(self):
        p1, p2 = initialize_game(lines)
        self.assertEqual(Player, type(p1))

    def test_get_ships(self):
        s1, s2 = get_ships(lines[3])
        self.assertEqual(('P', 2, 1, 'D4'), s1)

    @patch("Gameplay.open")
    def test_play(self, mock_open):
        mock_open.return_value = lines
        self.assertEqual(None, play("test"))


if __name__ == '__main__':
    unittest.main()
