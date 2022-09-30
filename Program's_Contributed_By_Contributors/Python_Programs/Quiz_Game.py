def check_guess(guess, answer):
    global score
    still_guessing = True
    attempt = 0
    while still_guessing and attempt < 3:
        if guess.lower() == answer.lower():
            print("Correct Answer")
            score = score + 1
            still_guessing = False
        else:
            if attempt < 2:
                guess = input("Sorry Wrong Answer, try again: ")
            attempt = attempt + 1
    if attempt == 3:
        print("The Correct answer is ", answer)


score = 0
guess1 = input("Lead actor in the Amazing SpiderMan Franchise ")
check_guess(guess1, "andrew garfield")
guess2 = input("Full form of JS in programming ")
check_guess(guess2, "javascript")
guess3 = input("Complete the famous dialogue from Avengers Endgame, 'I am ______'")
check_guess(guess3, "iron man")
print("Your Score is " + str(score))