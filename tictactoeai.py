import os
import time
import math

board = ['1', '2', '3', '4', '5', '6', '7', '8', '9']

X, O = 'X', 'O'

def draw():
    _ = os.system('cls')

    print(' _____ _____ _____ ')
    print('|     |     |     |')
    
    print('|  ' + board[0] + '  |  ' + board[1] + '  |  ' + board[2] + '  |')

    print('|_____|_____|_____|')
    print('|     |     |     |')

    print('|  ' + board[3] + '  |  ' + board[4] + '  |  ' + board[5] + '  |')

    print('|_____|_____|_____|')
    print('|     |     |     |')

    print('|  ' + board[6] + '  |  ' + board[7] + '  |  ' + board[8] + '  |')

    print('|_____|_____|_____|')

def player(state):
    count = {
        'X': 0,
        'O': 0
    }

    for i in state:
        if i is X:
            count[X] += 1
        elif i is O:
            count[O] += 1
    
    return O if count[X] > count[O] else X

def actions(state):
    actions = []

    for i in range(len(state)):
        if state[i] in ['1', '2', '3', '4', '5', '6', '7', '8', '9']:
            actions.append(i)
    
    return actions

def result(state, action, player):
    result = [i for i in state]
    result[action] = player
    return result

def winner(state):
    if state[0] == state[1] and state[1] == state[2]:
        return state[0]
    elif state[3] == state[4] and state[4] == state[5]:
        return state[3]
    elif state[6] == state[7] and state[7] == state[8]:
        return state[6]

    elif state[0] == state[3] and state[3] == state[6]:
        return board[0]
    elif state[1] == state[4] and state[4] == state[7]:
        return board[1]
    elif state[2] == state[5] and state[5] == state[8]:
        return state[2]
    
    elif state[0] == state[4] and state[4] == state[8]:
        return board[0]
    elif state[2] == state[4] and state[4] == state[6]:
        return state[2]

    else:
        return None    

def terminal(state):
    return winner(state) is not None or not any(i in state for i in ['1', '2', '3', '4', '5', '6', '7', '8', '9'])

def utility(state):
    return 1 if winner(state) is X else -1 if winner(state) is O else 0

def minimax(state):
    t, action = minvalue(state)
    
    if action is not None:
        board[action] = O

def maxvalue(state):
    if terminal(state):
        return utility(state), None
    
    v = -math.inf
    
    for action in actions(state):
        MIN, t = minvalue(result(state, action, X))
        if MIN > v:
            ACTION = action
            v = MIN
    
    return v, ACTION

def minvalue(state):
    if terminal(state):
        return utility(state), None
    
    v = math.inf
    
    for action in actions(state):
        MAX, t = maxvalue(result(state, action, O))
        if MAX < v:
            ACTION = action
            v = MAX
        
    return v, ACTION

while True:
    draw()

    if player(board) is X:
        print('\nPlayer X, Enter a number: ', end='')
        action = int(input()) - 1

        if action in [0, 1, 2, 3, 4, 5, 6, 7, 8] and board[action] in ['1', '2', '3', '4', '5', '6', '7', '8', '9']:
            board[action] = X
        else:
            print("invalid move")
            time.sleep(2)
    else:
        print("Computer thinking...")
        time.sleep(1)
        
        minimax(board)
    
    if (terminal(board)):
        text = 'You won' if winner(board) is X else 'You lose' if winner(board) is O else 'Draw'
        _ = os.system('cls')
        print(text)
        break