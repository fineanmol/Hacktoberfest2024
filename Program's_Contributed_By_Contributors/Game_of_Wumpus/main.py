import sys

from game.src.engine.core import play

if sys.version_info < (3, 7):
    sys.stdout.write("Sorry, requires Python 3.7\n")
    sys.exit(1)

import argparse

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description="Play game 'Hunt the Wumpus'")
    parser.add_argument("cols", help="Number of columns for the board game", type=int)
    parser.add_argument("rows", help="Number of rows for the board game", type=int)
    parser.add_argument("pits", help="How many pits should be", type=int)
    parser.add_argument("arrows", help="How many arrows have the player", type=int)
    parser.add_argument("--debug", help="Enables debug mode", action='store_true')
    args = parser.parse_args()

    play(args.cols, args.rows, args.pits, args.arrows, args.debug)

    sys.exit()
