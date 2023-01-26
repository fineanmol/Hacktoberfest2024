import unittest

from game.src.components.playable_character import PlayableCharacter


class TestPlayableCharacter(unittest.TestCase):
    def setUp(self):
        self.pc = PlayableCharacter()

    def test_constructor_default(self):
        self.assertEqual(self.pc.name, "Player")
        self.assertFalse(self.pc.has_gold)
        self.assertFalse(self.pc.killed_wumpus)

    def test_constructor_arrows(self):
        pc = PlayableCharacter(arrows=10)
        self.assertEqual(pc.arrows, 10)


class TestHunting(TestPlayableCharacter):
    def test_shoot_arrow(self):
        arrows = 10
        pc = PlayableCharacter(arrows=arrows)
        for x in range(4):
            arrow = pc.shoot()
            self.assertEqual(pc.arrows, arrows - (x + 1))
            self.assertEqual(arrow.trajectory, pc.position.orientation)
            pc.turn_right()

    def test_shoot_but_no_arrows(self):
        arrow = self.pc.shoot()
        self.assertIsNone(arrow)


class TestExit(TestPlayableCharacter):
    def test_exit_ok(self):
        self.assertTrue(self.pc.exit())

    def test_exit_nok_x(self):
        self.pc.position.x = 9
        self.assertFalse(self.pc.exit())

    def test_exit_nok_y(self):
        self.pc.position.y = 9
        self.assertFalse(self.pc.exit())

    def test_exit_nok(self):
        self.pc.position.x = 9
        self.pc.position.y = 9
        self.assertFalse(self.pc.exit())


class TestAchievements(TestPlayableCharacter):
    def test_has_gold(self):
        self.pc.obtain_gold()
        self.assertTrue(self.pc.has_gold)

    def test_killed_wumpus(self):
        self.pc.kill_wumpus()
        self.assertTrue(self.pc.kill_wumpus, True)


if __name__ == '__main__':
    unittest.main()
