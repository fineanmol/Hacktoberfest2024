from copy import deepcopy

from game.src.components.arrow import Arrow
from game.src.components.board import Board
from game.src.components.character import Character
from game.src.components.enumerations import Actions
from game.src.components.game import Game


def process_shoot(game: Game, arrow: Arrow):
    refresh = False
    if arrow is not None and game.wumpus is not None:
        print("An arrow was shoot from your bow")
        w_col = game.wumpus.position.x
        w_row = game.wumpus.position.y
        p_col = game.player.position.x
        p_row = game.player.position.y

        # check orientation from player to wumpus
        if p_col == w_col or p_row == w_row:
            if p_col == w_col:
                if p_row > w_row:
                    relative_position = 2
                else:
                    relative_position = 0
            else:
                if p_col > w_col:
                    relative_position = 3
                else:
                    relative_position = 1
            if relative_position == arrow.trajectory:
                print("You perceive the Wumpus yelling in agony, you killed it")
                game.player.kill_wumpus()
                game.wumpus = None
                refresh = True
    elif arrow is not None:
        print("An arrow was shoot from your bow, but there is nothing more to kill")
    else:
        print("You have no arrows left")
    return refresh


def move(character: Character, board: Board):
    pos = deepcopy(character.position)
    pos.move_forward()
    if len(board.cells) <= pos.y or len(board.cells[0]) <= pos.x or pos.y < 0 or pos.x < 0:
        print("Cannot move through walls")
        refresh = False
    else:
        character.move_forward()
        refresh = True
    return refresh


def check_exit(game):
    player = game.player
    if player.position.x == 0 and player.position.y == 0:
        gold = player.has_gold
        wumpus = player.killed_wumpus

        if gold and wumpus:
            print("Congratulations, you managed to kill the Wumpus, collect the gold and getting out.")
        elif gold:
            print(
                "Congratulations, you managed to collect the gold and getting out without "
                "risking your life with the Wumpus.")
        elif wumpus:
            print("Congratulations hunter, you killed the Wumpus and returned to your home.")
        else:
            print("You returned home without the gold or the Wumpus head")
        exit(0)
    else:
        print("There is no exit here, you should go to the entrance")


def process_actions_player(game: Game, action: Actions):
    refresh = False
    if action == Actions.MOVE:
        refresh = move(game.player, game.board)
    elif action == Actions.TURN_LEFT:
        game.player.turn_left()
    elif action == Actions.TURN_RIGHT:
        game.player.turn_right()
    elif action == Actions.SHOOT:
        arrow = game.player.shoot()
        refresh = process_shoot(game, arrow)
    elif action == Actions.EXIT:
        check_exit(game)
    return refresh
