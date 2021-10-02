import random
while True:
    n=random.randint(0,100)
    i = 7
    g = 0
    print("\t\t\t\t ##### welcome to game of guessing the number #####\n")
    print("Rules are as follows:")
    print("1)Tere pass sirf 7 chances hai.\n2)Wo number 0 se 100 ke beech me hai.\nChal ab suru krte hai\n")
    while i >= 1:
        # print("\nTere dimag me konsa number atta hai. chal bata:")
        a = int(input("\nTere dimag me konsa number atta hai. chal bata:"))
        i = i - 1
        g = g + 1
        if a > n:
            print("\nBhot Aage ka Number socha hai,kaise game jeetga.number isse chota hai. fir se try kr.chances bache hai:", i)
            # speak("\nBhot Aage ka Number socha hai,kaise game jeetga.number isse chota hai. fir se try kr.")
            if i == 0:
                print("\nArre chances to katam hue.Chal tera game katam hua.Pheli fursat me nikal.get out!!!")
                break
            else:
                continue
        elif a == n:
            print("Chal beta tune wo number dhoond liye.bhot shana hai re tu.mubarak bhai")
            print("Tuze", g, "chances lage dhundane me.Agli bar kaam lagne chaiye samja kya")
            break

        else:
            # speak("\nBhot choti soch hai re teri,kaise game jeetga.kuch bada number soch.")
            print("\nBhot choti soch hai re teri,kaise game jeetga.kuch bada number soch.chances hai:", i)
            if i == 0:
                print("\n\t\t\tChal tera game katam hua.Pheli fursat me nikal.get out!!!")
                break
            else:
                continue

    b = input("\n\t Fir se khelna hai kya.Soch ke bata jaldi(ha/na):")
    if b == "na":
        print("\n\tTeri shakal fir se mat dhikana.patli gali se nikal.Dubara dhika to patak patak ke maruga")
        break
    else:
        continue
