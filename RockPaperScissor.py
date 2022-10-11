import random
print("Hi!",input("What is Your good Name? "))
user = 0; computer = 0
l = ["rock","paper","scissor","q"]
while True:
      user_sel = input("Please Select Either of Rock/Paper/Scissor or Q to Quit ").lower()
      a = random.randint(0,2)
      computer_sel = l[a]
      if user_sel == "q":
          break
      elif user_sel not in l:
          print("Invalid Input!!, Try again")
          continue
      print("Computer Chose:",computer_sel)
      if user_sel == "rock" and computer_sel == "scissor":
          print("Congrats! You Win")
          user+=1
      elif user_sel == "paper" and computer_sel == "rock":
          print("Congrats! You Win")
          user += 1
      elif user_sel == "scissor" and computer_sel == "paper":
          print("Congrats! You Win")
          user += 1
      elif user_sel == computer_sel:
          print("Ohh! Its a Draw")
      else:
          print("OOPS! I think you Lost")
          computer+=1
print("You Won", user, "times.")
print("Computer Won", computer, "times.")
print("Thanks For Playing, Have a Nice Day :)")
