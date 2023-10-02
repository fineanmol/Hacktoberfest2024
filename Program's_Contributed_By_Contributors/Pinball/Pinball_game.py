
'''
    
    This code generates a random pinball
    gameboard, and you don't have to input
    anything.
    
    But if you want, input the first int,
    which decides the amount of balls.
    
    And then if you keep giving inputs,
    they will be the strength you shoot
    each balls. If you give no inputs,
    the strength will be random.
    
    Up to now, the size of the gameboard
    is 10 holes with height 15. Maybe I'll
    make it resizeable when I have time.
    
    
    Update: Sizes are changeable now!
    
'''

height = 20
holes = 17
density = 5 # 0 for densest pins

balls = int(input("Amount of balls:") or 200000) # decide balls here



from random import randint as ri

scores = list(p*int(p**.5/2)+p for p in range(holes//2, 0, -1)) + list(p*int(p**.5/2)+p+1 for p in range(1, (holes+1)//2+1))

gameboard = list(list(bool(ri(0, density)) for p in range(holes*2-1)) for p in range(height))


def put(place:"0 ~ holes/2-1"):
    for p in gameboard:
        if not p[place]:
            if place is 0:
                place = 1
            elif place is holes*2-2:
                place = holes*2-3
            else:
                place += [-1,1][ri(0,1)]
    else:
        if place%2:
            place += [-1,1][ri(0,1)]
    return place//2





def input(msg=""):
    if msg:
        print(msg, end=" ")
    import sys
    s = sys.stdin.readline()[:-1]
    if s:
        print(s)
    elif msg:
        print()
    return s




from time import time

score = 0
inholes = [0]*holes


t = time()

for p in range(balls):
    b = input() or ri(0,20*(holes-2))
    
    hole = put(abs(int(b)%(holes*4-4)-holes*2+2))
    score += scores[hole]
    inholes[hole] += 1
    if time()-t>4:
        print("Time's up!")
        break

balls = sum(inholes)

std = balls/holes/4


print("Score:", score, "Balls:", balls, "Average:", f"{score/balls:.2f}")
print(" "*2+"-"*(holes*2-1)+" ")
[print(" "*(1-p) + "/" + " "*((holes*2-1)+2*p) + "\\") for p in range(2)]
[print("|" + "".join(". "[d] for d in p) + "| |") for p in gameboard]
[print(p[0].join(["|"]*(holes+1))+p[1]+"|") for p in ("  ", "'o")]
[print("|" + "|".join(" -="[0+(p>std*(k-1))+(p>std*k)] for p in inholes) + "|T|") for k in range(8,0,-2)]

print("", *(p%10 for p in inholes), "(I)")
print("", *(p//10%10 or " 0"[p>99] for p in inholes), "(X)")
print("", *(p//100%10 or " 0"[p>999] for p in inholes), "(C)")
print("", *(p//1000%10 or " 0"[p>9999] for p in inholes), "(M)")
print("", *(p>9999 and p>99999 and chr(p//10000%26+55) or p//10000 or " " for p in inholes), "(+)")
print("*".join(" "*(holes+1)))
print(*(f"{p%100:>2}" for p in scores), " pts.", sep="")


