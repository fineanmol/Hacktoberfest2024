
map = [
    ["⬜️", "⬜️", "⬜️"],
    ["⬜️", "⬜️", "⬜️"],
    ["⬜️", "⬜️", "⬜️"]
]

for row in map:
    print(row)

position = input("Where do you want to put the treasure? ")

row_idx = int(position[0]) - 1
col_idx = int(position[1]) - 1

map[row_idx][col_idx] = "X"

for row in map:
    print(row)

