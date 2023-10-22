def decrypt(ciphertext, shift):
    de_txt = ""
    
    for char in ciphertext:
        if char.isalpha():
            is_upper = char.isupper()
            char = char.lower()
            de_char = chr(((ord(char) - ord('a') - shift) % 26) + ord('a'))
            if is_upper:
                de_char = de_char.upper()
            de_txt += de_char
        else:
            de_txt += char
    
    return de_txt


def break_cipher(ciphertext):
    for shift in range(26):
        de_txt = decrypt(ciphertext, shift)
        print(f"Shift {shift}: {de_txt}")

if __name__ == "__main__":
    ciphertext = input("Enter encrypted text: ")
    break_cipher(ciphertext)
