def anagrams(word1, word2):
    word1 = word1.replace(" ", "").lower()
    word2 = word2.replace(" ", "").lower()

    return sorted(word1) == sorted(word2)


word1 = "listen"
word2 = "silent"

if anagrams(word1, word2):
    print(f"'{word1}' and '{word2}' are Anagrams!")
else:
    print(f"'{word1}' and '{word2}' are not Anagrams!")