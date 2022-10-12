from game.src.components.board import Board
from game.src.components.playable_character import PlayableCharacter
from game.src.components.wumpus import Wumpus


class Game:
    def __init__(self, board: Board, wumpus: Wumpus, player: PlayableCharacter):
        self.board = board
        self.wumpus = wumpus
        self.player = player
