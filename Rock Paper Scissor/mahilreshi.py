import random

# stone, paper, scissor

opt =  ["stone", "paper", "scissor"]

comp = random.choice(opt)

print(comp)

stone = "stone"
paper = "paper"
scissor = "scissor"

plyr = input("Select your choice stone, paper or scissor\n")

if (plyr == stone and comp  == paper):
    print("Computer wins! (Paper)")
  
elif (plyr == stone and comp == scissor):
    print("You won! (Scissor)")

elif(plyr == stone and comp == stone):
    print("$Draw$") 

if (plyr == paper and comp == scissor):
    print("Computer wins! (Paper)")
  
elif (plyr == paper and comp == stone):
    print("You won! (Scissor)")

elif(plyr == paper and comp == paper):
    print("$Draw$")

if (plyr == scissor and comp == stone):
    print("Computer wins! (Paper)")
  
elif (plyr == scissor and comp == paper):
    print("You won! (Scissor)")

elif(plyr == scissor and comp == scissor):
    print("$Draw$")
