from game.src.components.position import Position


class Character:
    def __init__(self, name, pos_x=0, pos_y=0, orientation=0):
        self.position = Position(pos_x, pos_y, orientation)
        self.name = name

    def turn_left(self):
        self.position.turn_left()

    def turn_right(self):
        self.position.turn_right()

    def move_forward(self):
        self.position.move_forward()
