import random

# Define the player's initial attributes
player_health = 100
player_damage = 20
player_inventory = []

# Define a list of monsters
monsters = [
    {"name": "Goblin", "health": 30, "damage": 10},
    {"name": "Orc", "health": 50, "damage": 20},
    {"name": "Dragon", "health": 100, "damage": 30},
]

def battle(monster):
    while player_health > 0 and monster["health"] > 0:
        # Player's turn
        player_attack = random.randint(1, player_damage)
        monster["health"] -= player_attack
        print(f"You hit the {monster['name']} for {player_attack} damage.")
        
        if monster["health"] <= 0:
            print(f"You defeated the {monster['name']}!")
            break
        
        # Monster's turn
        monster_attack = random.randint(1, monster["damage"])
        player_health -= monster_attack
        print(f"The {monster['name']} hits you for {monster_attack} damage.")
        
        if player_health <= 0:
            print("You were defeated.")
            break

def main():
    print("Welcome to the Dungeon Explorer Game!")
    while player_health > 0:
        command = input("Do you want to (explore) the dungeon or (quit) the game? ").lower()
        if command == "quit":
            print("Thanks for playing!")
            break
        elif command == "explore":
            # Randomly select a monster to encounter
            monster = random.choice(monsters)
            print(f"You encounter a {monster['name']}!")
            battle(monster)
        else:
            print("Invalid command. Please enter 'explore' or 'quit'.")

if __name__ == "__main__":
    main()
