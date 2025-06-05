import random

# Define the suits and ranks for the cards
suits = ['Hearts', 'Diamonds', 'Clubs', 'Spades']
ranks = ['2', '3', '4', '5', '6', '7', '8', '9', '10', 'Jack', 'Queen', 'King', 'Ace']
values = {'2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9': 9, '10': 10, 'Jack': 11, 'Queen': 12, 'King': 13, 'Ace': 14}

# Create a deck of cards
deck = [(rank, suit) for rank in ranks for suit in suits]

# Shuffle the deck
random.shuffle(deck)

# Split the deck between two players
player1_hand = deck[:26]
player2_hand = deck[26:]

# Function to play one round of the game
def play_round(player1_card, player2_card):
    print(f"Player 1 plays: {player1_card[0]} of {player1_card[1]}")
    print(f"Player 2 plays: {player2_card[0]} of {player2_card[1]}")
    
    # Compare the card values
    if values[player1_card[0]] > values[player2_card[0]]:
        print("Player 1 wins the round!")
        return 'Player 1'
    elif values[player1_card[0]] < values[player2_card[0]]:
        print("Player 2 wins the round!")
        return 'Player 2'
    else:
        print("It's a tie!")
        return 'Tie'

# Game loop
player1_score = 0
player2_score = 0

while player1_hand and player2_hand:
    player1_card = player1_hand.pop(0)
    player2_card = player2_hand.pop(0)
    
    result = play_round(player1_card, player2_card)
    
    # Update scores
    if result == 'Player 1':
        player1_score += 1
    elif result == 'Player 2':
        player2_score += 1
    
    print(f"Score -> Player 1: {player1_score}, Player 2: {player2_score}\n")
    
# Determine the overall winner
if player1_score > player2_score:
    print("Player 1 wins the game!")
elif player1_score < player2_score:
    print("Player 2 wins the game!")
else:
    print("The game is a tie!")

