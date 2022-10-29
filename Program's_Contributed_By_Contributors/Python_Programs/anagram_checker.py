# Check if two words are anagrams 
# An anagram is a woed or phrase that is created by rearranging the letters of another word or phrase.
# Example:
# find_anagrams("hello", "check") -> False
# find_anagrams("below", "elbow") -> True


def find_anagram(word, anagram):

    sort_first = (sorted(word))
    sort_second = (sorted(anagram))

    
    if(sort_first == sort_second):
        print(word, "and", anagram, "are anagrams")
        return True
    else:
        print(word, "and", anagram, "are not anagrams")
        return False

    

word = input("Enter first word: ")
anagram = input("Enter second word: ")

find_anagram(word, anagram)