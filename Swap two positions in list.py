def swapPos(list, pos1, pos2):
     
    list[pos1], list[pos2] = list[pos2], list[pos1]
    return list
 
list = [10, 45, 29, 9, 25]
pos1, pos2  = 2, 4
 
print(swapPos(list, pos1-1, pos2-1))