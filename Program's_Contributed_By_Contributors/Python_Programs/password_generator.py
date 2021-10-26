from string import punctuation, ascii_uppercase, ascii_lowercase, digits
from random import sample, shuffle, randint

def password_generator(difficulty) -> str:
    initial_password = ""

    if difficulty == "easy":
        initial_password = sample(ascii_lowercase, randint(2, 5)) + sample(ascii_uppercase, randint(3, 5))
    elif difficulty == "normal":
        initial_password = sample(ascii_lowercase, randint(2, 3)) + sample(ascii_uppercase, randint(2, 4)) + sample(digits, randint(3, 5))
    elif difficulty == "hard":
        initial_password = sample(ascii_lowercase, randint(2, 3)) + sample(ascii_uppercase, randint(2, 3)) + sample(digits, randint(3, 4)) + sample(punctuation, randint(3, 5))
    else: 
        return "Choose between 'easy', 'normal' or 'hard'."
        
    shuffle(initial_password)

    global final_password
    final_password = "".join(initial_password)
    
    return f"Your Password: {final_password}"

print(password_generator("easy"))
print(password_generator("normal"))
print(password_generator("hard"))