from typing import List

from BattleArea import BattleArea
from Ship import Ship
from Utilities import get_index


class Player:
    ships: List[Ship]
    battle_area: BattleArea
    name: str
    moves: List[str]

    def __init__(self, name, row):
        self.moves = []
        self.name = name
        self.battle_area = BattleArea(row)
        self.ships = []

    def add_moves(self, moves):
        """
        Initialises moves for the Player
        :param moves:
        :return:
        """
        self.moves = moves

    def has_move(self):
        """
        Returns True if Player has moves left
        :return: boolean
        """
        return len(self.moves) > 0

    def add_ship(self, ship_type, width, height, start_pos):
        """
        Creates and appends ship to ships list
        :param ship_type: ShipType
        :param width: int
        :param height: int
        :param start_pos: str
        :return:
        """
        ship = Ship(width, height, ship_type, start_pos)
        self.ships.append(ship)

    def is_hit(self, move):
        """
        Returns True if the move hit any Ship
        :param move: str
        :return: boolean
        """
        index = get_index(move)
        is_hit = False
        for ship in self.ships:
            is_hit = is_hit or ship.is_hit(index)
        return is_hit

    def is_destroyed(self):
        """
        Returns true if all ships are destroyed
        :return: boolean
        """
        is_destroyed = True
        for ship in self.ships:
            is_destroyed = is_destroyed and ship.is_destroyed()
        return is_destroyed

    def handle_move(self, opponent):
        """
        On each turn gets next move
        checks if it was a hit or miss
        checks if opponent is destroyed
            if yes stops the game
            if no and hit calls next turn for current player
            if no and miss calls next turn for opponent player

        :param opponent: Player
        :return: None
        """
        move = self.get_next_move()
        if not move and opponent.has_move():
            return opponent.handle_move(self)

        result = opponent.is_hit(move)
        print("{0} fires a missile with target {1} which got {2}".format(self.name, move, "hit" if result else "miss"))

        if opponent.is_destroyed():
            print("{0} won the battle".format(self.name))
            return
        if result:
            return self.handle_move(opponent)
        else:
            return opponent.handle_move(self)

    def get_next_move(self):
        """
        Returns next move if available None otherwise
        :return: str or None
        """
        if not self.has_move():
            print("{0} has no more missiles left to launch".format(self.name))
            return None
        move = self.moves.pop(0)
        return move
