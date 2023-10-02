import numpy as np
import itertools as it

def main(name1,name2):
    st=[]
    for n in name1:
        if n in name2:
            pass 
        else:
            st.append(n)
    for n in name2:
        if n in name1:
            pass
        else:
            st.append(n)
    game = "FLAME"
    game_list = ["FRIENDS","LOVE","AFFECTION","MARRIAGE","ENEMY","SIBLINGS"]
    l1 = zip(game,game_list)
    l2 = np.arange(1,len(st)+1)
    for s,e in zip(l2,it.cycle(l1)):
        if len(st)==s:
            print(f"\nyou got the letter {e[0]} from {game}")
            print("You both are",e[1])

            
if __name__ == "__main__":
    name1  = input("Enter Your Name: ")
    name2 = input("Enter Name of Your partner: ")
    main(name1,name2)