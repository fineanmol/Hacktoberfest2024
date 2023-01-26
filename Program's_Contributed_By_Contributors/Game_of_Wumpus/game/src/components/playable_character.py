from game.src.components.arrow import Arrow
from game.src.components.character import Character


class PlayableCharacter(Character):

    def __init__(self, arrows=0):
        super().__init__("Player")
        self.arrows = arrows
        self.has_gold = False
        self.killed_wumpus = False

    def obtain_gold(self):
        self.has_gold = True

    def kill_wumpus(self):
        self.killed_wumpus = True

    def shoot(self):
        if self.arrows > 0:
            arrow = Arrow(self.position.orientation)
            self.arrows -= 1
        else:
            arrow = None
        return arrow

    def exit(self):
        if self.position.x == 0 and self.position.y == 0:
            result = True
        else:
            result = False
        return result
