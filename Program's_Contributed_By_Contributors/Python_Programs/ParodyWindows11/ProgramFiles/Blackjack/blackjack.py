"""
Black jack game made possible with tkinter code
"""
import tkinter
from tkinter import ttk
import ProgramFiles.Blackjack.functions_for_blackjack as functions_for_blackjack

# Creating styles for background colours.


def lightTheme(event=None):
    """ enables light theme
    :param event: The event that it's going to capture to enable keyboard
    shortcut
    """
    global display
    ttk.Style().configure("TFrame", foreground="black", background="white")
    ttk.Style().configure("TLabel", foreground="black", background="white")
    ttk.Style().configure("TButton", foreground="black", background="white")
    display.configure(background="white", menu=altMenu)


def darkTheme(event=None):
    """ enables dark theme
    :param event: The event that it's going to capture to enable keyboard
    shortcut
    """
    global display
    global altMenu

    ttk.Style().configure("TFrame", foreground="white", background="black")
    ttk.Style().configure("TLabel", foreground="white", background="black")
    ttk.Style().configure("TButton", foreground="black", background="black")
    display.configure(background="black", menu=altMenu)


def newGame():
    """
    Start a new game after the reboot button is clicked.
    :return: None
    """
    global dealerHand
    global dealerHandT2
    global dCF
    global player1Hand
    global player1HandT2
    global player2Hand
    global dealerCardFrame
    global pC1F2
    global player1CardFrame
    global player2CardFrame
    dealerCardFrame.destroy()
    dCF.destroy()
    dealerCardFrame = ttk.Frame(cardFrame, style="TFrame")
    dealerCardFrame.grid(row=0, column=1, sticky="ew", rowspan=2)
    dCF = ttk.Frame(cardFrame2, style="TFrame")
    dCF.grid(row=0, column=1, sticky="ew", rowspan=2)
    player1CardFrame.destroy()
    pC1F2.destroy()
    pC1F2 = ttk.Frame(cardFrame2, style="TFrame")
    pC1F2.grid(row=2, column=1, sticky="ew", rowspan=2)
    player1CardFrame = ttk.Frame(cardFrame, style="TFrame")
    player1CardFrame.grid(row=2, column=1, sticky="ew", rowspan=2)
    player2CardFrame.destroy()
    player2CardFrame = ttk.Frame(cardFrame2, style="TFrame")
    player2CardFrame.grid(row=4, column=1, sticky="ew", rowspan=2)
    resultVar.set("None")
    resultVarT2.set("None")
    dealerHand = []
    dealerHandT2 = []
    player1Hand = []
    player1HandT2 = []
    player2Hand = []
    initialDeal()


def shuffle():
    """
    Activates `functions_for_blackjack.shuffler(deck)` in
    `functions_for_blackjack.py`
    :return:None
    """
    functions_for_blackjack.shuffler(deck, deck2)


def exitter():
    """
    Corrupting the game by stopping functions or quitting player frames
    :return: None
    """
    from tkinter import messagebox
    text = ("Are you sure you want to corrupt the runtime of this game?\n"
           "Note that the code of the game won't be changed at all!")
    warning = messagebox.askokcancel("CAUTION!", text)
    if warning:
        import random
        destroyer = ["function", "frame"]
        if destroyer[random.randint(0, 1)] == "function":
            functions = [newGame, exitter, shuffle, dealDealer, dealPlayer2,
                         dealPlayer1, initialDeal, functions_for_blackjack]
            funcToDelIndex = random.randint(0, 7)
            destroy_num = functions[funcToDelIndex]
            print(f"exiting function {str(destroy_num)}")
            del functions[funcToDelIndex]
            quit(destroy_num)
        else:
            frames = [dealerCardFrame, player1CardFrame, player2CardFrame]
            destroy_this = frames[random.randint(0, 2)]
            print(f"exiting frame {str(destroy_this)}")
            destroy_this.destroy()
    else:
        tkinter.messagebox.showinfo("You saved your day", "Aborted the "
                                                          "operation! have a "
                                                          "great day "
                                                          "playing blackjack.")


def fullscreen(event=None):
    """

    :param event: The event that it's going to capture to enable keyboard
    shortcut
    """
    display.attributes("-fullscreen", 1)


def exitFullScreen(event=None):
    """

    :param event: The event that it's going to capture to enable keyboard
    shortcut
    """
    display.attributes("-fullscreen", False)


def quit(event=None):
    """

    :param event: The event that it's going to capture to enable keyboard
    shortcut
    """
    display.destroy()

# Functions for the execution of player's buttons


def dealDealer():
    """
    Activate the function to display cards in functions_for_blackjack.py
    :return:Cards for the Dealer
    """
    dealersScore = functions_for_blackjack.scoreHand(dealerHand)
    while 0 < dealersScore < 17:
        dealerHand.append(functions_for_blackjack.dealCard(dealerCardFrame,
                                                           deck))
        dealersScore = functions_for_blackjack.scoreHand(dealerHand)
        dealersScoreLabel.set(dealersScore)

    player1Score = functions_for_blackjack.scoreHand(player1Hand)
    if dealersScore > 21 or dealersScore < player1Score:
        resultVar.set("Player 1 Wins this round!!!")
    elif dealersScore > player1Score:
        resultVar.set("Dealer wins this round!!!")
    else:
        resultVar.set("DRAW!!! DRAW!!! RESTART ROUND")


def dealDealerT2():
    """
        Activate the function to display cards in functions_for_blackjack.py
        :return:Cards for the Dealer
        """
    dealersScoreT2 = functions_for_blackjack.scoreHand(dealerHandT2)
    while 0 < dealersScoreT2 < 17:
        dealerHandT2.append(functions_for_blackjack.dealCard(dCF, deck2))
        dealersScoreT2 = functions_for_blackjack.scoreHand(dealerHandT2)
        dealersScoreLabelT2.set(dealersScoreT2)
    player1ScoreT2 = functions_for_blackjack.scoreHand(player1HandT2)
    player2Score = functions_for_blackjack.scoreHand(player2Hand)
    if dealersScoreT2 > 21 or dealersScoreT2 < player1ScoreT2:
        resultVarT2.set("Player 1 Wins this round!!!")
    elif dealersScoreT2 > 21 or dealersScoreT2 < player2Score:
        resultVarT2.set("Player 2 Wins this round!!!")
    elif dealersScoreT2 > player1ScoreT2:
        resultVarT2.set("Dealer wins this round!!!")
    elif dealersScoreT2 > player2Score:
        resultVarT2.set("Dealer wins this round!!!")
    else:
        resultVarT2.set("DRAW DRAW!!! PLEASE RESTART ROUND!")


def dealPlayer1():
    """
    Activate the function to display cards in functions_for_blackjack.py
    :return:Cards for Player 1
    """
    player1Hand.append(functions_for_blackjack.dealCard(player1CardFrame, deck))
    player1Score = functions_for_blackjack.scoreHand(player1Hand)
    player1ScoreLabel.set(player1Score)
    if player1Score > 21:
        resultVar.set("Dealer wins! player 1(you) have busted")


def dealPlayer1T2():
    """Deal player 1 for Tab 2."""
    player1HandT2.append(functions_for_blackjack.dealCard(pC1F2, deck2))
    player1ScoreT2 = functions_for_blackjack.scoreHand(player1HandT2)
    player1ScoreLabelT2.set(player1ScoreT2)
    if player1ScoreT2 > 21:
        resultVarT2.set("Dealer wins! player 1(you) have busted")


def dealPlayer2():
    """
    Activate the function to display cards in functions_for_blackjack.py
    :return:Cards for Player 2
    """
    player2Hand.append(functions_for_blackjack.dealCard(player2CardFrame,
                                                        deck2))
    player2Score = functions_for_blackjack.scoreHand(player2Hand)
    player2ScoreLabel.set(player2Score)
    if player2Score > 21:
        resultVarT2.set("Dealer wins! player 2(you) have busted")


def initialDeal():
    """
    The initial dealing of cards when `newGame` or `play` is called.
    :return: None
    """
    dealPlayer1()
    dealPlayer1T2()
    dealPlayer2()
    dealerHand.append(functions_for_blackjack.dealCard(dealerCardFrame, deck))
    dealerHandT2.append(functions_for_blackjack.dealCard(dCF, deck2))
    dealersScoreLabel.set(functions_for_blackjack.scoreHand(dealerHand))
    dealersScoreLabelT2.set(functions_for_blackjack.scoreHand(dealerHandT2))
    dealPlayer1()
    player1ScoreLabel.set(functions_for_blackjack.scoreHand(player1Hand))
    player1ScoreLabelT2.set(functions_for_blackjack.scoreHand(player1HandT2))
    dealPlayer2()


def play():
    """
    Used to run this program from another program
    :return: None
    """
    global cards
    newGame()
    initialDeal()
    functions_for_blackjack.loadImages(cards, display)
    display.mainloop()


def exitter():
    """
    Corrupting the game by stopping functions or quitting player frames
    :return: None
    """
    import random
    destroyer = ["function", "quit", "frame"]
    if destroyer[random.randint(0, 2)] == "function":
        functions = [newGame, exitter, shuffle, dealDealer, dealPlayer2,
                     dealPlayer1, initialDeal, functions_for_blackjack]
        destroy_num = functions[random.randint(0, 7)]
        print(f"exiting function {str(destroy_num)}")
        quit(destroy_num)
    elif destroyer[random.randint(0, 2)] == "quit":
        print("Exited the program safely with display.quit()")
        display.quit()
    else:
        frames = [dealerCardFrame, player1CardFrame, player2CardFrame]
        destroy_this = frames[random.randint(0, 2)]
        print(f"exiting frame {str(destroy_this)}")
        destroy_this.destroy()


# The GUI
def main():
    global player1Hand
    global player1HandT2
    global player2Hand
    global cardFrame
    global cardFrame2
    global resultVarT2
    global resultVar
    global player1ScoreLabel
    global player1ScoreLabelT2
    global player2ScoreLabel
    global dealersScoreLabel
    global dealersScoreLabelT2
    global display
    global altMenu
    global player1CardFrame
    global player2CardFrame
    global dealerCardFrame
    global deck
    global deck2
    global pC1F2
    global dCF
    global dealerHand
    global dealerHandT2
    display = tkinter.Tk()
    display.title("Blackjack v2.0")
    display.geometry("1000x600")
    altMenu = tkinter.Menu(display)
    display.configure(menu=altMenu, background="grey")
    display.bind("<Control-q>", quit)
    display.bind("<Control-f>", fullscreen)
    display.bind("<Control-F>", exitFullScreen)
    display.bind("<Control-d>", darkTheme)
    display.bind("<Control-l>", lightTheme)
    fileMenu = tkinter.Menu(altMenu, tearoff=0)
    altMenu.add_cascade(label="File", menu=fileMenu)
    fileMenu.add_command(label="Light mode", command=lightTheme)
    fileMenu.add_command(label="Dark mode", command=darkTheme)
    fileMenu.add_separator()
    fileMenu.add_command(label="FullScreen", command=fullscreen)
    fileMenu.add_command(label="Exit FullScreen", command=exitFullScreen)
    fileMenu.add_separator()
    fileMenu.add_command(label="Safe quit", command=display.quit)
    optionsMenu = tkinter.Menu(altMenu, tearoff=0)
    altMenu.add_cascade(label="Options", menu=optionsMenu)
    optionsMenu.add_command(label="Reset Game", command=newGame)
    optionsMenu.add_command(label="Shuffle decks", command=shuffle)
    optionsMenu.add_separator()
    optionsMenu.add_command(label="Corrupt game", command=exitter)

    # Player's cards
    cards = []
    functions_for_blackjack.loadImages(cards, display)
    deck = list(cards)
    deck2 = list(cards)
    functions_for_blackjack.shuffler(deck, deck2)

    tabs = ttk.Notebook(display)
    tabs.grid(row=0, column=0)
    mainT1 = ttk.Frame(tabs)
    mainT1.grid(row=1, column=0)
    mainT2 = ttk.Frame(tabs)
    mainT2.grid(row=1, column=0)
    resultVar = tkinter.StringVar()
    resultVarT2 = tkinter.StringVar()
    result = ttk.Label(mainT1, textvariable=resultVar)
    result.grid(row=0, column=0, columnspan=4)
    result2 = ttk.Label(mainT2, textvariable=resultVarT2)
    result2.grid(row=0, column=0)
    cardFrame = ttk.Frame(mainT1, relief="flat",
                        borderwidth=2)
    cardFrame.grid(row=1, column=0, sticky="ew", columnspan=3, rowspan=3)
    cardFrame2 = ttk.Frame(mainT2, relief="flat",
                        borderwidth=2)
    cardFrame2.grid(row=1, column=0, sticky="ew", columnspan=3, rowspan=3)
    # Dealer's arrangement
    dealersScoreLabel = tkinter.IntVar()
    dealersScoreLabelT2 = tkinter.IntVar()
    ttk.Label(cardFrame, text="Dealer's Score-", style="TLabel"
            ).grid(row=0, column=0)
    ttk.Label(cardFrame, textvariable=dealersScoreLabel,
            style="TLabel").grid(row=1, column=0)
    ttk.Label(cardFrame2, text="Dealer's Score-", style="TLabel"
            ).grid(row=0, column=0)
    ttk.Label(cardFrame2, textvariable=dealersScoreLabelT2,
            style="TLabel").grid(row=1, column=0)

    dealerCardFrame = ttk.Frame(cardFrame, style="TFrame")
    dealerCardFrame.grid(row=0, column=1, sticky="ew", rowspan=2)
    dCF = ttk.Frame(cardFrame2, style="TFrame")
    dCF.grid(row=0, column=1, sticky="ew", rowspan=2)
    # PLayer 1's arrangement

    player1ScoreLabel = tkinter.IntVar()
    player1ScoreLabelT2 = tkinter.IntVar()
    a = ttk.Label(master=cardFrame, text="Player 1's Score-", style="TLabel"
            ).grid(row=2, column=0)
    b = ttk.Label(master=cardFrame, textvariable=player1ScoreLabel,
            style="TLabel").grid(row=3, column=0)
    c = ttk.Label(master=cardFrame2, text="Player 1's Score-", style="TLabel"
            ).grid(row=2, column=0)
    d = ttk.Label(master=cardFrame2, textvariable=player1ScoreLabelT2,
            style="TLabel").grid(row=3, column=0)

    player1CardFrame = ttk.Frame(cardFrame, style="TFrame")
    player1CardFrame.grid(row=2, column=1, sticky="ew", rowspan=2)
    pC1F2 = ttk.Frame(cardFrame2, style="TFrame")
    pC1F2.grid(row=2, column=1, sticky="ew", rowspan=2)

    # Player 2's arrangement
    player2ScoreLabel = tkinter.IntVar()
    ttk.Label(cardFrame2, text="Player 2's Score-", style="TLabel"
            ).grid(row=4, column=0)
    ttk.Label(cardFrame2, textvariable=player2ScoreLabel, style="TLabel"
            ).grid(row=5, column=0)
    player2CardFrame = ttk.Frame(cardFrame2, style="TFrame")
    player2CardFrame.grid(row=4, column=1, sticky="ew", rowspan=2)

    # Player Selection
    playerControlFrame = ttk.LabelFrame(mainT1, style="TFrame", text="Player "
                                                                    "Selection-")
    playerControlFrame.grid(row=7, column=0, columnspan=3, sticky="w")
    pCF2 = ttk.LabelFrame(mainT2, style="TFrame", text="Player Selection-")
    pCF2.grid(row=7, column=0, columnspan=3, sticky="w")

    dealer = ttk.Button(playerControlFrame, text="Dealer", style="TButton",
                        command=dealDealer)
    dealer.grid(row=1, column=0)
    dealerT2 = ttk.Button(pCF2, text="Dealer", style="TButton",
                        command=dealDealerT2)
    dealerT2.grid(row=1, column=0)
    player1 = ttk.Button(playerControlFrame, text="Player 1",
                        style="TButton", command=dealPlayer1)
    player1.grid(row=1, column=1)
    player1T2 = ttk.Button(pCF2, text="Player 1",
                        style="TButton", command=dealPlayer1T2)
    player1T2.grid(row=1, column=1)
    player2 = ttk.Button(pCF2, text="Player 2",
                        style="TButton", command=dealPlayer2)
    player2.grid(row=1, column=2)
    tabs.add(mainT1, text="Single Player")
    tabs.add(mainT2, text="Double player")
    # Hands for Dealers and Players
    dealerHand = []
    dealerHandT2 = []
    player1Hand = []
    player1HandT2 = []
    player2Hand = []
    initialDeal()
    display.mainloop()


if __name__ == "__main__":
    main()
