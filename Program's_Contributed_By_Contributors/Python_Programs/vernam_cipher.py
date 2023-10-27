"""
Author: Ninja-06
Date: 27-10-2023
Description: This scripts performs encryption and decryption using vernam cipher.

"""

import getpass

class vernamCipher:
    
    def __init__(self):

        print("init...")
        self.plain_text = input("Enter Plaintext").upper().strip()
        self.key = getpass.getpass("Enter Key").upper().strip()
        self.cipher_text = ""

    def encrypt(self):

        print(">>Encrypting your text...\n")
    
        """
        check if plaintext and key size is same and if not adds / removes additional characters to/from key
        till it matches plain text size.

        """
        if len(self.plain_text) != len(self.key):
            self.key = "".join([(self.key[i % len(self.key)]) for i in range(len(self.plain_text))])
            
        print("key: {}".format(self.key))

        # iterate through the plain text and key  and encrypts the text
        index = 0
        for p_character in self.plain_text:
            if p_character == "":
                self.cipher_text += ""
            else:
                cipher_char_ord = (ord(p_character)%65) + (ord(self.key[index])%65)
                if cipher_char_ord > 26:
                    cipher_char_ord = cipher_char_ord - 26

                self.cipher_text += chr(cipher_char_ord + 65)
            index += 1 
        print("Your cipher text is {}\n".format(self.cipher_text))   
        return self.cipher_text

    def decrypt(self, cipher_text):
    
        print(">>decrypting your cipher text...\n")
        plain_text = ""

        # loop iterates through cipher text and key and decrypts the cipher text.
        index = 0
        for c_character in cipher_text:
            if c_character == "":
                plain_text += ""
            else:
                plain_char_ord = (ord(c_character)%65) - (ord(self.key[index])%65)
                if plain_char_ord < 0:
                    plain_char_ord = plain_char_ord + 26

                plain_text += chr(plain_char_ord + 65)
            index += 1  
        print("your plain text is {}\n".format(plain_text))

if __name__ == '__main__':
    v = vernamCipher()
    cipher_text = v.encrypt()
    v.decrypt(cipher_text)
