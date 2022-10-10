#caesar cipher encryption | Twitter @C15C01337
# new added
message = input('Enter a message: ')
key = int(input('Enter a key: '))
def encrypt_char(char, key):
    return chr(ord('A') + (ord(char) - ord('A') + key) % 26)

def encrypt_message(message, key):
    message = message.upper()
    cipher = ''
    for char in message:
        if char not in ' ,.':
            cipher += encrypt_char(char, key)
        else:
            cipher += char
    print(cipher)
    return cipher
encrypt_message(message, key)
