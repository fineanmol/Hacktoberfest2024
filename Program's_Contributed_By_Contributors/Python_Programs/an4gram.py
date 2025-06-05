#anagram is where both the strings have each characters of the same frequency
#danger and garden is an example of an anagram

def isanagram(s1,s2):
    if(len(s1)!=len(s2)):
        return False

    # return sorted(s1) == sorted(s2)
    freq1 = {} #declaring dictionaries for mapping purpose
    freq2 = {}

    #using dictionary(hash table) for  assigning the character as key and no of times it repeated as values
    # {
    #     char1:value1
    # }
    for char in s1:
        if char in freq1:
            freq1[char] += 1
        else:
            freq1[char] = 1

    for char in s2:
        if char in freq2:
            freq2[char] += 1
        else:
            freq2[char] = 1

    # for every key in dictionary freq1 we are comparing it with the key in dictionary freq2
    # if the key is not found then it will return false 
    # and simillarly the values from both the dictionaries are being compared 
    # if any one of the condition is false it will return false "or" is being used 
    for key in freq1:
        if key not in freq2 or freq1[key]!=freq2[key]:
            return False
    return True



s1 = input("Enter a string\n")
s2 = input("Enter second string\n")

if isanagram(s1,s2):
    print(f"\nThe {s1} and {s2} are Anagrams")
else:
    print(f"{s1} and {s2} are not anagram")