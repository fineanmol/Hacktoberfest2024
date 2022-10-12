from game.src.components.character import Character
from game.src.components.position import Position


class Wumpus(Character):
    def __init__(self):
        super().__init__("Wumpus")

    def set_position(self, x, y, orientation):
        self.position = Position(x, y, orientation)
