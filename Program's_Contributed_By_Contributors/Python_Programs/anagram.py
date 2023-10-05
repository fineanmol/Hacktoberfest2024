def find_anagrams(word):
    anagrams = []
    generate_anagrams(list(word), 0, anagrams)
    return anagrams

def generate_anagrams(word_chars, current_index, anagrams):
    if current_index == len(word_chars) - 1:
        anagrams.append(''.join(word_chars))
    else:
        for i in range(current_index, len(word_chars)):
            # Swap the current character with character at position 'i'
            word_chars[current_index], word_chars[i] = word_chars[i], word_chars[current_index]

            # Recursively generate anagrams for the remaining characters
            generate_anagrams(word_chars, current_index + 1, anagrams)

            # Swap back to the original arrangement for the next iteration
            word_chars[current_index], word_chars[i] = word_chars[i], word_chars[current_index]

if __name__ == "__main__":
    input_word = "listen"  # Sample test case
    anagrams = find_anagrams(input_word)

    print(f"Anagrams of '{input_word}':")
    for anagram in anagrams:
        print(anagram)
