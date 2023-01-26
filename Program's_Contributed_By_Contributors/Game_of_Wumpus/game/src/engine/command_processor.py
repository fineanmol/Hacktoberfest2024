import re

from game.src.components.enumerations import Actions


class CommandProcessor:
    p_move = re.compile(r'^move( forwards?)?$')
    p_turn_left = re.compile(r'^left turn$|^turn left$')
    p_turn_right = re.compile(r'^right turn$|^turn right$')
    p_shoot = re.compile(r'^shoot$|^(shoot|throw) arrow$')
    p_exit = re.compile(r'^exit( (board|game))?$|^go outside$')

    def process_command(self, command):
        text = command.lower()
        if re.match(self.p_move, text):
            action = Actions.MOVE
        elif re.match(self.p_turn_left, text):
            action = Actions.TURN_LEFT
        elif re.match(self.p_turn_right, text):
            action = Actions.TURN_RIGHT
        elif re.match(self.p_shoot, text):
            action = Actions.SHOOT
        elif re.match(self.p_exit, text):
            action = Actions.EXIT
        else:
            action = None
        return action
