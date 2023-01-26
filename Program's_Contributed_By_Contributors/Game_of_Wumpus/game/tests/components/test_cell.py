import unittest

from game.src.components.cell import Cell
from game.src.components.enumerations import Perception, Object


class TestCell(unittest.TestCase):
    def setUp(self):
        self.cell = Cell("cell_id")

    def test_constructor(self):
        self.assertEqual(self.cell.id, "cell_id")
        self.assertEqual(len(self.cell.perceptions), 0)
        self.assertEqual(self.cell.object, None)


class TestObjects(TestCell):
    def test_set_gold(self):
        self.cell.set_object(Object.GOLD)
        self.assertEqual(self.cell.object, Object.GOLD)

    def test_set_pit(self):
        self.cell.set_object(Object.PIT)
        self.assertEqual(self.cell.object, Object.PIT)


class TestSetPerceptions(TestCell):
    def test_set_perceive_wumpus(self):
        self.cell.add_perception(Perception.WUMPUS)
        self.assertTrue(Perception.WUMPUS in self.cell.perceptions)

    def test_set_perceive_wumpus_odor(self):
        self.cell.add_perception(Perception.WUMPUS_ODOR)
        self.assertTrue(Perception.WUMPUS_ODOR in self.cell.perceptions)

    def test_set_perceive_gold(self):
        self.cell.add_perception(Perception.GOLD)
        self.assertTrue(Perception.GOLD in self.cell.perceptions)

    def test_set_perceive_breeze(self):
        self.cell.add_perception(Perception.BREEZE)
        self.assertTrue(Perception.BREEZE in self.cell.perceptions)

    def test_set_perceive_wall(self):
        self.cell.add_perception(Perception.WALL)
        self.assertTrue(Perception.WALL in self.cell.perceptions)


class TestPerceptionsVarious(TestCell):
    def test_perceive_wumpus_odor_gold(self):
        self.cell.add_perception(Perception.WUMPUS_ODOR)
        self.cell.add_perception(Perception.GOLD)
        self.assertTrue(Perception.GOLD in self.cell.perceptions)
        self.assertTrue(Perception.WUMPUS_ODOR in self.cell.perceptions)

    def test_perceive_wumpus_gold(self):
        self.cell.add_perception(Perception.WUMPUS)
        self.cell.add_perception(Perception.GOLD)
        self.assertTrue(Perception.GOLD in self.cell.perceptions)
        self.assertTrue(Perception.WUMPUS in self.cell.perceptions)

    def test_perceive_wumpus_odor_breeze(self):
        self.cell.add_perception(Perception.WUMPUS_ODOR)
        self.cell.add_perception(Perception.BREEZE)
        self.assertTrue(Perception.BREEZE in self.cell.perceptions)
        self.assertTrue(Perception.WUMPUS_ODOR in self.cell.perceptions)

    def test_perceive_wumpus_odor_wall(self):
        self.cell.add_perception(Perception.WUMPUS_ODOR)
        self.cell.add_perception(Perception.WALL)
        self.assertTrue(Perception.WALL in self.cell.perceptions)
        self.assertTrue(Perception.WUMPUS_ODOR in self.cell.perceptions)

    def test_perceive_wumpus_breeze(self):
        self.cell.add_perception(Perception.WUMPUS)
        self.cell.add_perception(Perception.BREEZE)
        self.assertTrue(Perception.BREEZE in self.cell.perceptions)
        self.assertTrue(Perception.WUMPUS in self.cell.perceptions)

    def test_perceive_wumpus_wall(self):
        self.cell.add_perception(Perception.WUMPUS)
        self.cell.add_perception(Perception.WALL)
        self.assertTrue(Perception.WALL in self.cell.perceptions)
        self.assertTrue(Perception.WUMPUS in self.cell.perceptions)


if __name__ == '__main__':
    unittest.main()
