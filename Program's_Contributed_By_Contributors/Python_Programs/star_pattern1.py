
def pattern(n):
     
    # outer loop to handle number of rows
    # n in this case
    for i in range(n):
     
        # inner loop to handle number of columns
        # values changing acc. to outer loop
        for _ in range(i+1):
            print("* ",end="")

        # ending line after each row
        print("\r")

n = 5
pattern(n)