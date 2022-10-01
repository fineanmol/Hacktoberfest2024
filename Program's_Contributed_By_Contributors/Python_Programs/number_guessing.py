import random
while True:
    user_input=input("\nEnter a number : ")
    if user_input.isdigit():
        user_input=int(user_input)

        if user_input<=0:
            print("Please enter a number greater than 0 next time")
            ch=input("\nDo you want to continue ?(yes/no) ---> ").lower()
            if ch=="yes":
                continue
            else:
                break
    else:
        print("Please enter a digit next time")
        ch=input("\nDo you want to continue ?(yes/no) ---> ").lower()
        if ch=="yes":
            continue
        else:
            break

    random_number=random.randint(0,user_input)
    guesses=0
    while True:
        guesses+=1
        user_guess=input("\nCan you guess a number ? Enter it : ")
        if user_guess.isdigit():
            user_guess=int(user_guess)
        else:
            print("Please type a number next time")
            continue
        if user_guess==random_number:
            print("Hurray...!! You got the correct answer...!!")
            break
        else:
            if user_guess>random_number:
                print("You guess above the number")
            else:
                print("You guessed below the number")

    print("You got it in",guesses,"number of guesses !!")
    ch=input("\nDo you want to continue ?(yes/no) ---> ").lower()
    if ch=="yes":
        continue
    else:
        break
