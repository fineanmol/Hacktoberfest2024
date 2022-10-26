# create a dictionary of the alphabets according to their corresponding numbers
alpha_dict = {
    "a": 0,
    "b": 1,
    "c": 2,
    "d": 3,
    "e": 4,
    "f": 5,
    "g": 6,
    "h": 7,
    "i": 8,
    "j": 9,
    "k": 10,
    "l": 11,
    "m": 12,
    "n": 13,
    "o": 14,
    "p": 15,
    "q": 16,
    "r": 17,
    "s": 18,
    "t": 19,
    "u": 20,
    "v": 21,
    "w": 22,
    "x": 23,
    "y": 24,
    "z": 25,
}

try:
    # Input the key text
    key = input("Enter key text: ").lower()

    # Input the plain text
    plain_text = input("Enter plain text: ").lower()
    
    # key length check
    if len(key) > len(plain_text):
        raise Exception("Key length is greater than plain text length")

    # Initialise the cipher text
    cipher_text = ""

    # Convert the plain text to cipher text
    for i in range(len(plain_text)):
        if plain_text[i].isalpha():
            cipher_text += chr(
                ((alpha_dict.get(plain_text[i]) + alpha_dict.get(key[i % len(key)])) % 26) + 97)
        else:
            cipher_text += plain_text[i]

    # Print the cipher text
    print("Cipher text: ", cipher_text)

except:
    print("Please enter a valid key text, length smaller than that of plain text!!")
