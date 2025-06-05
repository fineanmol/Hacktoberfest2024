# Is Subsequence  Example 1:

# Input: s = "abc", t = "ahbgdc"
# Output: true
# Example 2:

# Input: s = "axc", t = "ahbgdc"
# Output: false


def isSubsequence(s, t):
    i, j = 0, 0

    while i < len(s) and j < len(t):
        if s[i] == t[j]:
            i += 1
        j += 1

    return i == len(s)

# Example usage:
s = "ace"
t = "abcde"
result = isSubsequence(s, t)

if result:
    print(f'"{s}" is a subsequence of "{t}".')
else:
    print(f'"{s}" is not a subsequence of "{t}".')

 
