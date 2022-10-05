# Python program to print all
# the possible combinations

def comb(L):

    for i in range(3):
        for j in range(3):
                # check if the indexes are not
                # same
                if (i!=j and j!=i):
                    print(L[i], L[j],)

# Driver Code
comb([2, 2, 3])
# Make a pair of two numbers using these three number
