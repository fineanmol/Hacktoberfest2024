import unittest

from game.src.components.board import Board
from game.src.components.game import Game
from game.src.components.playable_character import PlayableCharacter
from game.src.components.wumpus import Wumpus


class TestGame(unittest.TestCase):
    def setUp(self):
        self.wumpus = Wumpus()
        self.board = Board(5, 5)
        self.player = PlayableCharacter()
        self.game = Game(self.board, self.wumpus, self.player)

    def test_constructor(self):
        self.assertEqual(self.game.board, self.board)
        self.assertEqual(self.game.player, self.player)
        self.assertEqual(self.game.wumpus, self.wumpus)


if __name__ == '__main__':
    unittest.main()
