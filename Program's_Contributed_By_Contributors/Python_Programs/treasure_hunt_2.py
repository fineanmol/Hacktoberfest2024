
import random

def map_to_string(map):
    to_string = ""

    for line in map:
        new_line = ""
        for element in line:
            new_line += " "+  element 
        to_string += new_line + "\n"


    return to_string

map = []

"□"
for i in range(10):
    map.append(["■","■","■","■","■","■","■","■","■","■"])

visible_map = []
for i in range(10):
    visible_map.append(["■","■","■","■","■","■","■","■","■","■"])


map[random.randint(0,9)][random.randint(0,9)] = "B"
map[random.randint(0,9)][random.randint(0,9)] = "B"
map[random.randint(0,9)][random.randint(0,9)] = "T"



print("\n Here's the field, avoid (B)ombs and try to find the (T)reasure\n")
print(map_to_string(map))
print(map_to_string(visible_map))


print(" You can try it 10 times\n")

won = False
dead = False

for i in range(10):
    coordinates = input(" Enter the coordinates (ex: 0 1): ").split(" ")

    element = map[int(coordinates[0])][int(coordinates[1])]

    if (element == "■"):
        print("\n Well, there's nothing here\n")
        visible_map[int(coordinates[0])][int(coordinates[1])] = "□"
        print(map_to_string(visible_map))
    if (element == "B"):
        print("\n BOOOOOM, game over!\n")
        visible_map[int(coordinates[0])][int(coordinates[1])] = "B"
        print(map_to_string(visible_map))
        dead= True
        break
    if (element == "T"):
        print("\n CONGRATULATIONS, now you're rich\n")
        visible_map[int(coordinates[0])][int(coordinates[1])] = "T"
        print(map_to_string(visible_map))
        won = True

        break

if (not(won) and not(dead)):
     print(" You still poor, but at least you didn't die")

    # print(" The element in your coordinates is: %s" % (map[int(coordinates[0])][int(coordinates[1])]))

