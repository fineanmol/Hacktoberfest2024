from copy import deepcopy

from game.src.components.enumerations import Perception


def evaluate_perceptions(game):
    p_col = game.player.position.x
    p_row = game.player.position.y
    perceptions = deepcopy(game.board.cells[p_row][p_col].perceptions)
    for perception in perceptions:
        evaluate_perception(game, perception)


def evaluate_perception(game, perception):
    if perception == Perception.WUMPUS:
        print("Oh oh, you perceive the Wumpus but it also perceives you.")
        print("Y O U   D I E D")
        exit(0)
    elif perception == Perception.WUMPUS_ODOR:
        print("You sense the smell of the Wumpus, it's near, be careful.")
    elif perception == Perception.GOLD:
        print(
            "There is something shiny on the ground. "
            "After an examination you discover that it is a gold bar and put it in your backpack.")
        p_col = game.player.position.x
        p_row = game.player.position.y
        game.board.cells[p_row][p_col].perceptions.remove(perception)
        game.board.cells[p_row][p_col].object = None
        game.player.obtain_gold()
    elif perception == Perception.BREEZE:
        print("You feel the breeze coming from a near pit, a false step could end the adventure.")
    elif perception == Perception.WALL:
        print("With your hand you can touch the wall.")
