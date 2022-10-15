
import random

print("*********Welcome To*******************************")
print("*************GUESS THE NUMBER*********************")
print("**************************Game********************")
print("**************************************************")
print("*******Higher the range, Higher the Score*********")
print("**************************************************")


while(1):
    s, e = map(int, input("Type the range of the numbers to guess: ").split(" "))
    num = random.randint(s, e)
    
    for i in range(1, 11):
        user = int(input("Enter your number:"))
        if(num > user):
            print("Wrong!!...Try a higher value.")
        elif(num < user):
            print("Wrong!!...Try lower value.")
        else:
            print("Congratulation!! You WIN.")
            print("Your score is, = ", e-s-i)
            break
        if(i == 10):
            print("Game Over! You ran out of guesses.")
            print("The number was :", num)
    
    choice = input("Enter 1 to play again, 0 to exit : ") 
    
    if choice =="1":
        continue
    elif choice =="0":
        break
    else :
        print("Invalid input Exiting the game...")
        break   
