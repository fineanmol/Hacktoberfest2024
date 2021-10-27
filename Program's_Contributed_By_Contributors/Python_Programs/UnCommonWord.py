# Given two sentences A and B return a list of all uncommon words.
# A word is uncommon if it appears EXACTLY ONCE in one of the sentences, 
# and DOES NOT appear in the other sentence.

# Each sentence is a string of space separated words.  
# Each word consists only of lowercase letters.
# Order in the final array is not important.

# Example:
# Input: A = "orange orange", B = "apple"
# Output: ["apple"]

A = 'you used to love basketball but then you quit '
B = 'we used to enjoy basketball but then we quit'

def solution(A, B):
    import collections
    
    a_split, b_split = A.split(), B.split()
    uncommon_words = set(a_split)^set(b_split) #or set(a_split).symmetric_difference(b_split)
    
    a_counter,b_counter = collections.Counter(a_split), collections.Counter(b_split)
    return [x for x in uncommon_words if x in a_counter and a_counter[x] == 1 or b_counter[x] == 1]

solution(A, B)