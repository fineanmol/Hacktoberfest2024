# Python Implementation Of Rabin-Karp Algoritmn
# https://www.github.com/JehanPatel

# What is Rabin-Karp Algoritm?  
#The Rabin-Karp algorithm is a string searching algorithm that uses hashing to find any one of a set of pattern strings in a text. It is particularly useful for searching for a pattern in a large piece of text. The algorithm works by calculating a hash value for each pattern and for each substring of the text of the same length as the pattern. It then compares the hash values to determine if the substring matches the pattern.

# Code For Rabin-Karp Algoritm:

def search(pattern, text):
    n = len(text)
    m = len(pattern)
    pattern_hash = hash(pattern)
    text_hash = hash(text[:m])

    for i in range(n - m + 1):
        if pattern_hash == text_hash:
            if text[i:i+m] == pattern:
                return i
        if i < n - m:
            text_hash = hash(text[i+1:i+m+1])

    return -1

# Time Complexity = O(n+m)