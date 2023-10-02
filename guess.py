import random
import math
#Taking Inputs
lower= int(input("Enter lower bound: "))
upper= int(input("Enter upper bound: "))
x= random.randint(lower,upper)
print("\n\tYou've only", round(math.log(upper-lower+1,2)), "chances to guess the integer\n")
count=0
while count<math.log(upper-lower+1,2):
  count+=1
  guess=int(input("Guess the number: ")
    if x==guess:
       print("Congratulations you did it in", count,"try")
       break
    else if x > guess:
       print("You guessed too small")
    else if x < guess:
       print("You guessed too high")
    if count>= math.log(upper-lower+1,2):
       print("\nThe number is %d" % x)
       print("\tBetter luck next time !")

      


