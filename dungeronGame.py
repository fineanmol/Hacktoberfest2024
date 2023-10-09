import logging
import os
import random

logging.basicConfig(filename="game.log", level=logging.DEBUG)

import sys

CELLS = [(0, 0), (1, 0), (2, 0), (3, 0), (4, 0),
         (0, 1), (1, 1), (2, 1), (3, 1), (4, 1),
         (0, 2), (1, 2), (2, 2), (3, 2), (4, 2),
         (0, 3), (1, 3), (2, 3), (3, 3), (4, 3),
         (0, 4), (1, 4), (2, 4), (3, 4), (4, 4)]


def clear_screen():
    os.system('cls' if os.name == 'nt' else 'clear')


def get_locations():
    return random.sample(CELLS, 3)


def move_player(player, move):
    x, y = player
    if move == "LEFT":
        x -= 1
    if move == "RIGHT":
        x += 1
    if move == "UP":
        y -= 1
    if move == "DOWN":
        y += 1
    return x, y


def get_moves(player):
    moves = ["LEFT", "RIGHT", "UP", "DOWN"]
    x, y = player
    if x == 0:
        moves.remove("LEFT")
    if x == 4:
        moves.remove("RIGHT")
    if y == 0:
        moves.remove("UP")
    if y == 4:
        moves.remove("DOWN")
    return moves


def draw_map(player):
    print(" _"*5)
    tile = "|{}"

    for cell in CELLS:
        x, y  = cell
        if x < 4:
            line_end = ""
            if cell == player:
                output = tile.format("X")
            else:
                output = tile.format("_")
        else:
            line_end = "\n"
            if cell == player:
                output = tile.format("X|")
            else:
                output = tile.format("_|")
        print(output, end=line_end)



def game_loop():
    monster, door, player = get_locations()
    logging.info("monster: {}; door: {}; player: {}".format(monster, door, player))
    playing = True

    while playing:
        clear_screen()
        draw_map(player)
        valid_moves = get_moves(player)
        print("you are in the room {}".format(player))
        print("you can move {}".format(", ".join(valid_moves)))
        print("enter QUIT to exit")

        move = input("> ").upper()

        if move == "QUIT":
            print("see you next time !")
            break
        if move in valid_moves:
            player = move_player(player, move)

            if player == monster:
                print("\n the monster has got you :( \n")
                print("GAME OVER")
                playing = False

            if player == door:
                print("\n wow, you safely reach the door ! \n")
                print("CONGRATULATIONS !")
                playing = False

        else:
            input("\n cant go there ! \n")
    else:
        if input("play again ? [Y/n] ").lower() != "n":
            game_loop()





clear_screen()
print("welcome to the dungeon !")
input("press return to start")
clear_screen()

game_loop()
