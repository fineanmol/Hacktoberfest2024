#!/bin/python3

import math
import os
import random
import re
import sys

#
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER n
#  2. INTEGER m
#

def solve(n, m):
    inv=lambda a,b,c,d:(b<2)*d or inv(b,a%b,d,c-a//b*d)
    p,q,C=1,1,10**9+7
    for i in range(m,n+m-1):
        p,q=p*i%C,q*(i-m+1)%C
    return p*inv(q,C,1,0)%C

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input().strip())

    for t_itr in range(t):
        first_multiple_input = input().rstrip().split()

        n = int(first_multiple_input[0])

        m = int(first_multiple_input[1])

        result = solve(n, m)

        fptr.write(str(result) + '\n')

    fptr.close()

