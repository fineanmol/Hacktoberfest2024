# -*- coding: utf-8 -*-
"""
Created on Thu Sep 29 10:48:27 2022

@author: HP
"""

str1=input("Enter the first string")
str2=input("Enter the second string")
print(sorted(str1))
print(sorted(str2))
if (sorted(str1)==sorted(str2)):
     print("These are anagrams")
else:
    print("These are not Anagrams")
     