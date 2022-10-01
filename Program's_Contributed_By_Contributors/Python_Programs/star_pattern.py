r = int(input("Number of rows: "))
for i in range(0, r):
    for j in range(0, i + 1):
        print("*", end = ' ')
    print("")