def rabin_karp(pattern, text_string, prime_number): 
    M = len(pattern) 
    N = len(text_string) 
    i = 0
    j = 0
    d = 256
    pattern_hash = 0    # initial hash value for pattern 
    text_hash = 0    # initial hash value for txt 
    h = 1

    # The value of h would be "pow(d, M-1)% prime_number" 
    for i in range(M-1): 
        h = (h * d) % prime_number

    # Calculate the hash value of pattern and window
    for i in range(M): 
        pattern_hash = (d * pattern_hash+ ord(pattern[i]))% prime_number
        text_hash = (d * text_hash+ ord(text_string[i]))% prime_number

    # Slide the pattern over text one by one 
    for i in range(N - M + 1): 
        if pattern_hash == text_hash: 
            # Check for characters one by one 
            for j in range(M): 
                if text_string[i + j] != pattern[j]: 
                    break

            j += 1

            if j == M: 
                print("Pattern found at index ", str(i))

        # Calculate hash value for next window of text
        if i < N-M: 
            text_hash = (d * (text_hash - ord(text_string[i]) * h) + ord(text_string[i + M])) % prime_number

            # Making the value positive
            if text_hash < 0: 
                text_hash += prime_number

#Driver Program
if __name__ == "__main__":
    text_string = input("Enter text- ")
    pattern = input("Enter pattern to be found- ")
    prime_number= 11  #A prime number 
    rabin_karp(pattern, text_string, prime_number)
