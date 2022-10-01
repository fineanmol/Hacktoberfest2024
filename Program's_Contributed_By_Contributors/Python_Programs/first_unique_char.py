# https://leetcode.com/problems/first-unique-character-in-a-string/

def indexOf(s: str, input: str) -> int:
    for idx, ch in enumerate(input):
        if ch == s:
            return idx
    return -1

def firstuniqueChar(s: str) -> int:
    for unique in dict.fromkeys(s).keys():
        if s.count(unique) == 1:
            return indexOf(unique, s)
    return -1

data = input("Enter a string: ")

print("The first unique character is", data[firstuniqueChar(data)])
