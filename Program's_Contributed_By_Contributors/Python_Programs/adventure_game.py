import time
import random


def print_pause(line):
    print(line)
    time.sleep(3)


def intro(enemy_creature):
    print_pause("You find yourself standing in an open field, filled with"
                " grass and yellow wildflowers.")
    print_pause("Rumor has it that a " + enemy_creature + " is somewhere "
                "around here, and has been terrifying the nearby village.")
    print_pause("In front of you is a house.")
    print_pause("To your right is a dark cave.")
    print_pause("In your hand you hold your trusty"
                " (but not very effective) dagger.")


def field(items, enemy_creature):
    print_pause("Enter 1 to knock on the door of the house.")
    print_pause("Enter 2 to peer into the cave.")
    print_pause("What would you like to do?")
    choice = input("(Please enter 1 or 2).\n")
    valid_input(choice, '1', '2', 'movement', items, enemy_creature)


def valid_input(choice, option1, option2, action, items, enemy_creature):
    if action == 'movement':
        if choice == option1:
            house(items, enemy_creature)
        elif choice == option2:
            cave(items, enemy_creature)
        else:
            choice = input("(Please enter 1 or 2).\n")
            valid_input(choice, 1, 2, 'movement', items, enemy_creature)
    elif action == 'attack':
        if choice == option1:
            fight(items, enemy_creature)
        elif choice == option2:
            run_away(items, enemy_creature)
        else:
            choice = input("Would you like to (1) fight or (2) run away?\n")
            valid_input(choice, 1, 2, 'attack', items, enemy_creature)
    elif action == 'playagain':
        if choice == option1:
            play_game()
        elif choice == option2:
            print_pause("Thanks for playing! See you next time.")
        else:
            choice = input("Would you like to play again? (y/n)\n")
            valid_input(choice, 'y', 'n', 'playagain', items, enemy_creature)


def house(items, enemy_creature):
    if 'sword' in items:
        print_pause("You approach the door of the house.")
        print_pause("You are about to knock when the door opens and "
                    "out steps a " + enemy_creature + ".")
        print_pause("Eep! This is the " + enemy_creature + "'s house!")
        print_pause("The " + enemy_creature + " attacks you!")
        choice = input("Would you like to (1) fight or (2) run away?\n")
        valid_input(choice, '1', '2', "attack", items, enemy_creature)
    else:
        print_pause("You approach the door of the house.")
        print_pause("You are about to knock when the door opens and out "
                    "steps a " + enemy_creature + ".")
        print_pause("Eep! This is the " + enemy_creature + "'s house!")
        print_pause("The " + enemy_creature + " attacks you!")
        print_pause("You feel a bit under-prepared for this, what with "
                    "only having a tiny dagger.")
        choice = input("Would you like to (1) fight or (2) run away?\n")
        valid_input(choice, '1', '2', "attack", items, enemy_creature)


def fight(items, enemy_creature):
    if 'sword' in items:
        print_pause("As the " + enemy_creature + " moves to attack, "
                    "you unsheath your new sword.")
        print_pause("The Sword of Ogoroth shines brightly in your hand as"
                    " you brace yourself for the attack.")
        print_pause("But the " + enemy_creature + " takes one look at your "
                    "shiny new toy and runs away!")
        print_pause("You have rid the town of the " + enemy_creature + ". "
                    "You are victorious!")
        choice = input("Would you like to play again? (y/n)\n")
        valid_input(choice, 'y', 'n', 'playagain', items, enemy_creature)
    else:
        print_pause("You do your best...")
        print_pause("but your dagger is no match for the "+enemy_creature+".")
        print_pause("You have been defeated!")
        choice = input("Would you like to play again? (y/n)\n")
        valid_input(choice, 'y', 'n', 'playagain', items, enemy_creature)


def run_away(items, enemy_creature):
    print_pause("You run back into the field. Luckily, you don't seem to"
                " have been followed.\n")
    field(items, enemy_creature)


def cave(items, enemy_creature):
    if 'sword' in items:
        print_pause("You peer cautiously into the cave.")
        print_pause("You've been here before, and gotten all the good "
                    "stuff. It's just an empty cave now.")
        print_pause("You walk back out to the field.\n")
        field(items, enemy_creature)
    else:
        print_pause("You peer cautiously into the cave.")
        print_pause("It turns out to be only a very small cave.")
        print_pause("Your eye catches a glint of metal behind a rock.")
        print_pause("You have found the magical Sword of Ogoroth!")
        print_pause("You discard your silly old dagger and take the sword"
                    " with you.")
        print_pause("You walk back out to the field.\n")
        items.append("sword")
        field(items, enemy_creature)

def play_game():
    items = []
    enemy_creature_list = ['pirate', 'wicked fairy', 'alien', 'dragon']
    enemy_creature = random.choice(enemy_creature_list)
    intro(enemy_creature)
    field(items, enemy_creature)

play_game()
