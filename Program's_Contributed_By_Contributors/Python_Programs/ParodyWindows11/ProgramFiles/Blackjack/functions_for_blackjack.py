import tkinter
import random


def loadImages(cards, root):
    """
    Load images off of Cards for
    blackjack game in the same directory (blackjack\\blackjack.py).
    :param root: The window
    :param cards: The cards from the directory
    :return: None
    """
    suits = ['heart', 'club', 'diamond', 'spade']
    faceCards = ['jack', 'queen', 'king']
    # Suit cards loading
    for suit in suits:
        for card in range(1, 11):
            fileName = f"ProgramFiles/BlackJack/Cards/{str(card)}_{suit}.png"
            image = tkinter.PhotoImage(file=fileName, master=root)
            cards.append((card, image,))
        for card in faceCards:
            fileNames = f"ProgramFiles/BlackJack/Cards/{str(card)}_{suit}.png"
            images = tkinter.PhotoImage(file=fileNames, master=root)
            cards.append((10, images,))


def dealCard(frame: tkinter.Frame, deckCards: list) -> any:
    """
    Deal cards for players and dealers.

    Additional feature is that it won't crash if there's no cards in the list
    as we did when the length of the list is more than 0, then only,
    it should display cards or give a friendly error message.
    :param frame: The frame which it should deal cards on
    :param deckCards: From what list of cards it should rely on
    :return: Cards for players who request.
    """
    if len(deckCards) > 0:
        nextCard = deckCards.pop(0)
        deckCards.append(nextCard)
        tkinter.Label(frame, image=nextCard[1], relief="raised").pack(
            side="left")
        return nextCard
    else:
        print("Error while importing cards...")


def scoreHand(hand):
    """
    Chacking scores for players and dealers hands
    :param hand: The respective player or the dealer
    :return: None
    """
    score = 0
    ace = False
    for nextCard in hand:
        cardValue = nextCard[0]
        if cardValue == 1 and not ace:
            ace = True
            cardValue = 11
        score += cardValue
        if score > 21 and ace:
            score -= 10
            ace = False
    return score


def shuffler(*decks: list) -> None:
    """
    Shuffles cards in a deck of cards
    :return:Shuffled Cards
    """
    for deck in decks:
        random.shuffle(deck)
