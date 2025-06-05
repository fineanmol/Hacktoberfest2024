import random
import string

def create_encryption_key(string1):
    chars=list(set(list(string1)))
    keydict={}
    taken = []
    for each in chars:
        while(1):
            r=random.choice(chars)
            if(r not in taken):
                keydict[each]=r
                taken.append(r)
                break
    return(keydict)
def reverse(d):
    d1={}
    for each in d:
        d1[d[each]]= each
    return d1

def encrypt(letter,key):
    l=[]
    for i in range(0,len(letter)):
        l.append(key[letter[i]])
    return l


plain_text=input("enter the string you want to encrypt  =  ")
print('plain text = ', plain_text)

#encrypt
key=create_encryption_key(plain_text)
cipher_list=encrypt(plain_text,key)
cipher_text=(''.join(cipher_list))
print("cipher text =", cipher_text)

#decrypt
plain_list=encrypt(cipher_list,reverse(key))
plain_text=(''.join(plain_list))
print('plain text =', plain_text)
