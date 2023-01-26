from enum import auto, Enum


class Object(Enum):
    GOLD = auto()
    PIT = auto()


class Perception(Enum):
    WUMPUS = auto()
    WUMPUS_ODOR = auto()
    GOLD = auto()
    BREEZE = auto()
    WALL = auto()


class Actions(Enum):
    MOVE = auto()
    TURN_LEFT = auto()
    TURN_RIGHT = auto()
    SHOOT = auto()
    EXIT = auto()
