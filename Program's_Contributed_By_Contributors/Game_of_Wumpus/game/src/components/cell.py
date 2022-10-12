from game.src.components.enumerations import Object, Perception


class Cell:
    def __init__(self, identifier):
        self.id = identifier
        self.object = None
        self.perceptions = set()

    def set_object(self, obj: Object):
        self.object = obj

    def add_perception(self, perception: Perception):
        self.perceptions.add(perception)
