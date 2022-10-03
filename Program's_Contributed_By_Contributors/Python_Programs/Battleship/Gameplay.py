import sys

from Player import Player

PLAYER_2 = "Player-2"
PLAYER_1 = "Player-1"


def get_ships(param):
    """
    creates tuple of Ship attribute from input
    :param param: ((str, int,int, str),(str, int,int, str))
    :return:
    """
    t, w, h, pos1, pos2 = str(param).split(' ')
    return (t, int(w), int(h), pos1), (t, int(w), int(h), pos2)


def play(file_path):
    """
    Reads input file and initializes the game and initiates it
    :param file_path: str
    :return: None
    """
    try:
        lines = [line.rstrip('\n') for line in open(file_path)]
        player1, player2 = initialize_game(lines)

        player1.handle_move(player2)
    except IOError as e:
        print("Error while reading input file: {0}".format(e))


def initialize_game(lines):
    """
    Initializes the game
    :param lines: List[str]
    :return: (Player, Player)
    """
    battle_area_row = lines[0]
    player1 = Player(PLAYER_1, battle_area_row)
    player2 = Player(PLAYER_2, battle_area_row)
    total_ships = int(lines[1])
    for i in range(total_ships):
        ship1, ship2 = get_ships(lines[2 + i])
        player1.add_ship(*ship1)
        player2.add_ship(*ship2)
    player1.add_moves(str(lines[-2]).split(' '))
    player2.add_moves(str(lines[-1]).split(' '))
    return player1, player2


if __name__ == '__main__':
    if len(sys.argv) > 1:
        testfile = str(sys.argv[1])
        play(testfile)
    else:
        play('testdata/testdata.txt')
