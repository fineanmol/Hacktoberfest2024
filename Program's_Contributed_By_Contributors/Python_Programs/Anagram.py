"""An Anagram is a word or phrase formed by rearranging the
letters of a different word or phrase,
typically using all the original letters exactly once.
"""
s=input("Input the first word")
t=input("Input the second word")
if len(s)==len(t):
    p=list(s)
    g=list(t)
    k=sorted(p)
    m=sorted(g)
    if k==m:
        print("Yes, the words are Anagram")
    else:
        print("No, The words are not Anagram")
else:
    print("No, The words are not Anagram")
