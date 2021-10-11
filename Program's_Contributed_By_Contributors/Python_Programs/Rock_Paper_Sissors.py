import random

def play():
  user = input("'r' , 'p' , 's' ")
  comp =  random.choice(['r','p','s'])

  if user==comp:
    print("tie")
    play()

  elif winner(user,comp):
    print(f"comp chose {comp} YOU WIN!!")
  elif winner(comp, user):
    print(f"comp chose {comp} you LOSE")

def winner(player, opponent):
  if ( player =='r' and opponent == 's') or ( player =='s' and opponent == 'p') or ( player =='p' and opponent == 'r'):
    return True
  else:
    return False

play()
