import random
def get_choices (): 
    player_choice= input(" this is rock paper scissors, enter your move : ")
    options = ["rock","paper","scissors"]
    computer_choice=random.choice(options)
    choices= {"player": player_choice,"computer": computer_choice}
    return choices
    
# choices = get_choices()
# print (choices)

def check_win (player,computer):
  print("you chose " + player + ",computer chose "+computer)
  if player == computer:
   return "its a tie"
  elif player=="rock":
   if computer == "scissors":
     return "rock smashes scissors ! you win"
   else : 
     return "paper covers rock! you lose!"
  elif player=="paper":
   if computer == "rock":
     return "paper covers rock! you win!"
   else : 
     return "scissor cut paper! you lose!"
  elif player=="scissors":
   if computer == "paper":
     return "scissors cut paper you win!"
   else : 
     return "rock smashes scissors you lose!"

choices = get_choices()
result = check_win(choices["player"],choices["computer"])
print(result)
# check_win("rock","paper")
