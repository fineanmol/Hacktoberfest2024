'''
https://www.hackerrank.com/challenges/sherlock-and-squares/problem

'''

import os
import random
import re
import sys

# Complete the squares function below.
def squares(a, b):
    sqrta = math.ceil(math.sqrt(a))
    sqrtb = math.floor(math.sqrt(b))
    return(sqrtb - sqrta + 1)
    
    
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input())

    for q_itr in range(q):
        ab = input().split()

        a = int(ab[0])

        b = int(ab[1])

        result = squares(a, b)

        fptr.write(str(result) + '\n')

    fptr.close()



