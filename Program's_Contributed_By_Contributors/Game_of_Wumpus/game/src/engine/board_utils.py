from random import seed, randint

from game.src.components.board import Board
from game.src.components.enumerations import Perception, Object
from game.src.components.wumpus import Wumpus


def create_board(cols, rows, pits, wumpus=Wumpus()):
    board = Board(cols, rows)
    set_walls(board)
    set_pits(board, pits)
    set_gold_bar(board)
    set_wumpus_location(board, wumpus)
    return board


def refresh_board(game):
    board = game.board
    if game.player.has_gold:
        remove_perception(board, Perception.GOLD)
    remove_perception(board, Perception.WUMPUS)
    remove_perception(board, Perception.WUMPUS_ODOR)
    if game.wumpus is not None:
        wumpus = game.wumpus
        cell = board.cells[wumpus.position.y][wumpus.position.x]
        cell.add_perception(Perception.WUMPUS)
        set_perception_near(board, cell, Perception.WUMPUS_ODOR)


def get_random_cell(board):
    max_cols = len(board.cells[0])
    max_rows = len(board.cells)
    col, row = get_random_coords(max_cols, max_rows)
    return board.cells[row][col]


def get_random_coords(max_cols, max_rows):
    seed()
    col = randint(0, max_cols - 1)
    row = randint(0, max_rows - 1)
    return col, row


def set_walls(board):
    cols = len(board.cells[0])
    rows = len(board.cells)
    for row in range(rows):
        for col in range(cols):
            if row == 0 or row == rows - 1 or col == 0 or col == cols - 1:
                board.cells[row][col].add_perception(Perception.WALL)


def set_pits(board, pits):
    for pit in range(pits):
        cell = get_random_cell(board)
        while cell.object is not None or cell.id == "0x0":
            cell = get_random_cell(board)
        cell.object = Object.PIT
        set_perception_near(board, cell, Perception.BREEZE)


def set_perception_near(board, cell, perception):
    col, row = [int(val) for val in cell.id.split("x")]
    for i in [col - 1, col + 1]:
        set_perception(board, i, row, perception)
    for j in [row - 1, row + 1]:
        set_perception(board, col, j, perception)


def set_perception(board, col, row, perception):
    max_cols = len(board.cells[0])
    max_rows = len(board.cells)
    if col in range(max_cols) and row in range(max_rows):
        board.cells[row][col].add_perception(perception)


def set_gold_bar(board):
    cell = get_random_cell(board)
    while cell.object is not None and cell.object is Object.PIT:
        cell = get_random_cell(board)
    cell.set_object(Object.GOLD)
    cell.add_perception(Perception.GOLD)


def set_wumpus_location(board, wumpus):
    cell = get_random_cell(board)
    while cell.object is Object.PIT or cell.id == "0x0":
        cell = get_random_cell(board)
    col, row = [int(val) for val in cell.id.split("x")]
    wumpus.set_position(col, row, randint(0, 3))
    cell.add_perception(Perception.WUMPUS)
    set_perception_near(board, cell, Perception.WUMPUS_ODOR)


def check_pit(game):
    p_col = game.player.position.x
    p_row = game.player.position.y
    if game.board.cells[p_row][p_col].object == Object.PIT:
        print("You should be more careful, you stepped on an endless pit")
        print("G A M E   O V E R")
        exit(0)


def remove_perception(board, perception):
    cells = board.cells
    for i in range(len(cells)):
        for j in range(len(cells[0])):
            cell = cells[i][j]
            if perception in cell.perceptions:
                cell.perceptions.remove(perception)
