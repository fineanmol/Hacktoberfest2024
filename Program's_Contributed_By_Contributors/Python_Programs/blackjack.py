import blackjackart,random,os
def deal_card():
    cards = [11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10]
    rand_card=random.choice(cards)
    return rand_card
def calculate_card(cards):    
    if sum(cards)==21 and len(cards)==2:
        return 0
    if 11 in cards and sum(cards)>21:
        cards.remove(11)
        cards.append(1)
    return sum(cards)
def compare(user_score,computer_score):
    if user_score==computer_score:
        return "Draw"
    elif computer_score==0:
        return "You lost. Computer has blackjack"
    elif user_score==0:
        return "Blackjack!! You Won"
    elif user_score>21:
         return "Score above 21. You lost"
    elif computer_score>21:
        return "Computer score went over 21. You win"
    elif user_score>computer_score:
        return "You have higher score. You win"
    else:
        return "Your score is lower. You lost"
def play_game():
    print(blackjackart.logo)  
    user_cards=[]
    computer_cards=[]
    game_over=False 
    for i in range(2):
        user_cards.append(deal_card())
        computer_cards.append(deal_card())
    while not game_over:
        user_score=calculate_card(user_cards)
        computer_score=calculate_card(computer_cards)
        print(f"Your cards : {user_cards}, Current score : {user_score}")
        print(f"Computer's first card : {computer_cards[0]}")
        if user_score==0 or computer_score==0 or user_score>21:
            game_over=True
        else:
            should_continue=input("Type 'y' to get another card and 'n' to pass : ")
            if should_continue=='y':
                user_cards.append(deal_card())
            else:
                game_over=True
    while computer_score!=0 and computer_score<17:
        computer_cards.append(deal_card())
        computer_score=calculate_card(computer_cards)
        print(f"Your final hand : {user_cards} and final score : {user_score}")
        print(f"Computer's final hand : {computer_cards} and final score : {computer_score}")
        print(compare(user_score,computer_score))
while input("Do you want to play a game of Blackjack.Type 'y' for yes 'n' for no : ").lower()=='y':
        os.system('cls')
        play_game()