#!/bin/python3

import math
import os
import random
import re
import sys

first_multiple_input = input().rstrip().split()

n = int(first_multiple_input[0])
#print("n is: " + str(n))
m = int(first_multiple_input[1])
#print("m is " + str(m))
matrix = []

for _ in range(n):
    matrix_item = input()
    #print("matrix_item is: " + str(matrix_item))
    matrix.append(matrix_item)
    #print("matrix now is: " + str(matrix))

x = []

for i in range(m):
    for j in range(n):

        x.append(matrix[j][i])

txt = ''.join(x)

print(re.sub(r"\b[\W]+\b", " ", txt))
