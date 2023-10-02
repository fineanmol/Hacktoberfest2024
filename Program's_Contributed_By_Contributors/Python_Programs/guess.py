import random

run = True
target = random.randint(1,25)

while run:
    user_input = int(input('Enter a Number between 1 and 25 : '))
    if user_input == target:
        print('You won!')
        run = False
    
    elif user_input > target:
        print("Try a Lower Number!")
        continue
    
    else:
        print('Try a Higher Number!')
        continue