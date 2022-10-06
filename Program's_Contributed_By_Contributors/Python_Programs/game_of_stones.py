import math
import os
import random
import re
import sys

# gameOfStones function.
def gameOfStones(n):
    if n==1:
        return 'Second'
    elif n>=2 and n<7:
        return 'First'
    elif n>=7:
        if n%7<2:
            return 'Second'
        else: return 'First'
        

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        n = int(input())

        result = gameOfStones(n)

        fptr.write(result + '\n')

    fptr.close()
