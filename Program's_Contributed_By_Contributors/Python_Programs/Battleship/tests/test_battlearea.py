import unittest

from BattleArea import BattleArea


class TestBattleArea(unittest.TestCase):
    def test_battle_area_width(self):
        battle_area = BattleArea('9 D')
        self.assertEqual(9, battle_area.width)
        self.assertRaises(Exception, BattleArea, '10 AA')
        self.assertRaises(Exception, BattleArea, '10AA')

    def test_battle_area_height(self):
        battle_area = BattleArea('9 D')
        self.assertEqual(3, battle_area.height)
        self.assertRaises(Exception, BattleArea, '9 a')


if __name__ == '__main__':
    unittest.main()
