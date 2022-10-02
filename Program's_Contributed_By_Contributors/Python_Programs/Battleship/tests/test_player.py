import unittest

from Player import Player
from Ship import Ship


class TestPlayer(unittest.TestCase):
    def setUp(self):
        self.player = Player("Player 1", "2 D")
        self.player.add_ship('P', 2, 1, 'A1')
        self.player.add_moves(['A1'])

    def test_is_hit(self):
        self.assertEqual(True, self.player.is_hit('A1'))

    def test_has_move(self):
        self.assertEqual(True, self.player.has_move())
        self.player.get_next_move()
        self.assertEqual(False, self.player.has_move())

    def test_get_next_move(self):
        self.assertEqual('A1', self.player.get_next_move())
        self.assertEqual(None, self.player.get_next_move())

    def test_is_destroyed(self):
        self.assertEqual(False, self.player.is_destroyed())

    def test_handle_move(self):
        player2 = Player("Player 2", "2 D")
        self.assertEqual(None, self.player.handle_move(player2))


if __name__ == '__main__':
    unittest.main()
