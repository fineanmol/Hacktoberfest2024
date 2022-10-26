
row1 = ["⬜️","⬜️","⬜️"]
row2 = ["⬜️","⬜️","⬜️"]
row3 = ["⬜️","⬜️","⬜️"]
map = [row1, row2, row3]
print(f"{row1}\n{row2}\n{row3}")
position = input("Where do you want to put the treasure? ")


position=int(position)
if position==11:
    row1[0]="X"
elif position==12:
    row1[1]="X"
elif position==13:
    row1[2]="X"
elif position==21:
    row2[0]="X"
elif position==22:
    row2[1]="X"
elif position==23:
    row2[2]="X"
elif position==31:
    row3[0]="X"
elif position==32:
    row3[1]="X"
elif position==33:
    row3[2]="X"

print(f"{row1}\n{row2}\n{row3}")
