class Position:
    directions = ["north", "east", "south", "west"]

    def __init__(self, x, y, orientation):
        self.x = x
        self.y = y
        self.orientation = orientation % 4

    def turn(self, direction):
        self.orientation = (self.orientation + direction) % 4

    def turn_left(self):
        self.turn(-1)

    def turn_right(self):
        self.turn(1)

    def move_forward(self):
        dir = self.orientation
        if dir == 0:
            self.y += 1
        elif dir == 1:
            self.x += 1
        elif dir == 2:
            self.y -= 1
        else:
            self.x -= 1
