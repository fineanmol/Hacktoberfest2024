from time import time

print("\nType the sentence given below")
s = "The Quick Brown Fox Jumps over the lazy dog."

words = (len(s.split()))

print()
print(s)

print("\nAfter you are done press enter to know your time and speed")
input("Press any key to Start:")

while True:
    print("\nTimer Started\n")
    start = time()
    t = input()
    end = time()
    if t == s:
        total = round(end - start, 2)
        print("\nHurray you typed that correctly")
        print("Your time was %s seconds" % total)
        total = int(total) / 60
        print("Speed was %s WPM" % (str(words // total)))
        break

    else:
        print("\nWrongly entered -  Enter the sentence as it is shown\n")
        user_input = input("Press Enter to Play Again\n")
        print("\nType the sentence given below")
        print(s,"\n")
        input("Press any key to Start:")