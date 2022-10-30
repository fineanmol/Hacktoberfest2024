# Solution for HackerRank problem with URL: https://www.hackerrank.com/challenges/ctci-making-anagrams/problem
from collections import *    
a = Counter(raw_input())
b = Counter(raw_input())
c = a - b
d = b - a
e = c + d
print len(list(e.elements()))
