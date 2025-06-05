import string, random

if __name__ == '__main__':
    s1 = string.ascii_lowercase
    s2 = string.ascii_uppercase
    s3 = string.digits
    s4 = string.punctuation

    while True:
        a = input("Enter password length\n") # handle gibberish(anything is entered except int)
        b = a.isdigit()
        if b==True:
            plen= int(a)
            break
        else:
            print("Invalid value! Please enter the valid value")

    s = []
    s.extend(list(s1))
    s.extend(list(s2))
    s.extend(list(s3))
    s.extend(list(s4))
    
    random.shuffle(s)

    print("".join(s[0:plen])) 
    # The string whose method is called is inserted in between each given string. 
    # The result is returned as a new string.
    # Example: '.'.join(['ab', 'pq', 'rs']) -> 'ab.pq.rs'
